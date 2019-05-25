<<<<<<< HEAD
#include "javascript_interface.h"
#include "jerry-core/include/jerryscript.h"
=======
#include "fuzz_target.h"
#if FUZZ_JERRY == 1
#include "javascript_interface.h"
#include "jerryscript.h"
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""

using std::unique_ptr;
using std::vector;

<<<<<<< HEAD
void JavascriptInterface::Init(const char* execution_path) {
  jerry_init(JERRY_INIT_EMPTY);
}
=======
void JavascriptInterface::Init() { jerry_init(JERRY_INIT_EMPTY); }
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""

void JavascriptInterface::Execute(
    const vector<unique_ptr<Instruction>>& instructions) {
  jerry_value_t eval_ret;
  for (const auto& instr : instructions) {
    auto code = instr->Emit();
    if (jerry_is_valid_utf8_string((const jerry_char_t*)code.c_str(),
                                   code.length())) {
      eval_ret =
          jerry_eval((const jerry_char_t*)code.c_str(), code.length(), false);
      jerry_release_value(eval_ret);
    }
  }
  jerry_cleanup();
}
<<<<<<< HEAD
=======

#endif  // if FUZZ_JERRY == 1
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""
