#ifndef EXPRESSION_DIVISION_H_
#define EXPRESSION_DIVISION_H_

#include "expression_arithmetic.h"

class ExpressionDivision : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_DIVISION_H_
