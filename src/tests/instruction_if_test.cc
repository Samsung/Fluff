#include "gtest/gtest.h"

#include "statements/expression.h"
#include "statements/expression_literal.h"
#include "statements/instruction.h"
#include "statements/instruction_if.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::move;

TEST(InstructionIfTest, Default) {
  InstructionIf iif;
  EXPECT_EQ(iif.Emit(), "if (false) {\n}\n");
}

TEST(InstructionIfTest, SimpleBody) {
  ExpressionLiteral literal("true");
  ExpressionLiteral body("42");
  InstructionIf iif;
  iif.SetExpression(make_unique<ExpressionLiteral>(literal));
  iif.AddInstruction(make_unique<ExpressionLiteral>(body));
  EXPECT_EQ(iif.Emit(), "if (true) {\n42;\n}\n");
}

TEST(InstructionIfTest, Corruption) {
  ExpressionLiteral literal("true");
  ExpressionLiteral body("42");
  InstructionIf iif;
  iif.SetExpression(make_unique<ExpressionLiteral>(literal));
  iif.AddInstruction(make_unique<ExpressionLiteral>(body));
  iif.Corrupt('b');
  EXPECT_EQ(iif.Emit(), "if b (true) {\n42;\n}\n");
}

TEST(InstructionIfTest, CorruptionNoOp) {
  ExpressionLiteral literal("true");
  ExpressionLiteral body("42");
  InstructionIf iif;
  iif.SetExpression(make_unique<ExpressionLiteral>(literal));
  iif.AddInstruction(make_unique<ExpressionLiteral>(body));
  iif.Corrupt('a');
  EXPECT_EQ(iif.Emit(), "if (true) {\n42;\n}\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
