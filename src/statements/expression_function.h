#ifndef EXPRESSION_FUNCTION_H_
#define EXPRESSION_FUNCTION_H_

#include "expression.h"
#include "instruction.h"

#include <memory>
#include <vector>

// This class represents definition of a function.
// Typically, a function looks like this:
// function f(arg) { instructions; }
// but most of the components can be ommited,
// to create functions wihtout a name or with no arguments.
class ExpressionFunction : public Expression {
 public:
  std::string Emit() const override;
  void SetArgumentCount(int count);
  void SetIdentifier(const std::string& identifier);
  void AddInstruction(std::unique_ptr<Instruction> instruction);

 private:
  std::vector<std::unique_ptr<Instruction>> code_block_;
  int argument_count_ = 0;
  std::string identifier_;
};

#endif  // EXPRESSION_FUNCTION_H_
