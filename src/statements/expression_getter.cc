#include "expression_getter.h"

#include <algorithm>
#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

string ExpressionGetter::Emit() const {
  if (!field_) {
    return "{}";
  }
  return "{get: " + field_->Emit() + "}";
}

void ExpressionGetter::AddField(unique_ptr<ExpressionFunction> function) {
  field_ = move(function);
}