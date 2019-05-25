#ifndef EXPRESSION_FUNCTION_APPLICATION_H_
#define EXPRESSION_FUNCTION_APPLICATION_H_

#include "expression.h"

#include <memory>
#include <vector>

class ExpressionFunctionApplication : public Expression {
 public:
  std::string Emit() const override;
  void SetId(const std::string& id);
  void AddArgument(std::unique_ptr<Expression> argument);

 private:
  std::string id_;
  std::vector<std::unique_ptr<Expression>> arguments_;
};

#endif  // EXPRESSION_FUNCTION_APPLICATION_H_
