#include "gtest/gtest.h"

#include "statements/expression.h"
#include "statements/expression_literal.h"
#include "statements/instruction.h"
#include "statements/instruction_while.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::move;

TEST(InstructionWhileTest, Default) {
  InstructionWhile iwhile;
  EXPECT_EQ(iwhile.Emit(), "while (false) {\n}\n");
}

TEST(InstructionWhileTest, SimpleBody) {
  ExpressionLiteral literal("true");
  ExpressionLiteral body("42");
  InstructionWhile iwhile;
  iwhile.SetExpression(make_unique<ExpressionLiteral>(literal));
  iwhile.AddInstruction(make_unique<ExpressionLiteral>(body));
  EXPECT_EQ(iwhile.Emit(), "while (true) {\n42;\n}\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
