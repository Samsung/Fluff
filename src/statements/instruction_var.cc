#include "instruction_var.h"

std::string InstructionVar::Emit() const {
  return "var " + id_ + "=" + expression_->Emit();
}