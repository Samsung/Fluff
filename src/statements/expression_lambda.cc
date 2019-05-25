#include "expression_lambda.h"

#include <utility>

using std::move;
using std::string;
using std::to_string;
using std::unique_ptr;

string ExpressionLambda::Emit() const {
  string result = "";
  result += "(";
  for (int argument = 0; argument < argument_count_; argument++) {
    result += "arg" + to_string(argument);
    if (argument != argument_count_ - 1) {
      result += ",";
    }
  }
  result += ") => {\n";
  for (const auto& instr : code_block_) {
    result += instr->Emit() + ";\n";
  }
  result += "}";
  return result;
}

void ExpressionLambda::SetArgumentCount(int count) { argument_count_ = count; }

void ExpressionLambda::AddInstruction(unique_ptr<Instruction> instruction) {
  code_block_.push_back(move(instruction));
}
