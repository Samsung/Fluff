#include "gtest/gtest.h"

#include <string>

#include "utils/variable_id_allocator_impl.h"

using std::string;

TEST(VariableIdAllocatorImplTest, GetIdUnique) {
  VariableIdAllocatorImpl allocator;
  string id1;
  EXPECT_TRUE(allocator.GetId(&id1).Ok());
  string id2;
  EXPECT_TRUE(allocator.GetId(&id2).Ok());
  EXPECT_NE(id1, id2);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
