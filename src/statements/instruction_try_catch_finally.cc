#include "instruction_try_catch_finally.h"

#include <utility>

using std::move;
using std::string;
using std::unique_ptr;
using std::vector;

string InstructionTryCatchFinally::Emit() const {
  string result = "try {\n";
  for (const auto& instruction : try_block_) {
    result += instruction->Emit() + ";\n";
  }
  result += "} catch (" + catch_variable_ + ") {\n";
  for (const auto& instruction : catch_block_) {
    result += instruction->Emit() + ";\n";
  }
  result += "} finally {\n";
  for (const auto& instruction : finally_block_) {
    result += instruction->Emit() + ";\n";
  }
  result += "}\n";
  return result;
}

void InstructionTryCatchFinally::AddInstructionTry(
    unique_ptr<Instruction> instruction) {
  try_block_.push_back(move(instruction));
}

void InstructionTryCatchFinally::AddInstructionCatch(
    unique_ptr<Instruction> instruction) {
  catch_block_.push_back(move(instruction));
}

void InstructionTryCatchFinally::AddInstructionFinally(
    unique_ptr<Instruction> instruction) {
  finally_block_.push_back(move(instruction));
}

void InstructionTryCatchFinally::SetCatchVariable(const string& identifier) {
  catch_variable_ = identifier;
}
