#ifndef EXPRESSION_POSTINCREMENT_H_
#define EXPRESSION_POSTINCREMENT_H_

#include "expression_ppid.h"

class ExpressionPostincrement : public ExpressionPPID {
 public:
  std::string Emit() const override;
};

#endif  // EXPRESSION_POSTINCREMENT_H_
