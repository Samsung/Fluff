#ifndef EXPRESSION_ADDITION_H_
#define EXPRESSION_ADDITION_H_

#include "expression_arithmetic.h"

// Represents an addition of two expressions.
class ExpressionAddition : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_ADDITION_H_
