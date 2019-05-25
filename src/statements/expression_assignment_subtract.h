#ifndef EXPRESSION_ASSIGNMENT_SUBTRACT_H_
#define EXPRESSION_ASSIGNMENT_SUBTRACT_H_

#include "expression_assignment.h"

class ExpressionAssignmentSubtract : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_ASSIGNMENT_SUBTRACT_H_
