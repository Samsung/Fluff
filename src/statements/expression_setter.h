#ifndef EXPRESSION_SETTER_H_
#define EXPRESSION_SETTER_H_

#include "expression.h"
#include "expression_function.h"

#include <memory>

// Represents a javascript object of the following form:
// { set: function(...) }
// Used in Object.defineProperty
class ExpressionSetter : public Expression {
 public:
  std::string Emit() const override;
  void AddField(std::unique_ptr<ExpressionFunction> function);

 private:
  std::unique_ptr<ExpressionFunction> field_;
};

#endif  // ifndef EXPRESSION_SETTER_H_
