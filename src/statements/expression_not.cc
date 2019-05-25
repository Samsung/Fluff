#include "expression_not.h"

std::string ExpressionNot::Emit() const {
  return "!(" + expression_->Emit() + ")";
}
