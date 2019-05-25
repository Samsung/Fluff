#include "gtest/gtest.h"

#include "statements/expression_literal.h"
#include "statements/expression_new.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::move;

TEST(ExpressionNewTest, Empty) {
  ExpressionNew expression;
  expression.SetType("Test");
  EXPECT_EQ(expression.Emit(), "new Test()");
}

TEST(ExpressionNewTest, Single) {
  ExpressionNew expression;
  auto literal = make_unique<ExpressionLiteral>("42");
  expression.SetType("Test");
  expression.AddArgument(move(literal));
  EXPECT_EQ(expression.Emit(), "new Test(42)");
}

TEST(ExpressionNewTest, Multiple) {
  ExpressionNew expression;
  auto literal = make_unique<ExpressionLiteral>("42");
  expression.SetType("Test");
  expression.AddArgument(move(literal));
  auto literal2 = make_unique<ExpressionLiteral>("1337");
  expression.AddArgument(move(literal2));
  EXPECT_EQ(expression.Emit(), "new Test(42, 1337)");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
