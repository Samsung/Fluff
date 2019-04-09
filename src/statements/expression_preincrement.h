#ifndef EXPRESSION_PREINCREMENT_H_
#define EXPRESSION_PREINCREMENT_H_

#include "expression_ppid.h"

class ExpressionPreincrement : public ExpressionPPID {
 public:
  std::string Emit() const override;
};

#endif  // EXPRESSION_PREINCREMENT_H_
