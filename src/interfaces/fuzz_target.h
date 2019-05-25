#ifndef FUZZ_TARGET_H_
#define FUZZ_TARGET_H_

// This header handles choosing fuzzing taget.
// It checks which -Doption was passed to compilation, and sets
// one of the following predicates to 1:
// - FUZZ_JERRY
// - FUZZ_ESPURINO
// - FUZZ_DUKTAPE
// - FUZZ_CHAKRA
// - DRY_RUN
// Note,  that exaclty one target will be set to 1, the rest will be set to 0.
// If multiple -D options were passes as -Doptions, the compilation should fail.

#ifndef FUZZ_JERRY
#define FUZZ_JERRY 0
#else
#define FUZZ_JERRY 1
#endif  // ifndef FUZZ_JERRY

#ifndef FUZZ_ESPURINO
#define FUZZ_ESPURINO 0
#else
#define FUZZ_ESPURINO 1
#endif  // ifndef FUZZ_ESPURINO

#ifndef FUZZ_DUKTAPE
#define FUZZ_DUKTAPE 0
#else
#define FUZZ_DUKTAPE 1
#endif  // ifndef FUZZ_DUKTAPE

#ifndef FUZZ_CHAKRA
#define FUZZ_CHAKRA 0
#else
#define FUZZ_CHAKRA 1
#endif  // ifndef FUZZ_CHAKRA

#if FUZZ_DUKTAPE + FUZZ_JERRY + FUZZ_ESPURINO + FUZZ_CHAKRA == 0
#define DRY_RUN 1
#elif FUZZ_DUKTAPE + FUZZ_JERRY + FUZZ_ESPURINO + FUZZ_CHAKRA != 1
#error Multiple fuzzing targets specified.
#else
#define DRY_RUN 0
#endif  // FUZZ_DUKTAPE + FUZZ_JERRY + FUZZ_ESPURINO == 0

#endif  // ifndef FUZZ_TARGET_H_
