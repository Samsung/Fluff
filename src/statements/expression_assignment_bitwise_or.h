#ifndef EXPRESSION_ASSIGNMENT_BITWISE_OR_H_
#define EXPRESSION_ASSIGNMENT_BITWISE_OR_H_

#include "expression_assignment.h"

class ExpressionAssignmentBitwiseOr : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_ASSIGNMENT_BITWISE_OR_H_
