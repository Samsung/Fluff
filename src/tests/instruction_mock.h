#ifndef INSTRUCTION_MOCK_H_
#define INSTRUCTION_MOCK_H_

#include "gmock/gmock.h"
#include "statements/instruction.h"

#include <string>

class InstructionMock : public Instruction {
 public:
  MOCK_CONST_METHOD0(Emit, std::string());
};

#endif  // INSTRUCTION_MOCK_H_
