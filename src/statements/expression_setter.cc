#include "expression_setter.h"

#include <algorithm>
#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

string ExpressionSetter::Emit() const {
  if (!field_) {
    return "{}";
  }
  return "{set: " + field_->Emit() + "}";
}

void ExpressionSetter::AddField(unique_ptr<ExpressionFunction> function) {
  field_ = move(function);
}