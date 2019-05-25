#include "javascript_interface.h"
#include "jerry-core/include/jerryscript.h"

using std::unique_ptr;
using std::vector;

void JavascriptInterface::Init(const char* execution_path) {
  jerry_init(JERRY_INIT_EMPTY);
}

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
