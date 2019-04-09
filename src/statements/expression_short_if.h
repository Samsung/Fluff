#ifndef EXPRESSION_SHORT_IF_H_
#define EXPRESSION_SHORT_IF_H_

#include <memory>
#include "expression.h"
#include "expression_literal.h"

// Represents a trenary operator of the following form:
// condition ? truthy_expression : falsy_expression.
// All three parts of this expression must be set before Emit is called,
// otherwise the behaviour is undefined.
class ExpressionShortIf : public Expression {
 public:
  std::string Emit() const override;
  void SetCondition(std::unique_ptr<Expression> condition);
  void SetTrufyExpression(std::unique_ptr<Expression> expression);
  void SetFalsyExpression(std::unique_ptr<Expression> expression);

 private:
  std::unique_ptr<Expression> condition_ =
      std::make_unique<ExpressionLiteral>("false");
  std::unique_ptr<Expression> truthy_value_ =
      std::make_unique<ExpressionLiteral>("1");
  std::unique_ptr<Expression> falsy_value_ =
      std::make_unique<ExpressionLiteral>("0");
};

#endif  // EXPRESSION_SHORT_IF_H_
