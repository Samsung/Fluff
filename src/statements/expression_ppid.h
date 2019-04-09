#ifndef EXPRESSION_PPID_H_
#define EXPRESSION_PPID_H_

#include "expression.h"

class ExpressionPPID : public Expression {
 public:
  virtual void SetId(const std::string& id);
  virtual std::string Emit() const = 0;

 protected:
  std::string id_;
};

#endif  // ifndef EXPRESSION_PPID_H_