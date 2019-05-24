#include "fuzz_target.h"
#if FUZZ_DUKTAPE == 1
#include "duktape.h"
#include "javascript_interface.h"

using std::unique_ptr;
using std::vector;

static duk_context* ctx;

void JavascriptInterface::Init() { ctx = duk_create_heap_default(); }

void JavascriptInterface::Execute(
    const vector<unique_ptr<Instruction>>& instructions) {
  for (const auto& instruction : instructions) {
    duk_peval_string(ctx, instruction->Emit().c_str());
  }
  duk_destroy_heap(ctx);
}

#endif  // if FUZZ_DUKTAPE == 1
