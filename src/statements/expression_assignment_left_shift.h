#ifndef EXPRESSION_ASSIGNMENT_LEFT_SHIFT_H_
#define EXPRESSION_ASSIGNMENT_LEFT_SHIFT_H_

#include "expression_assignment.h"

class ExpressionAssignmentLeftShift : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_ASSIGNMENT_LEFT_SHIFT_H_
