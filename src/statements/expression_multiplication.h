#ifndef EXPRESSION_MULTIPLICATION_H_
#define EXPRESSION_MULTIPLICATION_H_

#include "expression_arithmetic.h"

// Represents a multiplication of two expressions.
class ExpressionMultiplication : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_MULTIPLICATION_H_
