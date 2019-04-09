#include "gtest/gtest.h"

#include "statements/expression_literal.h"
#include "statements/instruction_return.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::move;

TEST(InstructionReturnTest, ReturnVoid) {
  InstructionReturn i_return;
  EXPECT_EQ(i_return.Emit(), "return");
}

TEST(InstructionReturnTest, ReturnInt) {
  InstructionReturn i_return;
  auto expression = make_unique<ExpressionLiteral>("42");
  i_return.SetExpression(move(expression));
  EXPECT_EQ(i_return.Emit(), "return 42");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
