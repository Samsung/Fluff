#ifndef EXPRESSION_ASSIGNMENT_MODULO_H_
#define EXPRESSION_ASSIGNMENT_MODULO_H_

#include "expression_assignment.h"

class ExpressionAssignmentModulo : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // EXPRESSION_ASSIGNMENT_MODULO_H_
