#include "javascript_interface.h"

#include "libplatform/libplatform.h"
#include "v8.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::vector;

static const char* ec;

void JavascriptInterface::Init(const char* execution_path) {
  ec = execution_path;
}

void JavascriptInterface::Execute(
    const vector<unique_ptr<Instruction>>& instructions) {
  v8::V8::InitializeICUDefaultLocation(ec);
  v8::V8::InitializeExternalStartupData(ec);
  std::unique_ptr<v8::Platform> platform = v8::platform::NewDefaultPlatform();
  v8::V8::InitializePlatform(platform.get());
  v8::V8::Initialize();
  v8::Isolate::CreateParams create_params;
  create_params.array_buffer_allocator =
      v8::ArrayBuffer::Allocator::NewDefaultAllocator();
  v8::Isolate* isolate = v8::Isolate::New(create_params);
  string my_script;
  for (const auto& instr : instructions) {
    my_script += instr->Emit() + "\n";
  }
  {
    v8::Isolate::Scope isolate_scope(isolate);
    v8::HandleScope handle_scope(isolate);
    v8::Local<v8::Context> context = v8::Context::New(isolate);
    v8::Context::Scope context_scope(context);
    v8::Local<v8::String> source =
        v8::String::NewFromUtf8(isolate, my_script.c_str(),
                                v8::NewStringType::kNormal)
            .ToLocalChecked();

    v8::Local<v8::Script> script;
    if (!v8::Script::Compile(context, source).ToLocal(&script)) {
      return;
    }
    v8::Local<v8::Value> result;
    if (!script->Run(context).ToLocal(&result)) {
      return;
    }
  }
  isolate->Dispose();
  v8::V8::Dispose();
  v8::V8::ShutdownPlatform();
  delete create_params.array_buffer_allocator;
}
