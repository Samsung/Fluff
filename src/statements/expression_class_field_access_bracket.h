#ifndef EXPRESSION_CLASS_FIELD_ACCESS_BRACKET_H_
#define EXPRESSION_CLASS_FIELD_ACCESS_BRACKET_H_

#include "expression_literal.h"
#include "expression_unary.h"

#include <memory>

class ExpressionClassFieldAccessBracket : public ExpressionUnary {
 public:
  std::string Emit() const override;
  void SetAccessor(std::unique_ptr<Expression> accessor);

 private:
  std::unique_ptr<Expression> accessor_ =
      std::make_unique<ExpressionLiteral>("0");
};

#endif  // EXPRESSION_CLASS_FIELD_ACCESS_BRACKET_H_
