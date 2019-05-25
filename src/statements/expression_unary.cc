#include "expression_unary.h"

#include <utility>

using std::move;
using std::unique_ptr;

void ExpressionUnary::SetExpression(unique_ptr<Expression> expression) {
  expression_ = move(expression);
}
