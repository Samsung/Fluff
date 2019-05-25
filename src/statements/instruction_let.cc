#include "instruction_let.h"

std::string InstructionLet::Emit() const {
  return "let " + id_ + "=" + expression_->Emit();
}