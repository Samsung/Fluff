#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <memory>
#include <string>
#include <vector>

#include "yaml-cpp/yaml.h"

#include "reader_mock.h"
#include "statements/instruction.h"
#include "utils/identifier_register.h"
#include "utils/parser.h"
#include "utils/status.h"

using testing::_;
using testing::Invoke;
using testing::Return;

using std::string;
using std::unique_ptr;
using std::vector;

using namespace std::string_literals;

constexpr char kYamlGrammar[] = R"(
0:
  0: LoopWhile
  1: LoopFor
  2: ConditionalIf
  3: ConditionalIfElse
  4: VariableDeclaration
  5: Return
  6: Break
  7: Continue
  8: TryCatchFinally
  9: LetDeclaration
  10: ConstDeclaration
1:
  0: Addition
  1: Subtraction
  2: Multiplication
  3: Division
  4:
    0: Integer
    1: Real
    2: Boolean
    3: String
    4: SimpleArray
    5: ENull
  5: Variable
  6: LeftShift
  7: RightShiftSigned
  8: RightShiftUnsigned
  9: BitwiseOr
  10: BitwiseXor
  11: BitwiseAnd
  12: LogicalOr
  13: LogicalNot
  14: LogicalAnd
  15:
    0: SimpleAssign
    1: AddAssign
    2: SubAssign
    3: MulAssign
    4: DivAssign
    5: ModAssign
    6: LeftShiftAssign
    7: RightShiftUnsignedAssign
    8: RightShiftSignedAssign
  16: FunctionApplication
  17: MethodApplication
  18: ClassFieldDotAccess
  19: ClassFieldBracketAccess
  20: PreIncrement
  21: PostIncrement
  22: PreDecrement
  23: PostDecrement
  24: FunctionDefinition
  25: ClassDefinition
  26:
    0: Greater
    1: Smaller
    2: GreaterEqual
    3: SmallerEqual
    4: Equal
    5: NotEqual
    6: EqualType
    7: NotEqualType
  27: NewObject
  28: Getter
  29: Setter
  30: ShortIf
  31: Lambda
)";

class ParserTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    characters_read = 0;
    instructions.clear();
    identifier_register = new IdentifierRegister();
    parser = new Parser(node);
  }

  virtual void TearDown() {
    delete identifier_register;
    delete parser;
  }

  YAML::Node node = YAML::Load(kYamlGrammar);
  Parser *parser;
  ReaderMock reader;
  size_t characters_read;
  vector<unique_ptr<Instruction>> instructions;
  IdentifierRegister *identifier_register;
};

Status ReaderMockHelper(size_t &index, const string &input, char *c) {
  if (index < input.length()) {
    *c = input[index++];
  } else {
    return Status::Error("EOF");
  }
  return Status::OkStatus();
}

TEST_F(ParserTest, BooleanFalse) {
  // Note that there is no zero byte in this input.
  // It seems that there must be some prepartion to allow for
  // zero bytes here, as it may interfer with std::string implementation.
  // A quick workaround is use a non zero byte which is congruent to zero
  // modulo grammar size.
  string input = "\x01\x04\x02\x02\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "false");
}

TEST_F(ParserTest, BooleanTrue) {
  // Note that there is no zero byte in this input.
  // It seems that there must be some prepartion to allow for
  // zero bytes here, as it may interfer with std::string implementation.
  // A quick workaround is use a non zero byte which is congruent to zero
  // modulo grammar size.
  string input = "\x01\x04\x02\x03\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "true");
}

TEST_F(ParserTest, Integer) {
  string input = "\x01\x04\x00\x42\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "66");
}

TEST_F(ParserTest, Real) {
  string input = "\x01\x04\x01\x02\x03\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "2.3");
}

TEST_F(ParserTest, SimpleArray) {
  string input = "\x01\x04\x04\x03\x04\x06\x01\x04\x06\x02\x04\x06\x07\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "[1, 2, 7]");
}

TEST_F(ParserTest, Null) {
  string input = "\x01\x04\x05\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "NULL");
}

TEST_F(ParserTest, Addition) {
  string input = "\x01\x00\x04\x00\x01\x04\x00\x02\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "(1+2)");
}

TEST_F(ParserTest, Subtraction) {
  string input = "\x01\x01\x04\x00\x01\x04\x00\x02\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "(1-2)");
}

TEST_F(ParserTest, Multiplication) {
  string input = "\x01\x02\x04\x00\x01\x04\x00\x02\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "(1*2)");
}

TEST_F(ParserTest, Division) {
  string input = "\x01\x03\x04\x00\x01\x04\x00\x02\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "(1/2)");
}

TEST_F(ParserTest, LeftShift) {
  string input = "\x01\x06\x04\x00\x01\x04\x00\x02\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "(1<<2)");
}

TEST_F(ParserTest, RightShiftSigned) {
  string input = "\x01\x07\x04\x00\x01\x04\x00\x02\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "(1>>2)");
}

TEST_F(ParserTest, RightShiftUnsigned) {
  string input = "\x01\x08\x04\x00\x01\x04\x00\x02\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "(1>>>2)");
}

TEST_F(ParserTest, LoopWhile) {
  string input = "\x02\x0B\x01\x04\x02\x01\x01\x04\x00\x01\x01\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "while (true) {\n1;\n}\n");
}

TEST_F(ParserTest, Variable) {
  string input = "\x00\x04\x04\x05\x01\x01\x05\x01\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));

  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "var v0=NULL");

  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 2);
  EXPECT_EQ(instructions[1]->Emit(), "(v0)");
}

TEST_F(ParserTest, TryCatchFinally) {
  string input =
      "\x00\x08\x01\x01\x04\x05\x01\x02\x01\x04\x05\x01\x01\x04\x05\x01\x03"s
      "\x01\x04\x05\x01\x01\x04\x05\x01\x01\x04\x05\x01\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));

  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(),
            "try {\nNULL;\n} catch (v0) "
            "{\nNULL;\nNULL;\n} finally "
            "{\nNULL;\nNULL;\nNULL;\n}\n");
}

TEST_F(ParserTest, Getter) {
  string input = "\x01\x1c\x01\x01\x04\x05\x01\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "{get: function () {\nNULL;\n}}");
}

TEST_F(ParserTest, Setter) {
  string input = "\x01\x1d\x01\x02\x05\x05\x01\x01\x01\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(),
            "{set: function (arg0) {\nreturn (arg0);\n}}");
}

TEST_F(ParserTest, VariableDeclAndArray) {
  string input = "\x00\x04\x04\x04\x02\x04\x00\x01\x04\x00\x02\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "var v0=[1, 2]");
}

TEST_F(ParserTest, LetDeclAndArray) {
  string input = "\x00\x09\x04\x04\x02\x04\x00\x01\x04\x00\x02\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "let v0=[1, 2]");
}

TEST_F(ParserTest, ConstDeclAndArray) {
  string input = "\x00\x0A\x04\x04\x02\x04\x00\x01\x04\x00\x02\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "const v0=[1, 2]");
}

TEST_F(ParserTest, ShortIf) {
  string input = "\x01\x1e\x04\00\x01\x04\x00\x02\x04\x00\x03\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "1 ? 2 : 3");
}

TEST_F(ParserTest, CorruptedIf) {
  string input = "\x00\x02\x01\x04\x05\x01\x04\x05\x05\x62"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "if b (NULL) {\nNULL;\n}\n");
}

TEST_F(ParserTest, FunctionDefinition) {
  string input = "\x01\x18\x01\x01\x02\x05\x04\05\x01\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(), "function v0(arg0) {\nreturn NULL;\n}");
}

TEST_F(ParserTest, Lambda) {
  identifier_register->RegisterFunction("console.log");
  string input = "\x01\x10\x01\x01\x1f\x01\x01\x02\x05\x04\x05\x01\x01"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
  EXPECT_EQ(instructions[0]->Emit(),
            "console.log((arg0) => {\nreturn NULL;\n})");
}

TEST_F(ParserTest, PureRun) {
  string input = "\x01\x04\x06\x00"s;
  parser->SetPureRun();
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_TRUE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 1);
}

TEST_F(ParserTest, PPID) {
  string input =
      "\x00\x04\x04\x00\x01\x00\x01\x14\x01\x00\x01\x15\x01\x00\x01\x16\x01\x00"
      "\x01\x17\x01\x00"s;
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char *c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  while (
      parser->GetInstruction(reader, &instructions, identifier_register).Ok()) {
  }
  EXPECT_EQ(instructions.size(), 5);
  EXPECT_EQ(instructions[0]->Emit(), "var v0=1");
  EXPECT_EQ(instructions[1]->Emit(), "++(v0)");
  EXPECT_EQ(instructions[2]->Emit(), "(v0)++");
  EXPECT_EQ(instructions[3]->Emit(), "--(v0)");
  EXPECT_EQ(instructions[4]->Emit(), "(v0)--");
}

/*TEST_F(ParserTest, CorruptedRun) {
  string input = "\x01\x04\x06\x20";
  EXPECT_CALL(reader, GetChar(_)).WillRepeatedly(Invoke([&](char* c) -> Status {
    return ReaderMockHelper(characters_read, input, c);
  }));
  EXPECT_FALSE(
      parser->GetInstruction(reader, &instructions, identifier_register).Ok());
  EXPECT_EQ(instructions.size(), 0);
}*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
