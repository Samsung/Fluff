#ifndef INSTRUCTION_RETURN_H_
#define INSTRUCTION_RETURN_H_

#include "expression.h"
#include "instruction.h"

#include <memory>

// Represents a return statement. It can return void (empty return),
// or an expression.
class InstructionReturn : public Instruction {
 public:
  std::string Emit() const override;
  void SetExpression(std::unique_ptr<Expression> expression);

 private:
  std::unique_ptr<Expression> expression_;
};

#endif  // ifndef INSTRUCTION_RETURN_H_
