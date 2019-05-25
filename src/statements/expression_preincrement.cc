#include "expression_preincrement.h"

std::string ExpressionPreincrement::Emit() const { return "++(" + id_ + ")"; }
