#include "instruction_if.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

string InstructionIf::Emit() const {
  string output = "if";
  if (corruption != '\0') {
    output += " ";
    output += corruption;
  }
  output += " (" + expression_->Emit() + ") {\n";
  for (const auto& instr : instruction_block_) {
    output += instr->Emit() + ";\n";
  }
  output += "}\n";
  return output;
}

void InstructionIf::Corrupt(char corruption) {
  if (corruption % 7 == 0) {
    this->corruption = corruption;
  }
}

void InstructionIf::AddInstruction(unique_ptr<Instruction> instruction) {
  instruction_block_.push_back(move(instruction));
}

void InstructionIf::SetExpression(unique_ptr<Expression> expression) {
  expression_ = move(expression);
}
