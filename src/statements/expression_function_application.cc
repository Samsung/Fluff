#include "expression_function_application.h"

#include <utility>

using std::string;
using std::unique_ptr;

string ExpressionFunctionApplication::Emit() const {
  string result;
  result = id_ + "(";
  for (size_t arg = 0; arg < arguments_.size(); arg++) {
    result += arguments_[arg]->Emit();
    if (arg != arguments_.size() - 1) {
      result += ", ";
    }
  }
  result += ")";
  return result;
}

void ExpressionFunctionApplication::SetId(const string& id) { id_ = id; }

void ExpressionFunctionApplication::AddArgument(
    unique_ptr<Expression> argument) {
  arguments_.push_back(move(argument));
}
