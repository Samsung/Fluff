#ifndef EXPRESSION_BITWISE_AND_H_
#define EXPRESSION_BITWISE_AND_H_

#include "expression_arithmetic.h"

class ExpressionBitwiseAnd : public ExpressionArithmetic {
 public:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_BITWISE_AND_H_
