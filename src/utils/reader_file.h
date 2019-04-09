#ifndef READER_FILE_H_
#define READER_FILE_H_

#include "reader.h"

#include <cstddef>
#include <fstream>
#include <string>

// Reader for files. Given a filename this reader will
// open it and read char by char.
class ReaderFile : public Reader {
 public:
  ReaderFile(){};
  ~ReaderFile() override;
  void SetFileName(const std::string& file_name);
  Status GetChar(char* to_read) override;
  Status ReadYamlGrammar(const std::string& path,
                         YAML::Node* grammar) const override;
  size_t GetFileSize() const;
  int CharactersRead() const override;

 private:
  std::ifstream input_stream_;
  size_t file_size_;
};

#endif  // ifndef READER_FILE_H_
