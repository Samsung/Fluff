#include "instruction_return.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

string InstructionReturn::Emit() const {
  string output = "return";
  if (expression_) {
    output += " " + expression_->Emit();
  }
  return output;
}

void InstructionReturn::SetExpression(unique_ptr<Expression> expression) {
  expression_ = move(expression);
}
