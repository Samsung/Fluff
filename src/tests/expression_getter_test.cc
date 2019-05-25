#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "expression_function_mock.h"
#include "statements/expression_getter.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::move;

TEST(ExpressionGetterTest, Basic) {
  auto getter = make_unique<ExpressionGetter>();
  auto function = make_unique<ExpressionFunctionMock>();
  EXPECT_CALL(*function, Emit())
      .WillOnce(testing::Return("function() {return 1}"));
  getter->AddField(move(function));
  EXPECT_EQ(getter->Emit(), "{get: function() {return 1}}");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
