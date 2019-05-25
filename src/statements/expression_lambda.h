#ifndef EXPRESSION_LAMBDA_H_
#define EXPRESSION_LAMBDA_H_

#include "expression.h"
#include "instruction.h"

#include <memory>
#include <vector>

// This class represents definition of a lambda function.
// Typically, a function looks like this:
// (x) => {return x}
class ExpressionLambda : public Expression {
 public:
  std::string Emit() const override;
  void SetArgumentCount(int count);
  void AddInstruction(std::unique_ptr<Instruction> instruction);

 private:
  std::vector<std::unique_ptr<Instruction>> code_block_;
  int argument_count_ = 0;
};

#endif  // EXPRESSION_LAMBDA_H_
