#ifndef EXPRESSION_INT_H_
#define EXPRESSION_INT_H_

#include "expression.h"

// An expression representing a concrete literal.
// The value of this number is stored in a string, to allow
// easier manimulation of it.
// It can represent entities such as simple ints, reals,
// strings, arrays, etc.
class ExpressionLiteral : public Expression {
 public:
  ExpressionLiteral(const std::string &value);
  std::string Emit() const override;

 private:
  std::string value_;
};

#endif  // ifndef EXPRESSION_INT_H_
