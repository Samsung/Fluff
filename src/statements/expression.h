#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "instruction.h"

// Virtual metaclass for expressions (addition, function applucation, etc.) to
// inherit after.
class Expression : public Instruction {};

#endif  // ifndef EXPRESSION_H_
