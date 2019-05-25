#include "variable_id_allocator_impl.h"

using std::string;

constexpr char kVariableNamePrefix[] = "v";

Status VariableIdAllocatorImpl::GetId(string* id) {
  if (free_id_ == UINT64_MAX) {
    return Status::Error("Too many identifiers allocated");
  }
  *id = kVariableNamePrefix + std::to_string(free_id_++);
  return Status::OkStatus();
}
