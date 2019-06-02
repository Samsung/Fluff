#ifndef BUILTINS_H_
#define BUILTINS_H_
#include <string>
namespace builtins {
const std::string functions[] = {
    "load",
    "print",
    "ffi",
    "ffi_cb_free",
    "mkstr",
    "getMJS",
    "die",
    "gc",
    "chr",
    "s2o",
    };
const std::string methods[] = {
    "stringify",
    "parse",
    "create",
    "isNaN",
    "at",
    "length",
    "indexOf",
    "slice",
    "splice",
    "push",
    "apply"
    };
const std::string variables[] = {"global", "Object", "JSON"};
};  // namespace builtins

#endif  // ifndef BUILTINS_H_