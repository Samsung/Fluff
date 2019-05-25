#include "expression_literal.h"

using std::string;

ExpressionLiteral::ExpressionLiteral(const string& value) : value_(value) {}

string ExpressionLiteral::Emit() const { return value_; }
