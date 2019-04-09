#ifndef EXPRESSION_NOT_EQUALS_H_
#define EXPRESSION_NOT_EQUALS_H_

#include "expression_arithmetic.h"

class ExpressionNotEquals : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_NOT_EQUALS_H_
