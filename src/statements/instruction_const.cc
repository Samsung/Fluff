#include "instruction_const.h"

std::string InstructionConst::Emit() const {
  return "const " + id_ + "=" + expression_->Emit();
}