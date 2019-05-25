#ifndef EXPRESSION_BITWISE_XOR_H_
#define EXPRESSION_BITWISE_XOR_H_

#include "expression_arithmetic.h"

class ExpressionBitwiseXor : public ExpressionArithmetic {
 public:
  std::string Operator() const override;
};

#endif  // EXPRESSION_BITWISE_XOR_H_
