#include "gtest/gtest.h"

#include "statements/expression_function_application.h"
#include "statements/expression_literal.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::move;

TEST(ExpressionFunctionApplicationTest, NoArguments) {
  ExpressionFunctionApplication function_application;
  function_application.SetId("f1");
  EXPECT_EQ(function_application.Emit(), "f1()");
}

TEST(ExpressionFunctionApplicationTest, OneArgument) {
  ExpressionFunctionApplication function_application;
  function_application.SetId("f2");
  auto argument = make_unique<ExpressionLiteral>("1");
  function_application.AddArgument(move(argument));
  EXPECT_EQ(function_application.Emit(), "f2(1)");
}

TEST(ExpressionFunctionApplicationTest, TwoArgument) {
  ExpressionFunctionApplication function_application;
  function_application.SetId("f3");
  auto argument = make_unique<ExpressionLiteral>("1");
  function_application.AddArgument(move(argument));
  auto argument2 = make_unique<ExpressionLiteral>("2");
  function_application.AddArgument(move(argument2));
  EXPECT_EQ(function_application.Emit(), "f3(1, 2)");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
