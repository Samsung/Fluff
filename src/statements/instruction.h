#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <string>

// Generic instruction - root for an instruction type hierarchy.
// All instruction types must inherit after this to provide
// uniform interface.
class Instruction {
 public:
  // Generates target code for this instruction.
  virtual std::string Emit() const = 0;

  // This function "corrupts" an instruction. It allows us to use an extra
  // byte to modify a constructed instruction in order to detect some more
  // itnerreseting errors.
  // NOTE: we do not want to always corrupt instructions. It should be very
  //       likely to construct ordinary, uncorrupted instructions.
  // NOTE: it is required that no randomness is introduced here. This function
  //       must be completly deterministic.
  // As a default, we provide an empty implementation.
  virtual void Corrupt(char corruption) { (void)corruption; }

  virtual ~Instruction(){};
};

#endif  // ifndef INSTRUCTION_H_
