#include "gtest/gtest.h"

#include "utils/status.h"

constexpr char kErrorMessage[] = "Sample error message.";

TEST(StatusTest, StatusError) {
  auto status = Status::Error(kErrorMessage);
  EXPECT_TRUE(!status.Ok());
  EXPECT_EQ(status.Message(), kErrorMessage);
}

TEST(StatusTest, StatusOk) {
  auto status = Status::OkStatus();
  EXPECT_TRUE(status.Ok());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
