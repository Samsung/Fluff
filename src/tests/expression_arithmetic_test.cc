#include "gtest/gtest.h"

#include "statements/expression_addition.h"
#include "statements/expression_bitwise_and.h"
#include "statements/expression_bitwise_or.h"
#include "statements/expression_bitwise_xor.h"
#include "statements/expression_division.h"
#include "statements/expression_equals.h"
#include "statements/expression_equals_type.h"
#include "statements/expression_greater.h"
#include "statements/expression_greater_equal.h"
#include "statements/expression_left_shift.h"
#include "statements/expression_literal.h"
#include "statements/expression_logical_and.h"
#include "statements/expression_logical_or.h"
#include "statements/expression_modulo.h"
#include "statements/expression_multiplication.h"
#include "statements/expression_not_equals.h"
#include "statements/expression_not_equals_type.h"
#include "statements/expression_right_shift_signed.h"
#include "statements/expression_right_shift_unsigned.h"
#include "statements/expression_smaller.h"
#include "statements/expression_smaller_equal.h"
#include "statements/expression_subtraction.h"

#include <memory>
#include <string>
#include <utility>

constexpr char kSimpleInt[] = "42";
constexpr char kSimpleInt2[] = "1337";

using std::make_unique;
using std::string;
using std::unique_ptr;

void SetSampleExpressions(ExpressionArithmetic *expression) {
  if (expression) {
    expression->SetLhs(make_unique<ExpressionLiteral>(kSimpleInt));
    expression->SetRhs(make_unique<ExpressionLiteral>(kSimpleInt2));
  }
}

TEST(ExpressionArithmeticTest, DefaultArguments) {
  ExpressionAddition addition;
  EXPECT_EQ(addition.Emit(), "(1+1)");
}

TEST(ExpressionArithmeticTest, Addition) {
  ExpressionAddition addition;
  SetSampleExpressions(&addition);
  EXPECT_EQ(addition.Emit(), "(42+1337)");
}

TEST(ExpressionArithmeticTest, Subtraction) {
  ExpressionSubtraction subtraction;
  SetSampleExpressions(&subtraction);
  EXPECT_EQ(subtraction.Emit(), "(42-1337)");
}

TEST(ExpressionArithmeticTest, Multiplication) {
  ExpressionMultiplication multiplication;
  SetSampleExpressions(&multiplication);
  EXPECT_EQ(multiplication.Emit(), "(42*1337)");
}

TEST(ExpressionArithmeticTest, Division) {
  ExpressionDivision division;
  SetSampleExpressions(&division);
  EXPECT_EQ(division.Emit(), "(42/1337)");
}

TEST(ExpressionArithmeticTest, LeftShift) {
  ExpressionLeftShift left_shift;
  SetSampleExpressions(&left_shift);
  EXPECT_EQ(left_shift.Emit(), "(42<<1337)");
}

TEST(ExpressionArithmeticTest, RightShiftSigned) {
  ExpressionRightShiftSigned right_shift;
  SetSampleExpressions(&right_shift);
  EXPECT_EQ(right_shift.Emit(), "(42>>1337)");
}

TEST(ExpressionArithmeticTest, RightShiftUnsigned) {
  ExpressionRightShiftUnsigned right_shift;
  SetSampleExpressions(&right_shift);
  EXPECT_EQ(right_shift.Emit(), "(42>>>1337)");
}

TEST(ExpressionArithmeticTest, Modulo) {
  ExpressionModulo modulo;
  SetSampleExpressions(&modulo);
  EXPECT_EQ(modulo.Emit(), "(42%1337)");
}

TEST(ExpressionArithmeticTest, BitwiseAnd) {
  ExpressionBitwiseAnd bitwise_and;
  SetSampleExpressions(&bitwise_and);
  EXPECT_EQ(bitwise_and.Emit(), "(42&1337)");
}

TEST(ExpressionArithmeticTest, BitwiseOr) {
  ExpressionBitwiseOr bitwise_or;
  SetSampleExpressions(&bitwise_or);
  EXPECT_EQ(bitwise_or.Emit(), "(42|1337)");
}

TEST(ExpressionArithmeticTest, BitwiseXor) {
  ExpressionBitwiseXor bitwise_xor;
  SetSampleExpressions(&bitwise_xor);
  EXPECT_EQ(bitwise_xor.Emit(), "(42^1337)");
}

TEST(ExpressionArithmeticTest, LogicalAnd) {
  ExpressionLogicalAnd logical_and;
  SetSampleExpressions(&logical_and);
  EXPECT_EQ(logical_and.Emit(), "(42&&1337)");
}

TEST(ExpressionArithmeticTest, LogicalOr) {
  ExpressionLogicalOr logical_or;
  SetSampleExpressions(&logical_or);
  EXPECT_EQ(logical_or.Emit(), "(42||1337)");
}

TEST(ExpressionArithmeticTest, Equals) {
  ExpressionEquals equals;
  SetSampleExpressions(&equals);
  EXPECT_EQ(equals.Emit(), "(42==1337)");
}

TEST(ExpressionArithmeticTest, NotEquals) {
  ExpressionNotEquals not_equals;
  SetSampleExpressions(&not_equals);
  EXPECT_EQ(not_equals.Emit(), "(42!=1337)");
}

TEST(ExpressionArithmeticTest, EqualsType) {
  ExpressionEqualsType equals;
  SetSampleExpressions(&equals);
  EXPECT_EQ(equals.Emit(), "(42===1337)");
}

TEST(ExpressionArithmeticTest, NotEqualsType) {
  ExpressionNotEqualsType not_equals;
  SetSampleExpressions(&not_equals);
  EXPECT_EQ(not_equals.Emit(), "(42!==1337)");
}

TEST(ExpressionArithmeticTest, Greater) {
  ExpressionGreater greater;
  SetSampleExpressions(&greater);
  EXPECT_EQ(greater.Emit(), "(42>1337)");
}

TEST(ExpressionArithmeticTest, GreaterEqual) {
  ExpressionGreaterEqual greater;
  SetSampleExpressions(&greater);
  EXPECT_EQ(greater.Emit(), "(42>=1337)");
}

TEST(ExpressionArithmeticTest, Smaller) {
  ExpressionSmaller smaller;
  SetSampleExpressions(&smaller);
  EXPECT_EQ(smaller.Emit(), "(42<1337)");
}

TEST(ExpressionArithmeticTest, SmallerEqual) {
  ExpressionSmallerEqual smaller;
  SetSampleExpressions(&smaller);
  EXPECT_EQ(smaller.Emit(), "(42<=1337)");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
