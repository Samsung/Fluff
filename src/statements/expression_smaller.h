#ifndef EXPRESSION_SMALLER_H_
#define EXPRESSION_SMALLER_H_

#include "expression_arithmetic.h"

class ExpressionSmaller : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_SMALLER_H_
