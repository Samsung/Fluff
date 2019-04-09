#ifndef INSTRUCTION_CONTINUE_H_
#define INSTRUCTION_CONTINUE_H_

#include "instruction.h"

// Represents a simple continue statement.
class InstructionContinue : public Instruction {
 public:
  std::string Emit() const override;
};

#endif  // ifndef INSTRUCTION_CONTINUE_H_
