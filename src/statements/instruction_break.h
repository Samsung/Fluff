#ifndef INSTRUCTION_BREAK_H_
#define INSTRUCTION_BREAK_H_

#include "instruction.h"

// Represents a simple break statement.
class InstructionBreak : public Instruction {
 public:
  std::string Emit() const override;
};

#endif  // ifndef INSTRUCTION_BREAK_H_
