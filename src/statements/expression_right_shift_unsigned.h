#ifndef EXPRESSION_RIGHT_SHIFT_UNSIGNED_H_
#define EXPRESSION_RIGHT_SHIFT_UNSIGNED_H_

#include "expression_arithmetic.h"

class ExpressionRightShiftUnsigned : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_RIGHT_SHIFT_UNSIGNED_H_
