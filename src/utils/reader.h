#ifndef READER_H_
#define READER_H_

#include <string>

#include "utils/status.h"
#include "yaml-cpp/yaml.h"

// Generic interface for reading input char by char.
class Reader {
 public:
  virtual ~Reader() {}

  // Reads a single character to `to_read`
  // If an error occurs or an EOF is encountered an errorneus status is
  // returned.
  virtual Status GetChar(char* to_read) = 0;

  // Reads a YAML file containing grammar which will be used to parse
  // and generate output.
  // On error, the grammar pointer is not used.
  virtual Status ReadYamlGrammar(const std::string& path,
                                 YAML::Node* grammar) const = 0;

  // Returns number of characters read by this reader.
  virtual int CharactersRead() const = 0;

 protected:
  int characters_read_ = 0;
};

#endif  // ifndef READER_H_
