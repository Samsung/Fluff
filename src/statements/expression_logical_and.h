#ifndef EXPRESSION_LOGICAL_AND_H_
#define EXPRESSION_LOGICAL_AND_H_

#include "expression_arithmetic.h"

class ExpressionLogicalAnd : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_LOGICAL_AND_H_
