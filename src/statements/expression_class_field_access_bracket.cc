#include "expression_class_field_access_bracket.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

string ExpressionClassFieldAccessBracket::Emit() const {
  return expression_->Emit() + "[" + accessor_->Emit() + "]";
}

void ExpressionClassFieldAccessBracket::SetAccessor(
    unique_ptr<Expression> accesssor) {
  accessor_ = move(accesssor);
}
