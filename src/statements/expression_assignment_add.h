#ifndef EXPRESSION_ASSIGNMENT_ADD_H_
#define EXPRESSION_ASSIGNMENT_ADD_H_

#include "expression_assignment.h"

class ExpressionAssignmentAdd : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_ASSIGNMENT_ADD_H_
