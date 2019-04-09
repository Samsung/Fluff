#ifndef EXPRESSION_SUBTRACTION_H_
#define EXPRESSION_SUBTRACTION_H_

#include "expression_arithmetic.h"

// Represents subtraction of two expressions.
class ExpressionSubtraction : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_SUBTRACTION_H_
