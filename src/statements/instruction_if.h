#ifndef INSTRUCTION_IF_H_
#define INSTRUCTION_IF_H_

#include <memory>
#include <vector>
#include "expression.h"
#include "expression_literal.h"
#include "instruction.h"

class InstructionIf : public Instruction {
 public:
  InstructionIf() {}
  std::string Emit() const override;
  void Corrupt(char corruption) override;
  void AddInstruction(std::unique_ptr<Instruction> instruction);
  void SetExpression(std::unique_ptr<Expression> expression);

 private:
  std::vector<std::unique_ptr<Instruction>> instruction_block_;
  std::unique_ptr<Expression> expression_ =
      std::make_unique<ExpressionLiteral>("false");
  char corruption = '\0';
};

#endif  // INSTRUCTION_IF_H_
