#ifndef IDENTIFIER_REGISTER_H_
#define IDENTIFIER_REGISTER_H_

#include <cstddef>
#include <string>
#include <unordered_set>
#include <vector>

#include "utils/status.h"

// This class stores identifiers of variables.
// It allows to access variables by a number, control scopes etc.
// It also allows storing information such as type, number of arguments etc.
class IdentifierRegister {
 public:
  void RegisterVariable(const std::string& identifier);
  void RegisterFunction(const std::string& identifier);
  void RegisterMethod(const std::string& identifier);
  Status GetVariable(size_t index, std::string* identifier) const;
  Status GetFunction(size_t index, std::string* identifier) const;
  Status GetMethod(size_t index, std::string* identifier) const;

 private:
  std::vector<std::string> variables_;
  std::vector<std::string> functions_;
  std::vector<std::string> methods_;

  std::unordered_set<std::string> variables_set_;
  std::unordered_set<std::string> functions_set_;
  std::unordered_set<std::string> methods_set_;
};

#endif  // ifndef IDENTIFIER_REGISTER_H_
