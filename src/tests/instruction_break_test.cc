#include "gtest/gtest.h"

#include "statements/instruction_break.h"

TEST(InstructionBreakTest, Break) {
  InstructionBreak i_break;
  EXPECT_EQ(i_break.Emit(), "break");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
