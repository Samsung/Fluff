#ifndef EXPRESSION_PREDECREMENT_H_
#define EXPRESSION_PREDECREMENT_H_

#include "expression_ppid.h"

class ExpressionPredecrement : public ExpressionPPID {
 public:
  std::string Emit() const override;
};

#endif  // EXPRESSION_PREDECREMENT_H_
