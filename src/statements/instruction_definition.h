#ifndef INSTRUCTION_DEFINITION_H_
#define INSTRUCTION_DEFINITION_H_

#include <memory>

#include "expression.h"
#include "expression_literal.h"
#include "instruction.h"
#include "utils/status.h"
#include "utils/variable_id_allocator.h"

// Definition of a variable.
class InstructionDefinition : public Instruction {
 public:
  void SetExpression(std::unique_ptr<Expression> expression);
  Status UseIdAllocator(VariableIdAllocator *allocator);
  virtual std::string Emit() const = 0;
  std::string GetId() const;

 protected:
  std::unique_ptr<Expression> expression_ =
      std::make_unique<ExpressionLiteral>("0");
  std::string id_ = "something";
};

#endif  // INSTRUCTION_DEFINITION_H_
