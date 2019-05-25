#ifndef INSTRUCTION_VAR_H_
#define INSTRUCTION_VAR_H_

#include "instruction_definition.h"

class InstructionVar : public InstructionDefinition {
 public:
  std::string Emit() const override;
};

#endif  // INSTRUCTION_VAR_H_