#ifndef EXPRESSION_ASSIGNMENT_BITWISE_AND_H_
#define EXPRESSION_ASSIGNMENT_BITWISE_AND_H_

#include "expression_assignment.h"

class ExpressionAssignmentBitwiseAnd : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_ASSIGNMENT_BITWISE_AND_H_
