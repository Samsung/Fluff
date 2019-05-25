#ifndef EXPRESSION_LEFT_SHIFT_H_
#define EXPRESSION_LEFT_SHIFT_H_

#include "expression_arithmetic.h"

class ExpressionLeftShift : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_LEFT_SHIFT_H_
