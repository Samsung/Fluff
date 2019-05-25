#ifndef EXPRESSION_MODULO_H_
#define EXPRESSION_MODULO_H_

#include "expression_arithmetic.h"

class ExpressionModulo : public ExpressionArithmetic {
 protected:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_MODULO_H_
