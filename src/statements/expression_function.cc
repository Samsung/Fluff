#include "expression_function.h"

#include <utility>

using std::move;
using std::string;
using std::to_string;
using std::unique_ptr;

string ExpressionFunction::Emit() const {
  string result = "";
  result += "function " + identifier_ + "(";
  for (int argument = 0; argument < argument_count_; argument++) {
    result += "arg" + to_string(argument);
    if (argument != argument_count_ - 1) {
      result += ",";
    }
  }
  result += ") {\n";
  for (const auto& instr : code_block_) {
    result += instr->Emit() + ";\n";
  }
  result += "}";
  return result;
}

void ExpressionFunction::SetArgumentCount(int count) {
  argument_count_ = count;
}

void ExpressionFunction::SetIdentifier(const std::string& identifier) {
  identifier_ = identifier;
}

void ExpressionFunction::AddInstruction(unique_ptr<Instruction> instruction) {
  code_block_.push_back(move(instruction));
}
