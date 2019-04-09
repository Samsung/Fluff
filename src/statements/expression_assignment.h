#ifndef EXPRESSION_ASSIGNMENT_H_
#define EXPRESSION_ASSIGNMENT_H_

#include "expression.h"
#include "expression_literal.h"
#include "expression_variable.h"

#include <memory>
#include <string>

// An abstract class representing all assignments, such as x += 5, x = 8,
// x <<= 12 + 5, etc.
// Specific types of assignments (add, simple, etc.) should inheritc after
// this class.
class ExpressionAssignment : public Expression {
 public:
  std::string Emit() const override;
  virtual void SetVariable(std::unique_ptr<ExpressionVariable> variable);
  virtual void SetExpression(std::unique_ptr<Expression> expression);

 protected:
  virtual std::string Operator() const = 0;

  std::unique_ptr<ExpressionVariable> variable_;
  std::unique_ptr<Expression> expression_ =
      std::make_unique<ExpressionLiteral>("0");
};

#endif  // EXPRESSION_ASSIGNMENT_H_
