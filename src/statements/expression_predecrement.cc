#include "expression_predecrement.h"

std::string ExpressionPredecrement::Emit() const { return "--(" + id_ + ")"; }
