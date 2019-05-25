#ifndef EXPRESSION_ASSIGNMENT_RIGHT_SHIFT_UNSIGNED_H_
#define EXPRESSION_ASSIGNMENT_RIGHT_SHIFT_UNSIGNED_H_

#include "expression_assignment.h"

class ExpressionAssignmentRightShiftUnsigned : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_ASSIGNMENT_RIGHT_SHIFT_UNSIGNED_H_
