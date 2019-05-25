#include "expression_class_field_access_dot.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

string ExpressionClassFieldAccessDot::Emit() const {
  return expression_->Emit() + "." + accessor_->Emit();
}

void ExpressionClassFieldAccessDot::SetAccessor(
    unique_ptr<Expression> accessor) {
  accessor_ = move(accessor);
}
