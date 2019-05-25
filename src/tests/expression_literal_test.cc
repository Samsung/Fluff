#include "gtest/gtest.h"

#include "statements/expression_literal.h"

#include <string>

using std::string;

constexpr char kSampleInt[] = "42";
constexpr char kSampleString[] = "\"this is a string\"";

TEST(ExpressionLiteralTest, Integer) {
  ExpressionLiteral literal(kSampleInt);
  EXPECT_EQ(literal.Emit(), kSampleInt);
}

TEST(ExpressionLiteralTest, String) {
  ExpressionLiteral literal(kSampleString);
  EXPECT_EQ(literal.Emit(), kSampleString);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
