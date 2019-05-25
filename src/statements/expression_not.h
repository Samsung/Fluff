#ifndef EXPRESSION_NOT_H_
#define EXPRESSION_NOT_H_

#include "expression_unary.h"

class ExpressionNot : public ExpressionUnary {
 public:
  std::string Emit() const override;
};

#endif  // ifndef EXPRESSION_NOT_H_
