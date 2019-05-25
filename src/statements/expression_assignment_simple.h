#ifndef EXPRESSION_ASSIGNMENT_SIMPLE_H_
#define EXPRESSION_ASSIGNMENT_SIMPLE_H_

#include "expression_assignment.h"

class ExpressionAssignmentSimple : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_ASSIGNMENT_SIMPLE_H_
