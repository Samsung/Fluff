#ifndef EXPRESSION_SMALLER_EQUAL_H_
#define EXPRESSION_SMALLER_EQUAL_H_

#include "expression_arithmetic.h"

class ExpressionSmallerEqual : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_SMALLER_EQUAL_H_
