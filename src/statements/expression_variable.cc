#include "expression_variable.h"

using std::string;

string ExpressionVariable::Emit() const { return "(" + id_ + ")"; }

void ExpressionVariable::SetId(const string& id) { id_ = id; }
