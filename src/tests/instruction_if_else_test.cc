#include "gtest/gtest.h"

#include "statements/expression.h"
#include "statements/expression_literal.h"
#include "statements/instruction.h"
#include "statements/instruction_if_else.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::move;

TEST(InstructionIfElseTest, Default) {
  InstructionIfElse ifelse;
  EXPECT_EQ(ifelse.Emit(), "if (false) {\n} else {\n}\n");
}

TEST(InstructionIfElseTest, SimpleBody) {
  ExpressionLiteral literal("true");
  ExpressionLiteral body("42");
  ExpressionLiteral elsebody("\"something\"");
  InstructionIfElse ifelse;
  ifelse.SetExpression(make_unique<ExpressionLiteral>(literal));
  ifelse.AddInstruction(make_unique<ExpressionLiteral>(body));
  ifelse.AddElseInstruction(make_unique<ExpressionLiteral>(elsebody));
  EXPECT_EQ(ifelse.Emit(), "if (true) {\n42;\n} else {\n\"something\";\n}\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
