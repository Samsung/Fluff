#ifndef INSTRUCTION_IF_ELSE_H_
#define INSTRUCTION_IF_ELSE_H_

#include <memory>
#include <vector>
#include "expression.h"
#include "expression_literal.h"
#include "instruction.h"

class InstructionIfElse : public Instruction {
 public:
  InstructionIfElse() {}
  std::string Emit() const override;
  void AddInstruction(std::unique_ptr<Instruction> instruction);
  void AddElseInstruction(std::unique_ptr<Instruction> instruction);
  void SetExpression(std::unique_ptr<Expression> expression);

 private:
  std::vector<std::unique_ptr<Instruction>> instruction_block_;
  std::vector<std::unique_ptr<Instruction>> instruction_else_block_;
  std::unique_ptr<Expression> expression_ =
      std::make_unique<ExpressionLiteral>("false");
};

#endif  // INSTRUCTION_IF_H_
