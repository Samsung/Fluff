#ifndef EXPRESSION_ASSIGNMENT_DIVIDE_H_
#define EXPRESSION_ASSIGNMENT_DIVIDE_H_

#include "expression_assignment.h"

class ExpressionAssignmentDivide : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_ASSIGNMENT_DIVIDE_H_
