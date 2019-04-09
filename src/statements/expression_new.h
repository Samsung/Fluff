#ifndef EXPRESSION_NEW_H_
#define EXPRESSION_NEW_H_

#include "expression.h"

#include <memory>
#include <vector>

class ExpressionNew : public Expression {
 public:
  std::string Emit() const override;
  void SetType(const std::string& type);
  void AddArgument(std::unique_ptr<Expression> argument);

 private:
  std::string type_;
  std::vector<std::unique_ptr<Expression>> arguments_;
};

#endif  // EXPRESSION_NEW_H_
