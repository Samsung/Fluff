#ifndef VARIABLE_ID_ALLOCATOR_H_
#define VARIABLE_ID_ALLOCATOR_H_

#include "status.h"

#include <string>

// VariableIdAllocator allocates unique variable names.
class VariableIdAllocator {
 public:
  // On success sets id to a unique variable identifier.
  // On error the value pointed to by `id` is unchanged.
  virtual Status GetId(std::string* id) = 0;
};

#endif  // ifndef VARIABLE_ID_ALLOCATOR_H_
