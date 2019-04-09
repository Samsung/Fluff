#ifndef EXPRESSION_GETTER_H_
#define EXPRESSION_GETTER_H_

#include "expression.h"
#include "expression_function.h"

#include <memory>

// Represents a javascript object of the following form:
// { get: function(...) }
// Used in Object.defineProperty
class ExpressionGetter : public Expression {
 public:
  std::string Emit() const override;
  void AddField(std::unique_ptr<ExpressionFunction> function);

 private:
  std::unique_ptr<ExpressionFunction> field_;
};

#endif  // ifndef EXPRESSION_GETTER_H_
