#include "gtest/gtest.h"

#include "statements/instruction_continue.h"

TEST(InstructionContinueTest, Continue) {
  InstructionContinue i_continue;
  EXPECT_EQ(i_continue.Emit(), "continue");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
