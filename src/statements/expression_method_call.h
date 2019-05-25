#ifndef EXPRESSION_METHOD_CALL_H_
#define EXPRESSION_METHOD_CALL_H_

#include "expression.h"

#include <memory>
#include <vector>

// Represents calling a method on class instance, i.e. object.method(args).
class ExpressionMethodCall : public Expression {
 public:
  std::string Emit() const override;
  void SetMethodId(const std::string& id);
  void SetObjectId(const std::string& id);
  void AddArgument(std::unique_ptr<Expression> argument);

 private:
  std::string object_identifier_;
  std::string method_identifier_;
  std::vector<std::unique_ptr<Expression>> arguments_;
};

#endif  // ifndef EXPRESSION_METHOD_CALL_H_
