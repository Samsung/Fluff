#include "gtest/gtest.h"

#include <memory>

#include "statements/expression_postdecrement.h"
#include "statements/expression_postincrement.h"
#include "statements/expression_predecrement.h"
#include "statements/expression_preincrement.h"

using std::make_unique;

TEST(ExpressionPPIDTest, PreincrementTest) {
  ExpressionPreincrement expression;
  expression.SetId("var0");
  EXPECT_EQ(expression.Emit(), "++(var0)");
}

TEST(ExpressionPPIDTest, PostincrementTest) {
  ExpressionPostincrement expression;
  expression.SetId("var0");
  EXPECT_EQ(expression.Emit(), "(var0)++");
}
TEST(ExpressionPPIDTest, PredecrementTest) {
  ExpressionPredecrement expression;
  expression.SetId("var0");
  EXPECT_EQ(expression.Emit(), "--(var0)");
}
TEST(ExpressionPPIDTest, PostdecrementTest) {
  ExpressionPostdecrement expression;
  expression.SetId("var0");
  EXPECT_EQ(expression.Emit(), "(var0)--");
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
