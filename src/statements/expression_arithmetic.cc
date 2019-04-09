#include "expression_arithmetic.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

constexpr char kDefaultValue[] = "NULL";

void ExpressionArithmetic::SetLhs(unique_ptr<Expression> expression) {
  lhs_ = move(expression);
}

void ExpressionArithmetic::SetRhs(unique_ptr<Expression> expression) {
  rhs_ = move(expression);
}

string ExpressionArithmetic::Emit() const {
  return "(" + lhs_->Emit() + Operator() + rhs_->Emit() + ")";
}
