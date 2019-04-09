#include "gtest/gtest.h"

#include "statements/expression_literal.h"
#include "statements/expression_method_call.h"

#include <memory>
#include <utility>

using std::make_unique;

TEST(ExpressionMethodCall, NoArguments) {
  ExpressionMethodCall call;
  call.SetMethodId("method");
  call.SetObjectId("object");
  EXPECT_EQ(call.Emit(), "object.method()");
}

TEST(ExpressionMethodCall, SingleArgument) {
  ExpressionMethodCall call;
  call.SetMethodId("method");
  call.SetObjectId("object");
  auto argument = make_unique<ExpressionLiteral>("42");
  call.AddArgument(move(argument));
  EXPECT_EQ(call.Emit(), "object.method(42)");
}

TEST(ExpressionMethodCall, Big) {
  ExpressionMethodCall call;
  call.SetMethodId("method");
  call.SetObjectId("object");
  auto argument = make_unique<ExpressionLiteral>("42");
  call.AddArgument(move(argument));
  auto argument2 = make_unique<ExpressionLiteral>("1337");
  call.AddArgument(move(argument2));
  EXPECT_EQ(call.Emit(), "object.method(42, 1337)");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
