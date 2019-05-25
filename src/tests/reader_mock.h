#ifndef READER_MOCK_H_
#define READER_MOCK_H_

#include "gmock/gmock.h"
#include "utils/reader.h"
#include "utils/status.h"

class ReaderMock : public Reader {
 public:
  MOCK_METHOD1(GetChar, Status(char*));
  MOCK_CONST_METHOD2(ReadYamlGrammar, Status(const std::string&, YAML::Node*));
  MOCK_CONST_METHOD0(CharactersRead, int());
};

#endif  // ifndef READER_MOCK_H_
