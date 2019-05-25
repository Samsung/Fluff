#include "expression_short_if.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

string ExpressionShortIf::Emit() const {
  return condition_->Emit() + " ? " + truthy_value_->Emit() + " : " +
         falsy_value_->Emit();
}

void ExpressionShortIf::SetCondition(unique_ptr<Expression> condition) {
  condition_ = move(condition);
}

void ExpressionShortIf::SetTrufyExpression(unique_ptr<Expression> expression) {
  truthy_value_ = move(expression);
}

void ExpressionShortIf::SetFalsyExpression(unique_ptr<Expression> expression) {
  falsy_value_ = move(expression);
}
