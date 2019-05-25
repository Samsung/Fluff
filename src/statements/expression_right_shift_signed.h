#ifndef EXPRESSION_RIGHT_SHIFT_SIGNED_H_
#define EXPRESSION_RIGHT_SHIFT_SIGNED_H_

#include "expression_arithmetic.h"

class ExpressionRightShiftSigned : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_RIGHT_SHIFT_SIGNED_H_
