#ifndef EXPRESSION_ASSIGNMENT_RIGHT_SHIFT_SIGNED_H_
#define EXPRESSION_ASSIGNMENT_RIGHT_SHIFT_SIGNED_H_

#include "expression_assignment.h"

class ExpressionAssignmentRightShiftSigned : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_ASSIGNMENT_RIGHT_SHIFT_SIGNED_H_
