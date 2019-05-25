#ifndef EXPRESSION_GREATER_EQUAL_H_
#define EXPRESSION_GREATER_EQUAL_H_

#include "expression_arithmetic.h"

class ExpressionGreaterEqual : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_GREATER_EQUAL_H_
