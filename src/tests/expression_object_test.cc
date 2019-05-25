#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "statements/expression_literal.h"
#include "statements/expression_object.h"

#include <memory>
#include <utility>

using std::make_unique;
using std::move;

TEST(ExpressionObjectTest, Empty) {
  ExpressionObject object;
  EXPECT_EQ(object.Emit(), "{}");
}

TEST(ExpressionObjectTest, Single) {
  ExpressionObject object;
  auto literal = make_unique<ExpressionLiteral>("42");
  object.AddField("field1", move(literal));
  EXPECT_EQ(object.Emit(), "{field1: 42,\n}");
}

TEST(ExpressionObjectTest, Big) {
  ExpressionObject object;
  auto literal = make_unique<ExpressionLiteral>("42");
  object.AddField("field1", move(literal));
  auto literal2 = make_unique<ExpressionLiteral>("1337");
  object.AddField("field2", move(literal2));
  EXPECT_THAT(object.Emit(), testing::HasSubstr("field1: 42"));
  EXPECT_THAT(object.Emit(), testing::HasSubstr("field2: 1337"));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
