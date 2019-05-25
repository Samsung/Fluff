#ifndef INSTRUCTION_TRY_CATCH_FINALLY_H_
#define INSTRUCTION_TRY_CATCH_FINALLY_H_

#include "instruction.h"

#include <memory>
#include <vector>

class InstructionTryCatchFinally : public Instruction {
 public:
  std::string Emit() const override;
  void AddInstructionTry(std::unique_ptr<Instruction> instruction);
  void AddInstructionCatch(std::unique_ptr<Instruction> instruction);
  void AddInstructionFinally(std::unique_ptr<Instruction> instruction);
  void SetCatchVariable(const std::string& identifier);

 private:
  std::vector<std::unique_ptr<Instruction>> try_block_;
  std::vector<std::unique_ptr<Instruction>> catch_block_;
  std::vector<std::unique_ptr<Instruction>> finally_block_;
  std::string catch_variable_;
};

#endif  // ifndef INSTRUCTION_TRY_CATCH_FINALLY_H_
