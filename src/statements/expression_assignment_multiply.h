#ifndef EXPRESSION_ASSIGNMENT_MULTIPLY_H_
#define EXPRESSION_ASSIGNMENT_MULTIPLY_H_

#include "expression_assignment.h"

class ExpressionAssignmentMultiply : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_ASSIGNMENT_MULTIPLY_H_
