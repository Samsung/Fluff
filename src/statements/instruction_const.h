#ifndef INSTRUCTION_CONST_H_
#define INSTRUCTION_CONST_H_

#include "instruction_definition.h"

class InstructionConst : public InstructionDefinition {
 public:
  std::string Emit() const override;
};

#endif  // INSTRUCTION_CONST_H_