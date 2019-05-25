#ifndef EXPRESSION_VARIABLE_H_
#define EXPRESSION_VARIABLE_H_

#include "expression.h"

class ExpressionVariable : public Expression {
 public:
  ExpressionVariable(){};
  void SetId(const std::string &id);
  std::string Emit() const override;

 private:
  std::string id_ = "something";
};

#endif  // ifndef EXPRESSION_VARIABLE_H_
