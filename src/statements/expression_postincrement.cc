#include "expression_postincrement.h"

std::string ExpressionPostincrement::Emit() const { return "(" + id_ + ")++"; }
