#include "expression_postdecrement.h"

std::string ExpressionPostdecrement::Emit() const { return "(" + id_ + ")--"; }
