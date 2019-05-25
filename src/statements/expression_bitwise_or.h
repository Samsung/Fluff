#ifndef EXPRESSION_BITWISE_OR_H_
#define EXPRESSION_BITWISE_OR_H_

#include "expression_arithmetic.h"

class ExpressionBitwiseOr : public ExpressionArithmetic {
 public:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_BITWISE_OR_H_
