#include "reader_file.h"

using std::ifstream;
using std::string;

constexpr int kMaxCharactersRead = 2048;

void ReaderFile::SetFileName(const string& file_name) {
  input_stream_.open(file_name, ifstream::in | std::ios_base::binary);
  if (input_stream_) {
    input_stream_.ignore(std::numeric_limits<std::streamsize>::max());
    file_size_ = input_stream_.gcount();
    input_stream_.clear();                       // Ignore will set EOF.
    input_stream_.seekg(0, std::ios_base::beg);  // Reset pointer.
  }
}

ReaderFile::~ReaderFile() { input_stream_.close(); }

Status ReaderFile::GetChar(char* to_read) {
  if (!input_stream_) {
    return Status::Error("Underlying file error.");
  }
  if (!input_stream_.get(*to_read)) {
    return Status::Error("Reader encountered EOF.");
  }
  if (characters_read_ > kMaxCharactersRead) {
    return Status::Error("Too many characters read, cutting off.");
  }
  characters_read_++;
  return Status::OkStatus();
}

int ReaderFile::CharactersRead() const { return characters_read_; }

size_t ReaderFile::GetFileSize() const { return file_size_; }

Status ReaderFile::ReadYamlGrammar(const std::string& path,
                                   YAML::Node* grammar) const {
  // Library for handling YAML is using exceptions, so we have to use
  // a try-catch block here.
  try {
    *grammar = YAML::LoadFile(path);
  } catch (...) {
    return Status::Error("An error while loading YAML file occured.");
  }
  return Status::OkStatus();
}
