<<<<<<< HEAD
=======
#include "fuzz_target.h"
#if DRY_RUN == 1
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""
#include "javascript_interface.h"

#include <iostream>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

<<<<<<< HEAD
void JavascriptInterface::Init(const char *execution_path) {}
=======
void JavascriptInterface::Init() {}
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""

void JavascriptInterface::Execute(
    const vector<unique_ptr<Instruction>> &instructions) {
  for (const auto &instr : instructions) {
    cout << instr->Emit() << endl;
  }
}
<<<<<<< HEAD
=======

#endif  // if DRY_RUN == 1
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""
