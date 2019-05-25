#ifndef EXPRESSION_UNARY_H_
#define EXPRESSION_UNARY_H_

#include <memory>
#include "expression.h"
#include "expression_literal.h"

class ExpressionUnary : public Expression {
 public:
  virtual void SetExpression(std::unique_ptr<Expression> expression);
  virtual std::string Emit() const = 0;

 protected:
  std::unique_ptr<Expression> expression_ =
      std::make_unique<ExpressionLiteral>("NULL");
};

#endif  // ifndef EXPRESSION_UNARY_H_
