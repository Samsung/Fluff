#include "fuzz_target.h"
#include "javascript_interface.h"
#if FUZZ_SPIDERMONKEY == 1

#include <cstdlib>
#include <iostream>

#include <memory>
#include <vector>

// SpiderMonkey headers
#include "js/Initialization.h"
#include "jsapi.h"

// this code is a slightly modified official example:
// https://developer.mozilla.org/en-US/docs/Mozilla/Projects/SpiderMonkey/How_to_embed_the_JavaScript_engine

/* The class of the global object. */
static JSClass global_class = {"global", JSCLASS_GLOBAL_FLAGS,
                               nullptr,  nullptr,
                               nullptr,  nullptr,
                               nullptr,  nullptr,
                               nullptr,  nullptr,
                               nullptr,  nullptr,
                               nullptr,  JS_GlobalObjectTraceHook};

static JSContext *cx;
static JSRuntime *rt;

void JavascriptInterface::Init(const char *exeuction_path) {
  JS_Init();
  rt = JS_NewRuntime(8L * 1024 * 1024);
  if (rt == nullptr) {
    exit(EXIT_FAILURE);
  }

  cx = JS_NewContext(rt, 8192);
  if (cx == nullptr) {
    exit(EXIT_FAILURE);
  }
}

void JavascriptInterface::Execute(
    const std::vector<std::unique_ptr<Instruction>> &instructions) {
  {
    JSAutoRequest ar(cx);

    JS::RootedObject global(cx, JS_NewGlobalObject(cx, &global_class, nullptr,
                                                   JS::FireOnNewGlobalHook));
    if (!global) return;

    JS::RootedValue rval(cx);
    {
      JSAutoCompartment ac(cx, global);
      JS_InitStandardClasses(cx, global);
      int lineno = 0;
      const char *filename = "noname";
      JS::CompileOptions opts(cx);

      for (const auto &instruction : instructions) {
        lineno += 1;
        std::string script = instruction->Emit();
        opts.setFileAndLine(filename, lineno);

        bool ok =
            JS::Evaluate(cx, opts, script.c_str(), script.length(), &rval);
        if (!ok) return;
      }
    }
  }

  JS_DestroyContext(cx);
  JS_DestroyRuntime(rt);
  JS_ShutDown();
}

#endif  // if FUZZ_SPIDERMONKEY == 1
