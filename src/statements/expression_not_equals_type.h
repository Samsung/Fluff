#ifndef EXPRESSION_NOT_EQUALS_TYPE_H_
#define EXPRESSION_NOT_EQUALS_TYPE_H_

#include "expression_arithmetic.h"

class ExpressionNotEqualsType : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_NOT_EQUALS_TYPE_H_
