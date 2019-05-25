#include "expression_method_call.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;
using std::vector;

string ExpressionMethodCall::Emit() const {
  string result = object_identifier_ + "." + method_identifier_ + "(";
  for (size_t argument = 0; argument < arguments_.size(); argument++) {
    result += arguments_[argument]->Emit();
    if (argument != arguments_.size() - 1) {
      result += ", ";
    }
  }
  result += ")";
  return result;
}

void ExpressionMethodCall::SetMethodId(const string& id) {
  method_identifier_ = id;
}

void ExpressionMethodCall::SetObjectId(const string& id) {
  object_identifier_ = id;
}

void ExpressionMethodCall::AddArgument(unique_ptr<Expression> argument) {
  arguments_.push_back(move(argument));
}
