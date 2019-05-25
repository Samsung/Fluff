#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "expression_function_mock.h"
#include "statements/expression_setter.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::move;

TEST(ExpressionSetterTest, Basic) {
  auto getter = make_unique<ExpressionSetter>();
  auto function = make_unique<ExpressionFunctionMock>();
  EXPECT_CALL(*function, Emit())
      .WillOnce(testing::Return("function(a) {this.b=a}"));
  getter->AddField(move(function));
  EXPECT_EQ(getter->Emit(), "{set: function(a) {this.b=a}}");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
