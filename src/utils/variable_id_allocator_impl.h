#ifndef VARIABLE_ID_ALLOCATOR_IMPL_H_
#define VARIABLE_ID_ALLOCATOR_IMPL_H_

#include "variable_id_allocator.h"

#include <cstdint>
#include <string>

// This class allocates variable names.
class VariableIdAllocatorImpl : public VariableIdAllocator {
 public:
  // On success sets id to a unique variable identifier.
  // On error the value pointed to by `id` is unchanged.
  Status GetId(std::string* id) override;

 private:
  uint64_t free_id_ = 0;
};

#endif  // ifndef VARIABLE_ID_ALLOCATOR_H_
