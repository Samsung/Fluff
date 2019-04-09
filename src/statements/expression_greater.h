#ifndef EXPRESSION_GREATER_H_
#define EXPRESSION_GREATER_H_

#include "expression_arithmetic.h"

class ExpressionGreater : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_GREATER_H_
