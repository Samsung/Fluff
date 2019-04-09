#include "gtest/gtest.h"

#include "statements/instruction_try_catch_finally.h"

#include "statements/expression_literal.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::move;

TEST(InstructionTryCatchFinallyTest, Full) {
  InstructionTryCatchFinally try_catch_finally;
  auto try_1 = make_unique<ExpressionLiteral>("1");
  auto try_2 = make_unique<ExpressionLiteral>("2");
  auto catch_1 = make_unique<ExpressionLiteral>("3");
  auto catch_2 = make_unique<ExpressionLiteral>("4");
  auto finally_1 = make_unique<ExpressionLiteral>("5");
  auto finally_2 = make_unique<ExpressionLiteral>("6");

  try_catch_finally.AddInstructionTry(move(try_1));
  try_catch_finally.AddInstructionTry(move(try_2));
  try_catch_finally.AddInstructionCatch(move(catch_1));
  try_catch_finally.AddInstructionCatch(move(catch_2));
  try_catch_finally.AddInstructionFinally(move(finally_1));
  try_catch_finally.AddInstructionFinally(move(finally_2));
  try_catch_finally.SetCatchVariable("var");

  EXPECT_EQ(try_catch_finally.Emit(),
            "try {\n1;\n2;\n} catch (var) "
            "{\n3;\n4;\n} finally {\n5;\n6;\n}\n");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
