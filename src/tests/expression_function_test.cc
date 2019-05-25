#include "gmock/gmock.h"

#include <memory>
#include <utility>

#include "instruction_mock.h"
#include "statements/expression_function.h"

using std::make_unique;
using std::move;
using testing::Return;

TEST(FunctionTest, Empty) {
  ExpressionFunction function;
  EXPECT_EQ(function.Emit(), "function () {\n}");
}

TEST(FunctionTest, Simple) {
  ExpressionFunction function;
  function.SetArgumentCount(1);
  function.SetIdentifier("f1");
  auto instruction = make_unique<InstructionMock>();
  EXPECT_CALL(*instruction, Emit()).WillOnce(Return("var x = 0"));
  function.AddInstruction(move(instruction));
  EXPECT_EQ(function.Emit(), "function f1(arg0) {\nvar x = 0;\n}");
}

TEST(FunctionTest, Big) {
  ExpressionFunction function;
  function.SetArgumentCount(3);
  function.SetIdentifier("f2");
  auto instruction = make_unique<InstructionMock>();
  EXPECT_CALL(*instruction, Emit()).WillOnce(Return("var x = 0"));
  auto instruction2 = make_unique<InstructionMock>();
  EXPECT_CALL(*instruction2, Emit()).WillOnce(Return("x += 5"));
  function.AddInstruction(move(instruction));
  function.AddInstruction(move(instruction2));
  EXPECT_EQ(function.Emit(),
            "function f2(arg0,arg1,arg2) "
            "{\nvar x = 0;\nx += 5;\n}");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
