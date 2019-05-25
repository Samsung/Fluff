#ifndef EXPRESSION_POSTDECREMENT_H_
#define EXPRESSION_POSTDECREMENT_H_

#include "expression_ppid.h"

class ExpressionPostdecrement : public ExpressionPPID {
 public:
  std::string Emit() const override;
};

#endif  // EXPRESSION_POSTDECREMENT_H_
