#include "instruction_definition.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

void InstructionDefinition::SetExpression(unique_ptr<Expression> expression) {
  expression_ = move(expression);
}

Status InstructionDefinition::UseIdAllocator(VariableIdAllocator* allocator) {
  return allocator->GetId(&id_);
}

string InstructionDefinition::GetId() const { return id_; }
