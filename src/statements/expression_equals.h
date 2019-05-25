#ifndef EXPRESSION_EQUALS_H_
#define EXPRESSION_EQUALS_H_

#include "expression_arithmetic.h"

class ExpressionEquals : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_EQUALS_H_
