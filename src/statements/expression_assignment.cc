#include "expression_assignment.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

// TODO: Add implementation.
string ExpressionAssignment::Emit() const {
  return "(" + variable_->Emit() + Operator() + expression_->Emit() + ")";
}

void ExpressionAssignment::SetVariable(
    unique_ptr<ExpressionVariable> variable) {
  variable_ = move(variable);
}

void ExpressionAssignment::SetExpression(unique_ptr<Expression> expression) {
  expression_ = move(expression);
}
