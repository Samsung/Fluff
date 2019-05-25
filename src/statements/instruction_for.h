#ifndef INSTRUCTION_FOR_H_
#define INSTRUCTION_FOR_H_

#include "expression.h"
#include "instruction.h"

#include <memory>
#include <vector>

// Represents a for instruction which is of the following form
// for (initial_instruction ; check_expression ; post_expression) {
//   body;
// }
class InstructionFor : public Instruction {
 public:
  InstructionFor() {}
  std::string Emit() const override;
  void SetInitialInstruction(std::unique_ptr<Instruction> instruction);
  void SetCheckExpression(std::unique_ptr<Expression> expression);
  void SetPostExpression(std::unique_ptr<Expression> expression);
  void AddInstruction(std::unique_ptr<Instruction> instruction);

 private:
  std::unique_ptr<Instruction> initial_instruction_;
  std::unique_ptr<Expression> check_expression_;
  std::unique_ptr<Expression> post_expression_;
  std::vector<std::unique_ptr<Instruction>> instruction_block_;
};

#endif  // INSTRUCTION_FOR_H_
