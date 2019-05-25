#ifndef VARIABLE_ID_ALLOCATOR_MOCK_H_
#define VARIABLE_ID_ALLOCATOR_MOCK_H_

#include "gmock/gmock.h"
#include "utils/variable_id_allocator.h"

class VariableIdAllocatorMock : public VariableIdAllocator {
 public:
  MOCK_METHOD1(GetId, Status(std::string*));
};

#endif  // ifndef VARIABLE_ID_ALLOCATOR_MOCK_H_
