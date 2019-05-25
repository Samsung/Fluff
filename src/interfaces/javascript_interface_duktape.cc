<<<<<<< HEAD
=======
#include "fuzz_target.h"
#if FUZZ_DUKTAPE == 1
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""
#include "duktape.h"
#include "javascript_interface.h"

using std::unique_ptr;
using std::vector;

static duk_context* ctx;

<<<<<<< HEAD
void JavascriptInterface::Init(const char* execution_path) {
  ctx = duk_create_heap_default();
}
=======
void JavascriptInterface::Init() { ctx = duk_create_heap_default(); }
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""

void JavascriptInterface::Execute(
    const vector<unique_ptr<Instruction>>& instructions) {
  for (const auto& instruction : instructions) {
    duk_peval_string(ctx, instruction->Emit().c_str());
  }
  duk_destroy_heap(ctx);
}
<<<<<<< HEAD
=======

#endif  // if FUZZ_DUKTAPE == 1
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""
