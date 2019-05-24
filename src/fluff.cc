#include <climits>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "yaml-cpp/yaml.h"

#include "interfaces/builtins.h"
#include "interfaces/fuzz_target.h"
#include "interfaces/javascript_interface.h"
#include "statements/instruction.h"
#include "utils/identifier_register.h"
#include "utils/parser.h"
#include "utils/reader.h"
#include "utils/reader_file.h"
#include "utils/status.h"

constexpr size_t kMaxFileSize = 2048;

using std::cerr;
using std::endl;
using std::string;
using std::unique_ptr;
using std::vector;

int main(int argc, char **argv) {
  if (argc != 3 && argc != 4) {
    cerr << "Usage: " << argv[0] << " <input_file> <yaml_grammar> <purity byte"
         << " threshold [0; 1] (optional)>." << endl
         << "To fuzz a specific target compile with -Dfuzz_target, e.x. to "
         << "fuzz JerryScript, compile with -DFUZZ_JERRY. If no such value is "
         << "specified, a dry run version will be compiled." << endl;
    return -1;
  }
  double purity_byte_threshold = (argc == 4) ? std::stod(string(argv[3])) : 0.5;
  if (purity_byte_threshold > 1 || purity_byte_threshold < 0) {
    cerr << "Purity byte threshold must be between 0 and 1." << endl;
    return -1;
  }
  purity_byte_threshold *= CHAR_MAX;
  ReaderFile reader;
  YAML::Node grammar;
  auto status = reader.ReadYamlGrammar(argv[2], &grammar);
  if (!status.Ok()) {
    cerr << status.Message() << endl;
    return -1;
  }
  IdentifierRegister identifier_register;
  for (const auto &function : builtins::functions) {
    identifier_register.RegisterVariable(function);
    identifier_register.RegisterFunction(function);
  }
  for (const auto &method : builtins::methods) {
    identifier_register.RegisterMethod(method);
  }
  for (const auto &variable : builtins::variables) {
    identifier_register.RegisterVariable(variable);
  }
  JavascriptInterface js_interface;
  js_interface.Init();
#ifdef __AFL_HAVE_MANUAL_CONTROL
  __AFL_INIT();
#endif  // ifdef __AFL_HAVE_MANUAL_CONTROL
  reader.SetFileName(argv[1]);
  vector<unique_ptr<Instruction>> instructions;
  Parser parser(grammar);
  char purity_byte;
  status = reader.GetChar(&purity_byte);
  if (!status.Ok()) {
    cerr << status.Message() << endl;
    return -1;
  }
  if (purity_byte > purity_byte_threshold) {
    parser.SetPureRun();
  }
  try {
    while (parser.GetInstruction(reader, &instructions, &identifier_register)
               .Ok()) {
    }
    js_interface.Execute(instructions);
  } catch (const std::exception &ex) {
    cerr << "Exception was thrown while parsing instructions." << ex.what()
         << endl;
    return -1;
  }
  return 0;
}
