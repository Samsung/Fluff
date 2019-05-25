#ifndef EXPRESSION_EQUALS_TYPE_H_
#define EXPRESSION_EQUALS_TYPE_H_

#include "expression_arithmetic.h"

class ExpressionEqualsType : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_EQUALS_TYPE_H_
