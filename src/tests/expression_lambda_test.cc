#include "gmock/gmock.h"

#include <memory>
#include <utility>

#include "instruction_mock.h"
#include "statements/expression_lambda.h"

using std::make_unique;
using std::move;
using testing::Return;

TEST(LambdaTest, Empty) {
  ExpressionLambda function;
  EXPECT_EQ(function.Emit(), "() => {\n}");
}

TEST(FunctionTest, Simple) {
  ExpressionLambda function;
  function.SetArgumentCount(1);
  auto instruction = make_unique<InstructionMock>();
  EXPECT_CALL(*instruction, Emit()).WillOnce(Return("console.log(arg0)"));
  function.AddInstruction(move(instruction));
  EXPECT_EQ(function.Emit(), "(arg0) => {\nconsole.log(arg0);\n}");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
