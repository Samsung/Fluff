#ifndef EXPRESSION_ARITHMETIC_
#define EXPRESSION_ARITHMETIC_

#include "expression.h"
#include "expression_literal.h"

#include <memory>
#include <string>

// An abstract, binary epxression.
// If any part of this expression is not set (lhs or rhs),
// a default value.
class ExpressionArithmetic : public Expression {
 public:
  ExpressionArithmetic(){};

  // Sets lhs of this expression.
  virtual void SetLhs(std::unique_ptr<Expression> expression);

  // Sets rhs of this expression.
  virtual void SetRhs(std::unique_ptr<Expression> expression);

  virtual std::string Emit() const override;

 protected:
  // Returns characters denoting this operation ('+' for addition etc).
  virtual std::string Operator() const = 0;
  std::unique_ptr<Expression> lhs_ = std::make_unique<ExpressionLiteral>("1");
  std::unique_ptr<Expression> rhs_ = std::make_unique<ExpressionLiteral>("1");
};

#endif  // ifndef EXPRESSION_ARITHMETIC_
