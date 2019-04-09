#ifndef INSTRUCTION_LET_H_
#define INSTRUCTION_LET_H_

#include "instruction_definition.h"

class InstructionLet : public InstructionDefinition {
 public:
  std::string Emit() const override;
};

#endif  // INSTRUCTION_LET_H_