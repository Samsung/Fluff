#include "gtest/gtest.h"

#include <memory>
#include <string>

#include "statements/expression_literal.h"
#include "statements/instruction_const.h"
#include "statements/instruction_let.h"
#include "statements/instruction_var.h"
#include "utils/status.h"
#include "variable_id_allocator_mock.h"

using std::make_unique;
using std::string;
using std::unique_ptr;
using testing::_;
using testing::Invoke;

TEST(InstructionVarTest, Default) {
  VariableIdAllocatorMock allocator;
  EXPECT_CALL(allocator, GetId(_)).WillOnce(Invoke([](string *s) -> Status {
    *s = "v0";
    return Status::OkStatus();
  }));
  InstructionVar assignment;
  EXPECT_TRUE(assignment.UseIdAllocator(&allocator).Ok());
  EXPECT_EQ(assignment.Emit(), "var v0=0");
}

TEST(InstructionVarTest, Assign) {
  VariableIdAllocatorMock allocator;
  EXPECT_CALL(allocator, GetId(_)).WillOnce(Invoke([](string *s) -> Status {
    *s = "v0";
    return Status::OkStatus();
  }));
  InstructionVar assignment;
  EXPECT_TRUE(assignment.UseIdAllocator(&allocator).Ok());
  assignment.SetExpression(make_unique<ExpressionLiteral>("42"));
  EXPECT_EQ(assignment.Emit(), "var v0=42");
}

TEST(InstructionVarTest, GetId) {
  VariableIdAllocatorMock allocator;
  EXPECT_CALL(allocator, GetId(_)).WillOnce(Invoke([](string *s) -> Status {
    *s = "v0";
    return Status::OkStatus();
  }));
  InstructionVar assignment;
  EXPECT_TRUE(assignment.UseIdAllocator(&allocator).Ok());
  EXPECT_EQ(assignment.GetId(), "v0");
}

TEST(InstructionLetTest, Assign) {
  VariableIdAllocatorMock allocator;
  EXPECT_CALL(allocator, GetId(_)).WillOnce(Invoke([](string *s) -> Status {
    *s = "v0";
    return Status::OkStatus();
  }));
  InstructionLet assignment;
  EXPECT_TRUE(assignment.UseIdAllocator(&allocator).Ok());
  assignment.SetExpression(make_unique<ExpressionLiteral>("42"));
  EXPECT_EQ(assignment.Emit(), "let v0=42");
}

TEST(InstructionConstTest, Assign) {
  VariableIdAllocatorMock allocator;
  EXPECT_CALL(allocator, GetId(_)).WillOnce(Invoke([](string *s) -> Status {
    *s = "v0";
    return Status::OkStatus();
  }));
  InstructionConst assignment;
  EXPECT_TRUE(assignment.UseIdAllocator(&allocator).Ok());
  assignment.SetExpression(make_unique<ExpressionLiteral>("42"));
  EXPECT_EQ(assignment.Emit(), "const v0=42");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
