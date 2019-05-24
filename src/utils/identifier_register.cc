#include "identifier_register.h"

using std::string;

void IdentifierRegister::RegisterVariable(const string& identifier) {
  if (variables_set_.find(identifier) == variables_set_.end()) {
    variables_.push_back(identifier);
    variables_set_.insert(identifier);
  }
}

void IdentifierRegister::RegisterFunction(const string& identifier) {
  if (functions_set_.find(identifier) == functions_set_.end()) {
    functions_.push_back(identifier);
    functions_set_.insert(identifier);
  }
}

void IdentifierRegister::RegisterMethod(const string& identifier) {
  if (methods_set_.find(identifier) == methods_set_.end()) {
    methods_.push_back(identifier);
    methods_set_.insert(identifier);
  }
}

Status IdentifierRegister::GetVariable(size_t index, string* identifier) const {
  if (variables_.empty()) {
    return Status::Error("Variable set is empty.");
  }
  *identifier = variables_.at(index % variables_.size());
  return Status::OkStatus();
}

Status IdentifierRegister::GetFunction(size_t index, string* identifier) const {
  if (functions_.empty()) {
    return Status::Error("Function set is empty.");
  }
  *identifier = functions_.at(index % functions_.size());
  return Status::OkStatus();
}

Status IdentifierRegister::GetMethod(size_t index, string* identifier) const {
  if (methods_.empty()) {
    return Status::Error("Method set is empty.");
  }
  *identifier = methods_.at(index % methods_.size());
  return Status::OkStatus();
}
