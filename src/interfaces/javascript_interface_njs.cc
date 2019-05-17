#include <string>
extern "C" {
#include "njs/njs.h"
}
#include <cstdio>
#include <cstring>
#include "javascript_interface.h"

using std::string;
using std::unique_ptr;
using std::vector;

static njs_vm_t* vm;
static njs_vm_opt_t options;

void JavascriptInterface::Init(const char* exeuction_path) {
  memset(&options, 0, sizeof(njs_vm_opt_t));
  vm = NULL;
  options.shared = 0;
  options.trailer = 0;
  options.init = 1;
  options.accumulative = 0;
  options.backtrace = 1;
  options.sandbox = 0;
  vm = njs_vm_create(&options);
  if (vm == NULL) {
    printf("njs_vm_create() failed\n");
    exit(1);
  }
}

void JavascriptInterface::Execute(
    const vector<unique_ptr<Instruction>>& instructions) {
  string code;
  for (const auto& instr : instructions) {
    code += instr->Emit() + ";\n";
  }
  nxt_int_t ret;
  u_char* start = (u_char*)code.c_str();
  ret = njs_vm_compile(vm, &start, start + code.length());
  if (ret == NXT_OK) {
    ret = njs_vm_start(vm);
  }
  njs_vm_destroy(vm);
  vm = NULL;
}
