#include "gtest/gtest.h"

#include "instruction_mock.h"
#include "statements/expression_literal.h"
#include "statements/instruction_for.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::unique_ptr;
using testing::Return;

constexpr char kSampleVarDeclaration[] = "var x = 0";
constexpr char kSampleInstruction[] = "print(x)";

TEST(InstructionForTest, EmptyFor) {
  InstructionFor ifor;
  EXPECT_EQ(ifor.Emit(), "for ( ;  ; ) {\n}\n");
}

TEST(InstructionForTest, SimpleFor) {
  auto init_mock = make_unique<InstructionMock>();
  EXPECT_CALL(*init_mock, Emit()).WillOnce(Return(kSampleVarDeclaration));
  auto body_mock = make_unique<InstructionMock>();
  EXPECT_CALL(*body_mock, Emit()).WillOnce(Return(kSampleInstruction));
  ExpressionLiteral check("false");
  ExpressionLiteral post("5");
  InstructionFor ifor;
  ifor.SetInitialInstruction(move(init_mock));
  ifor.SetCheckExpression(make_unique<ExpressionLiteral>(check));
  ifor.SetPostExpression(make_unique<ExpressionLiteral>(post));
  ifor.AddInstruction(move(body_mock));
  EXPECT_EQ(ifor.Emit(), "for (var x = 0 ; false ; 5) {\nprint(x);\n}\n");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
