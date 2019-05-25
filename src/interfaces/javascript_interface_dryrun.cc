#include "fuzz_target.h"
#if DRY_RUN == 1
#include "javascript_interface.h"

#include <iostream>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

void JavascriptInterface::Init() {}

void JavascriptInterface::Execute(
    const vector<unique_ptr<Instruction>> &instructions) {
  for (const auto &instr : instructions) {
    cout << instr->Emit() << endl;
  }
}

#endif  // if DRY_RUN == 1
