#ifndef EXPRESSION_LOGICAL_OR_H_
#define EXPRESSION_LOGICAL_OR_H_

#include "expression_arithmetic.h"

class ExpressionLogicalOr : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_LOGICAL_OR_H_
