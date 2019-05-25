#include "expression_new.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;
using std::vector;

string ExpressionNew::Emit() const {
  string result;
  result = "new " + type_ + "(";
  for (size_t arg = 0; arg < arguments_.size(); arg++) {
    result += arguments_[arg]->Emit();
    if (arg != arguments_.size() - 1) {
      result += ", ";
    }
  }
  result += ")";
  return result;
}

void ExpressionNew::SetType(const string& type) { type_ = type; }

void ExpressionNew::AddArgument(unique_ptr<Expression> argument) {
  arguments_.push_back(move(argument));
}
