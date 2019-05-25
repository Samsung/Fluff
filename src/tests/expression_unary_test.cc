#include "gtest/gtest.h"

#include <memory>

#include "statements/expression_class_field_access_bracket.h"
#include "statements/expression_class_field_access_dot.h"
#include "statements/expression_literal.h"
#include "statements/expression_not.h"

constexpr char kSimpleInt[] = "42";

using std::make_unique;

void SetSampleExpression(ExpressionUnary *expression) {
  ExpressionLiteral literal(kSimpleInt);
  expression->SetExpression(make_unique<ExpressionLiteral>(literal));
}

TEST(ExpressionUnaryTest, Default) {
  ExpressionNot expression;
  EXPECT_EQ(expression.Emit(), "!(NULL)");
}

TEST(ExpressionUnaryTest, ClassFieldAccessDot) {
  ExpressionClassFieldAccessDot dot;
  SetSampleExpression(&dot);
  auto accessor = make_unique<ExpressionLiteral>("abc");
  dot.SetAccessor(move(accessor));
  EXPECT_EQ(dot.Emit(), "42.abc");
}

TEST(ExpressionUnaryTest, ClassFieldAccessBracket) {
  ExpressionClassFieldAccessBracket bracket;
  SetSampleExpression(&bracket);
  auto accessor = make_unique<ExpressionLiteral>("abc");
  bracket.SetAccessor(move(accessor));
  EXPECT_EQ(bracket.Emit(), "42[abc]");
}

TEST(ExpressionUnaryTest, BracketAccessDefault) {
  ExpressionClassFieldAccessBracket bracket;
  SetSampleExpression(&bracket);
  EXPECT_EQ(bracket.Emit(), "42[0]");
}

TEST(ExpressionUnaryTest, DotAccessDefault) {
  ExpressionClassFieldAccessDot dot;
  SetSampleExpression(&dot);
  EXPECT_EQ(dot.Emit(), "42.__proto__");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
