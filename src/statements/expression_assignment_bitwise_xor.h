#ifndef EXPRESSION_ASSIGNMENT_BITWISE_XOR_H_
#define EXPRESSION_ASSIGNMENT_BITWISE_XOR_H_

#include "expression_assignment.h"

class ExpressionAssignmentBitwiseXor : public ExpressionAssignment {
 protected:
  std::string Operator() const override;
};

#endif  // ifndef EXPRESSION_ASSIGNMENT_BITWISE_XOR_H_
