#ifdef FUZZ_CHAKRA
#include "builtins_chakra.h"
#endif  // ifdef FUZZ_CHAKRA

#ifdef FUZZ_DUKTAPE
#include "builtins_duktape.h"
#endif  // ifdef FUZZ_DUKTAPE

#ifdef FUZZ_ESPRUINO
#include "builtins_espruino.h"
#endif  // ifdef FUZZ_ESPRUINO

#ifdef FUZZ_JERRYSCRIPT
#include "builtins_jerryscript.h"
#endif  // ifdef FUZZ_JERRYSCRIPT

#ifdef FUZZ_NJS
#include "builtins_njs.h"
#endif  // ifdef FUZZ_NJS

#ifdef FUZZ_SPIDERMONKEY
#include "builtins_spidermonkey.h"
#endif  // ifdef FUZZ_SPIDERMONKEY

#ifdef FUZZ_V8
#include "builtins_v8.h"
#endif  // ifdef FUZZ_V8
