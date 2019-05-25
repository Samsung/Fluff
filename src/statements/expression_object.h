#ifndef EXPRESSION_OBJECT_H_
#define EXPRESSION_OBJECT_H_

#include "expression.h"

#include <memory>
#include <unordered_map>

// Represents a javascript object of the following form:
// { name: "value", name2: function() {...}
class ExpressionObject : public Expression {
 public:
  std::string Emit() const override;
  void AddField(const std::string& identifier,
                std::unique_ptr<Expression> expression);

 private:
  std::unordered_map<std::string, std::unique_ptr<Expression>> fields_;
};

#endif  // ifndef EXPRESSION_OBJECT_H_
