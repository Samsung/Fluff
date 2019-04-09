#include "gtest/gtest.h"

#include <cstdio>
#include <fstream>
#include <string>

#include "utils/reader_file.h"

using std::ofstream;

constexpr char kSampleFileName[] = "sample_test_file";
constexpr char kSampleFileContents[] = "abcd";
constexpr char kFileDoesntExist[] = "/this_file_does_not_exist";
constexpr char kYamlFileName[] = "sample_yaml_grammar_file";
constexpr char kYamlFileContents[] = "0: {1: one}";
const std::string kVeryLongInput = std::string(3000, 'E');
constexpr char kSampleFileName2[] = "sample_test_file2";

class ReaderFileTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    ofstream sample_file;
    sample_file.open(kSampleFileName,
                     std::ofstream::out | std::ofstream::trunc);
    sample_file << kSampleFileContents;
    sample_file.close();

    ofstream big_file;
    big_file.open(kSampleFileName2, std::ofstream::out | std::ofstream::trunc);
    big_file << kVeryLongInput;
    big_file.close();

    ofstream yaml_file;
    yaml_file.open(kYamlFileName, std::ofstream::out | std::ofstream::trunc);
    yaml_file << kYamlFileContents;
    yaml_file.close();
  }

  virtual void TearDown() {
    remove(kSampleFileName);
    remove(kYamlFileName);
    remove(kSampleFileName2);
  }
};

TEST_F(ReaderFileTest, Simple) {
  ReaderFile reader;
  reader.SetFileName(kSampleFileName);
  char read;
  int chars_read = 0;
  EXPECT_EQ(reader.CharactersRead(), 0);
  for (size_t i = 0; i < strlen(kSampleFileContents); i++) {
    if (i != strlen(kSampleFileContents)) {
      EXPECT_TRUE(reader.GetChar(&read).Ok());
      EXPECT_EQ(reader.CharactersRead(), ++chars_read);
    } else {
      EXPECT_FALSE(reader.GetChar(&read).Ok());
    }
    EXPECT_EQ(read, kSampleFileContents[i]);
  }
}

TEST_F(ReaderFileTest, Size) {
  ReaderFile reader;
  reader.SetFileName(kSampleFileName);
  EXPECT_EQ(reader.GetFileSize(), 4);
}

TEST_F(ReaderFileTest, YamlNonExistent) {
  ReaderFile reader;
  reader.SetFileName(kSampleFileName);
  YAML::Node grammar;
  EXPECT_FALSE(reader.ReadYamlGrammar(kFileDoesntExist, &grammar).Ok());
}

TEST_F(ReaderFileTest, YamlReadGrammar) {
  ReaderFile reader;
  reader.SetFileName(kSampleFileName);
  YAML::Node grammar;
  EXPECT_TRUE(reader.ReadYamlGrammar(kYamlFileName, &grammar).Ok());
  EXPECT_EQ(grammar.size(), 1);
}

TEST_F(ReaderFileTest, TooLongFile) {
  ReaderFile reader;
  reader.SetFileName(kSampleFileName2);
  bool failed = false;
  char dummy;
  for (int i = 0; i < 2900; i++) {
    failed = !reader.GetChar(&dummy).Ok();
  }
  EXPECT_TRUE(failed);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
