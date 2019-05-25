#include "instruction_for.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

string InstructionFor::Emit() const {
  string output = "for (";
  if (initial_instruction_) {
    output += initial_instruction_->Emit();
  }
  output += " ; ";
  if (check_expression_) {
    output += check_expression_->Emit();
  }
  output += " ; ";
  if (post_expression_) {
    output += post_expression_->Emit();
  }
  output += ") {\n";
  for (const auto& instr : instruction_block_) {
    output += instr->Emit() + ";\n";
  }
  output += "}\n";
  return output;
}

void InstructionFor::SetInitialInstruction(
    unique_ptr<Instruction> instruction) {
  initial_instruction_ = move(instruction);
}

void InstructionFor::SetCheckExpression(unique_ptr<Expression> expression) {
  check_expression_ = move(expression);
}

void InstructionFor::SetPostExpression(unique_ptr<Expression> expression) {
  post_expression_ = move(expression);
}

void InstructionFor::AddInstruction(unique_ptr<Instruction> instruction) {
  instruction_block_.push_back(move(instruction));
}
