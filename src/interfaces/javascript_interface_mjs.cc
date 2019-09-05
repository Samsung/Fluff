#include <string>
#include "mjs/mjs.h"
#include <cstdio>
#include <cstring>

#include "javascript_interface.h"

using std::string;
using std::unique_ptr;
using std::vector;

static struct mjs *mjs;

void JavascriptInterface::Init(const char* exeuction_path) {
    mjs = mjs_create();
}

void JavascriptInterface::Execute(
    const vector<unique_ptr<Instruction>>& instructions) {
  string code;
  for (const auto& instr : instructions) {
    code += instr->Emit() + ";\n";
  }
  mjs_exec(mjs, code.c_str(), NULL);
}
