#include "fuzz_target.h"
#if FUZZ_ESPURINO == 1
#include "javascript_interface.h"

#include <string>

extern "C" {
#include "main.h"
}

using std::string;
using std::unique_ptr;
using std::vector;

<<<<<<< HEAD
void JavascriptInterface::Init(const char* execution_path) {}
=======
void JavascriptInterface::Init() {}
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""

void JavascriptInterface::Execute(
    const vector<unique_ptr<Instruction>>& instructions) {
  string code;
  for (const auto& instruction : instructions) {
    code += instruction->Emit() + ";\n";
  }
  smain(&code[0]);
}

#endif  // if FUZZ_ESPRUINO == 1
