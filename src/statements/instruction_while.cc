#include "instruction_while.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

string InstructionWhile::Emit() const {
  string output = "while (" + expression_->Emit() + ") {\n";
  for (const auto& instr : instruction_block_) {
    output += instr->Emit() + ";\n";
  }
  output += "}\n";
  return output;
}

void InstructionWhile::AddInstruction(unique_ptr<Instruction> instruction) {
  instruction_block_.push_back(move(instruction));
}

void InstructionWhile::SetExpression(unique_ptr<Expression> expression) {
  expression_ = move(expression);
}
