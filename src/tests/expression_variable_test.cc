#include "gtest/gtest.h"

#include "statements/expression_variable.h"

constexpr char kVariableName[] = "var";

TEST(ExpressionVariableTest, Variable) {
  ExpressionVariable var;
  var.SetId(kVariableName);
  EXPECT_EQ(var.Emit(), "(var)");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
