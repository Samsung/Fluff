#include "gtest/gtest.h"

#include <string>

#include "utils/identifier_register.h"

TEST(IdentifierRegisterTest, EmptyVariable) {
  IdentifierRegister identifier_register;
  std::string identifier;
  EXPECT_FALSE(identifier_register.GetVariable(1, &identifier).Ok());
}

TEST(IdentifierRegisterTest, EmptyFunctions) {
  IdentifierRegister identifier_register;
  std::string identifier;
  EXPECT_FALSE(identifier_register.GetFunction(1, &identifier).Ok());
}

TEST(IdentifierRegisterTest, EmptyMethods) {
  IdentifierRegister identifier_register;
  std::string identifier;
  EXPECT_FALSE(identifier_register.GetMethod(1, &identifier).Ok());
}

TEST(IdentifierRegisterTest, Variable) {
  IdentifierRegister identifier_register;
  std::string identifier;
  identifier_register.RegisterVariable("var1");
  identifier_register.RegisterVariable("var2");
  EXPECT_TRUE(identifier_register.GetVariable(0, &identifier).Ok());
  EXPECT_EQ(identifier, "var1");
  EXPECT_TRUE(identifier_register.GetVariable(3, &identifier).Ok());
  EXPECT_EQ(identifier, "var2");
  EXPECT_FALSE(identifier_register.GetMethod(0, &identifier).Ok());
  EXPECT_FALSE(identifier_register.GetFunction(0, &identifier).Ok());
}

TEST(IdentifierRegisterTest, Function) {
  IdentifierRegister identifier_register;
  std::string identifier;
  identifier_register.RegisterFunction("f1");
  identifier_register.RegisterFunction("f2");
  EXPECT_TRUE(identifier_register.GetFunction(0, &identifier).Ok());
  EXPECT_EQ(identifier, "f1");
  EXPECT_TRUE(identifier_register.GetFunction(3, &identifier).Ok());
  EXPECT_EQ(identifier, "f2");
  EXPECT_FALSE(identifier_register.GetVariable(0, &identifier).Ok());
  EXPECT_FALSE(identifier_register.GetMethod(0, &identifier).Ok());
}

TEST(IdentifierRegisterTest, Method) {
  IdentifierRegister identifier_register;
  std::string identifier;
  identifier_register.RegisterMethod("m1");
  identifier_register.RegisterMethod("m2");
  EXPECT_TRUE(identifier_register.GetMethod(0, &identifier).Ok());
  EXPECT_EQ(identifier, "m1");
  EXPECT_TRUE(identifier_register.GetMethod(3, &identifier).Ok());
  EXPECT_EQ(identifier, "m2");
  EXPECT_FALSE(identifier_register.GetVariable(0, &identifier).Ok());
  EXPECT_FALSE(identifier_register.GetFunction(0, &identifier).Ok());
}

TEST(IdentifierRegisterTest, DuplicateMethods) {
  IdentifierRegister identifier_register;
  std::string identifier;
  identifier_register.RegisterMethod("m1");
  identifier_register.RegisterMethod("m2");
  identifier_register.RegisterMethod("m2");
  EXPECT_TRUE(identifier_register.GetMethod(2, &identifier).Ok());
  EXPECT_EQ(identifier, "m1");
}

TEST(IdentifierRegisterTest, DuplicateFunctions) {
  IdentifierRegister identifier_register;
  std::string identifier;
  identifier_register.RegisterFunction("f1");
  identifier_register.RegisterFunction("f2");
  identifier_register.RegisterFunction("f2");
  EXPECT_TRUE(identifier_register.GetFunction(2, &identifier).Ok());
  EXPECT_EQ(identifier, "f1");
}

TEST(IdentifierRegisterTest, DuplicateVariables) {
  IdentifierRegister identifier_register;
  std::string identifier;
  identifier_register.RegisterVariable("v1");
  identifier_register.RegisterVariable("v2");
  identifier_register.RegisterVariable("v2");
  EXPECT_TRUE(identifier_register.GetVariable(2, &identifier).Ok());
  EXPECT_EQ(identifier, "v1");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
