#include "instruction_if_else.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

string InstructionIfElse::Emit() const {
  string output = "if (" + expression_->Emit() + ") {\n";
  for (const auto& instr : instruction_block_) {
    output += instr->Emit() + ";\n";
  }
  output += "} else {\n";
  for (const auto& instr : instruction_else_block_) {
    output += instr->Emit() + ";\n";
  }
  output += "}\n";
  return output;
}

void InstructionIfElse::AddInstruction(unique_ptr<Instruction> instruction) {
  instruction_block_.push_back(move(instruction));
}

void InstructionIfElse::AddElseInstruction(
    unique_ptr<Instruction> instruction) {
  instruction_else_block_.push_back(move(instruction));
}

void InstructionIfElse::SetExpression(unique_ptr<Expression> expression) {
  expression_ = move(expression);
}
