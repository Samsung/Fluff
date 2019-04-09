#include "gtest/gtest.h"

#include <memory>
#include <string>
#include <utility>

#include "statements/expression_literal.h"
#include "statements/expression_variable.h"
#include "utils/status.h"

#include "statements/expression_assignment_add.h"
#include "statements/expression_assignment_bitwise_and.h"
#include "statements/expression_assignment_bitwise_or.h"
#include "statements/expression_assignment_bitwise_xor.h"
#include "statements/expression_assignment_divide.h"
#include "statements/expression_assignment_left_shift.h"
#include "statements/expression_assignment_modulo.h"
#include "statements/expression_assignment_multiply.h"
#include "statements/expression_assignment_right_shift_signed.h"
#include "statements/expression_assignment_right_shift_unsigned.h"
#include "statements/expression_assignment_simple.h"
#include "statements/expression_assignment_subtract.h"

using std::make_unique;
using std::move;
using std::string;
using std::unique_ptr;

class ExpressionAssignmentTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    expression_ = make_unique<ExpressionLiteral>("42");
    variable_ = make_unique<ExpressionVariable>();
    variable_->SetId("v0");
  }

  virtual void TeadDown() {}

  unique_ptr<ExpressionVariable> variable_;
  unique_ptr<Expression> expression_;
};

TEST_F(ExpressionAssignmentTest, Default) {
  ExpressionAssignmentSimple assignment;
  assignment.SetVariable(move(variable_));
  EXPECT_EQ(assignment.Emit(), "((v0)=0)");
}

TEST_F(ExpressionAssignmentTest, Simple) {
  ExpressionAssignmentSimple assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)=42)");
}

TEST_F(ExpressionAssignmentTest, Add) {
  ExpressionAssignmentAdd assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)+=42)");
}

TEST_F(ExpressionAssignmentTest, Subtract) {
  ExpressionAssignmentSubtract assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)-=42)");
}

TEST_F(ExpressionAssignmentTest, Multiply) {
  ExpressionAssignmentMultiply assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)*=42)");
}

TEST_F(ExpressionAssignmentTest, Divide) {
  ExpressionAssignmentDivide assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)/=42)");
}

TEST_F(ExpressionAssignmentTest, Modulo) {
  ExpressionAssignmentModulo assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)%=42)");
}

TEST_F(ExpressionAssignmentTest, LeftShift) {
  ExpressionAssignmentLeftShift assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)<<=42)");
}

TEST_F(ExpressionAssignmentTest, RightShiftUnsigned) {
  ExpressionAssignmentRightShiftUnsigned assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)>>>=42)");
}

TEST_F(ExpressionAssignmentTest, RightShiftSigned) {
  ExpressionAssignmentRightShiftSigned assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)>>=42)");
}

TEST_F(ExpressionAssignmentTest, BitwiseAnd) {
  ExpressionAssignmentBitwiseAnd assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)&=42)");
}

TEST_F(ExpressionAssignmentTest, BitwiseXor) {
  ExpressionAssignmentBitwiseXor assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)^=42)");
}

TEST_F(ExpressionAssignmentTest, BitwiseOr) {
  ExpressionAssignmentBitwiseOr assignment;
  assignment.SetVariable(move(variable_));
  assignment.SetExpression(move(expression_));
  EXPECT_EQ(assignment.Emit(), "((v0)|=42)");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
