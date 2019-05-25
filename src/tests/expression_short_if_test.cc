#include "gtest/gtest.h"

#include "statements/expression_literal.h"
#include "statements/expression_short_if.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::move;

TEST(ExpressionShortIfTest, Simple) {
  auto condition = make_unique<ExpressionLiteral>("1");
  auto truthy = make_unique<ExpressionLiteral>("2");
  auto falsy = make_unique<ExpressionLiteral>("3");
  ExpressionShortIf short_if;
  short_if.SetCondition(move(condition));
  short_if.SetTrufyExpression(move(truthy));
  short_if.SetFalsyExpression(move(falsy));
  EXPECT_EQ(short_if.Emit(), "1 ? 2 : 3");
}

TEST(ExpressionShortIf, Default) {
  ExpressionShortIf short_if;
  EXPECT_EQ(short_if.Emit(), "false ? 1 : 0");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
