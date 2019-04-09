#ifndef EXPRESSION_CLASS_FIELD_ACCESS_DOT_H_
#define EXPRESSION_CLASS_FIELD_ACCESS_DOT_H_

#include "expression.h"
#include "expression_literal.h"
#include "expression_unary.h"

#include <memory>

// Represents referencing a field from a class object, i.e object.field.
class ExpressionClassFieldAccessDot : public ExpressionUnary {
 public:
  std::string Emit() const override;
  void SetAccessor(std::unique_ptr<Expression> accessor);

 private:
  std::unique_ptr<Expression> accessor_ =
      std::make_unique<ExpressionLiteral>("__proto__");
};

#endif  // ifndef EXPRESSION_CLASS_FIELD_ACCESS_DOT_H_
