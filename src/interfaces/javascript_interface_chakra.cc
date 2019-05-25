#include "fuzz_target.h"
#if FUZZ_CHAKRA == 1
#include <csignal>
#include <iostream>
#include <string>
#include "ChakraCore.h"
#include "javascript_interface.h"

#define FAIL_CHECK(cmd)                            \
  do {                                             \
    JsErrorCode errCode = cmd;                     \
    if (errCode != JsNoError) {                    \
      printf("Error %d at '%s'\n", errCode, #cmd); \
      return;                                      \
    }                                              \
  } while (0)

using std::string;
using std::unique_ptr;
using std::vector;

static JsRuntimeHandle runtime;
static JsContextRef context;
static JsValueRef result;
static JsValueRef fname;
static JsValueRef scriptSource;
static unsigned currentSourceContext = 0;

void JavascriptInterface::Init(const char *execution_path) {
  FAIL_CHECK(JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &runtime));
  FAIL_CHECK(JsCreateContext(runtime, &context));
  FAIL_CHECK(JsSetCurrentContext(context));
  FAIL_CHECK(JsCreateString("sample", string("sample").length(), &fname));
}

void IgnoreSignal(int signal) {
  (void)signal;
  exit(0);
}

void JavascriptInterface::Execute(
    const vector<unique_ptr<Instruction>> &instructions) {
  string code;
  for (const auto &instr : instructions) {
    code += instr->Emit() + ";\n";
  }
  try {
    if (SIG_ERR == std::signal(SIGABRT, IgnoreSignal)) {
      perror("signal");
    }
    FAIL_CHECK(JsCreateExternalArrayBuffer((void *)code.c_str(),
                                           (unsigned int)code.length(), nullptr,
                                           nullptr, &scriptSource));
    FAIL_CHECK(JsRun(scriptSource, currentSourceContext++, fname,
                     JsParseScriptAttributeNone, &result));

    // Cleanup.
    FAIL_CHECK(JsSetCurrentContext(JS_INVALID_REFERENCE));
    FAIL_CHECK(JsDisposeRuntime(runtime));
  } catch (...) {
  }
}

#endif  // FUZZ_CHAKRA == 1
