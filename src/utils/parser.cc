#include "parser.h"

#include <climits>
#include <iostream>
#include <string>
#include <utility>

#include "parser_opcodes_util.h"
#include "status.h"
#include "variable_id_allocator_impl.h"

using std::make_unique;
using std::move;
using std::string;
using std::to_string;
using std::unique_ptr;
using std::vector;

Parser::Parser(const YAML::Node &grammar) : grammar_(grammar) {}

void Parser::SetPureRun() { pure_run_ = true; }

static bool LooksLikeArrayLiteral(const string &expression) {
  if (expression.length() == 0) {
    return false;
  }
  if (expression[0] == '[' && expression[expression.length() - 1] == ']') {
    return true;
  }
  return false;
}

Status Parser::GetInstruction(Reader &reader,
                              vector<unique_ptr<Instruction>> *instructions,
                              IdentifierRegister *identifier_register,
                              VariableIdAllocator *allocator,
                              int max_recursion_depth) const {
  if (--max_recursion_depth < 0) {
    return Status::Error("Recursion too deep.");
  }
  char to_read;

  auto current_map = Clone(grammar_);
  // Deduce type of the new instruction.
  do {
    CHECK_RET(reader.GetChar(&to_read));
    current_map = current_map[to_read % current_map.size()];
  } while (current_map.IsMap());

  unique_ptr<Instruction> instruction;
  // Even if we don't have enough data to finish an instruction we want to
  // add it the vector since it will be closed with default values.
  auto closure_status = GetInstructionClosure(
      current_map.as<string>(), reader, &instruction, allocator,
      identifier_register, max_recursion_depth);
  if (!closure_status.Ok()) {
    instructions->push_back(move(instruction));
    return closure_status;
  }
  auto corruption_status = CorruptStatement(reader, &instruction);
  instructions->push_back(move(instruction));
  return corruption_status;
}

Status Parser::GetExpression(Reader &reader, unique_ptr<Expression> *expression,
                             VariableIdAllocator *allocator,
                             IdentifierRegister *identifier_register,
                             int max_recursion_depth) const {
  if (--max_recursion_depth < 0) {
    *expression = make_unique<ExpressionLiteral>("0");
    return Status::Error("Recursion too deep.");
  }
  char to_read;
  auto current_map = Clone(grammar_);
  current_map = current_map[1];  // Expression map.
  do {
    auto reader_status = reader.GetChar(&to_read);
    if (!reader_status.Ok()) {
      *expression = make_unique<ExpressionLiteral>("0");
      return reader_status;
    }
    current_map = current_map[to_read % current_map.size()];
  } while (current_map.IsMap());
  unique_ptr<Instruction> instruction;
  auto get_instruction_status = GetInstructionClosure(
      current_map.as<string>(), reader, &instruction, allocator,
      identifier_register, max_recursion_depth);
  if (auto *expr = dynamic_cast<Expression *>(instruction.get())) {
    (void)expr;
    expression->reset(static_cast<Expression *>(instruction.release()));
    return get_instruction_status;
  } else {
    *expression = make_unique<ExpressionLiteral>("0");
    return Status::Error("Failed to construct an expression.");
  }
}

Status Parser::GetInstructionClosure(const string &operation, Reader &reader,
                                     unique_ptr<Instruction> *instruction,
                                     VariableIdAllocator *allocator,
                                     IdentifierRegister *identifier_register,
                                     int max_recursion_depth) const {
  // Warning: this code was mostly generated.
  if (--max_recursion_depth < 0) {
    *instruction = make_unique<ExpressionLiteral>("0");
    return Status::Error("Recursion too deep.");
  }
  if (operation == opcodes::kAddition) {
    auto addition = make_unique<ExpressionAddition>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(addition.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(addition));
  } else if (operation == opcodes::kSubtraction) {
    auto subtraction = make_unique<ExpressionSubtraction>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(subtraction.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(subtraction));
  } else if (operation == opcodes::kMultiplication) {
    auto multiplication = make_unique<ExpressionMultiplication>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(multiplication.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(multiplication));
  } else if (operation == opcodes::kDivision) {
    auto division = make_unique<ExpressionDivision>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(division.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(division));
  } else if (operation == opcodes::kModulo) {
    auto modulo = make_unique<ExpressionModulo>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(modulo.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(modulo));
  } else if (operation == opcodes::kLeftShift) {
    auto left_shift = make_unique<ExpressionLeftShift>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(left_shift.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(left_shift));
  } else if (operation == opcodes::kRightShiftSigned) {
    auto right_shift_signed = make_unique<ExpressionRightShiftSigned>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(right_shift_signed.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(right_shift_signed));
  } else if (operation == opcodes::kRightShiftUnsigned) {
    auto right_shift_unsigned = make_unique<ExpressionRightShiftUnsigned>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(right_shift_unsigned.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(right_shift_unsigned));
  } else if (operation == opcodes::kBitwiseOr) {
    auto bitwise_or = make_unique<ExpressionBitwiseOr>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(bitwise_or.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(bitwise_or))
  } else if (operation == opcodes::kBitwiseAnd) {
    auto bitwise_and = make_unique<ExpressionBitwiseAnd>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(bitwise_and.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(bitwise_and));
  } else if (operation == opcodes::kBitwiseXor) {
    auto bitwise_xor = make_unique<ExpressionBitwiseXor>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(bitwise_xor.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(bitwise_xor));
  } else if (operation == opcodes::kLogicalOr) {
    auto logical_or = make_unique<ExpressionLogicalOr>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(logical_or.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(logical_or));
  } else if (operation == opcodes::kLogicalAnd) {
    auto logical_and = make_unique<ExpressionLogicalAnd>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(logical_and.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(logical_and));
  } else if (operation == opcodes::kGreater) {
    auto greater = make_unique<ExpressionGreater>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(greater.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(greater));
  } else if (operation == opcodes::kSmaller) {
    auto smaller = make_unique<ExpressionSmaller>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(smaller.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(smaller));
  } else if (operation == opcodes::kGreaterEqual) {
    auto greater_equal = make_unique<ExpressionGreaterEqual>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(greater_equal.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(greater_equal));
  } else if (operation == opcodes::kSmallerEqual) {
    auto smaller_equal = make_unique<ExpressionSmallerEqual>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(smaller_equal.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(smaller_equal));
  } else if (operation == opcodes::kEqual) {
    auto equal = make_unique<ExpressionEquals>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(equal.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(equal))
  } else if (operation == opcodes::kNotEqual) {
    auto not_equal = make_unique<ExpressionNotEquals>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(not_equal.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(not_equal));
  } else if (operation == opcodes::kEqualType) {
    auto equal_type = make_unique<ExpressionEqualsType>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(equal_type.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(equal_type));
  } else if (operation == opcodes::kNotEqualType) {
    auto not_equal_type = make_unique<ExpressionNotEqualsType>();
    CHECK_FINALLY_RET(
        GetBinaryOperatorOperands(not_equal_type.get(), reader, allocator,
                                  identifier_register, max_recursion_depth),
        *instruction = move(not_equal_type));
  } else if (operation == opcodes::kVariableAssignment) {
    auto assign = make_unique<ExpressionAssignmentSimple>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kVariableAssignmentAdd) {
    auto assign = make_unique<ExpressionAssignmentAdd>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kVariableAssignmentSub) {
    auto assign = make_unique<ExpressionAssignmentSubtract>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kVariableAssignmentMul) {
    auto assign = make_unique<ExpressionAssignmentMultiply>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kVariableAssignmentDiv) {
    auto assign = make_unique<ExpressionAssignmentDivide>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kVariableAssignmentMod) {
    auto assign = make_unique<ExpressionAssignmentModulo>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kVariableAssignmentLeftShift) {
    auto assign = make_unique<ExpressionAssignmentLeftShift>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kVariableAssignmentRightShiftSigned) {
    auto assign = make_unique<ExpressionAssignmentRightShiftSigned>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kVariableAssignmentRightShiftUnsigned) {
    auto assign = make_unique<ExpressionAssignmentRightShiftUnsigned>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kVariableAssignmentBitwiseOr) {
    auto assign = make_unique<ExpressionAssignmentBitwiseOr>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kVariableAssignmentBitwiseAnd) {
    auto assign = make_unique<ExpressionAssignmentBitwiseAnd>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kVariableAssignmentBitwiseXor) {
    auto assign = make_unique<ExpressionAssignmentBitwiseXor>();
    CHECK_FINALLY_RET(
        GetAssignmentOperands(identifier_register, assign.get(), reader,
                              allocator, max_recursion_depth),
        *instruction = move(assign));
  } else if (operation == opcodes::kPostIncrement) {
    auto post_increment = make_unique<ExpressionPostincrement>();
    auto status =
        GetVariablePPID(reader, identifier_register, post_increment.get());
    *instruction = move(post_increment);
    return status;
  } else if (operation == opcodes::kPreIncrement) {
    auto pre_increment = make_unique<ExpressionPreincrement>();
    auto status =
        GetVariablePPID(reader, identifier_register, pre_increment.get());
    *instruction = move(pre_increment);
    return status;
  } else if (operation == opcodes::kPostDecrement) {
    auto post_decrement = make_unique<ExpressionPostdecrement>();
    auto status =
        GetVariablePPID(reader, identifier_register, post_decrement.get());
    *instruction = move(post_decrement);
    return status;
  } else if (operation == opcodes::kPreDecrement) {
    auto pre_decrement = make_unique<ExpressionPredecrement>();
    auto status =
        GetVariablePPID(reader, identifier_register, pre_decrement.get());
    *instruction = move(pre_decrement);
    return status;
  } else if (operation == opcodes::kLogicalNot) {
    auto expression_not = make_unique<ExpressionNot>();
    unique_ptr<Expression> expression;
    CHECK_SUCCECSS_RET(GetExpression(reader, &expression, allocator,
                                     identifier_register, max_recursion_depth),
                       expression_not->SetExpression(move(expression)),
                       *instruction = move(expression_not));
  } else if (operation == opcodes::kClassFieldDotAccess) {
    auto dot_access = make_unique<ExpressionClassFieldAccessDot>();
    unique_ptr<Expression> expression;
    auto expression_status =
        GetExpression(reader, &expression, allocator, identifier_register,
                      max_recursion_depth);
    dot_access->SetExpression(move(expression));
    unique_ptr<Expression> accessor;
    auto accessor_status = GetExpression(
        reader, &accessor, allocator, identifier_register, max_recursion_depth);
    dot_access->SetAccessor(move(accessor));
    *instruction = move(dot_access);
    return accessor_status;
  } else if (operation == opcodes::kClassFieldBracketAccess) {
    auto bracket_access = make_unique<ExpressionClassFieldAccessBracket>();
    unique_ptr<Expression> expression;
    auto expression_status =
        GetExpression(reader, &expression, allocator, identifier_register,
                      max_recursion_depth);
    bracket_access->SetExpression(move(expression));
    unique_ptr<Expression> accessor;
    auto accessor_status = GetExpression(
        reader, &accessor, allocator, identifier_register, max_recursion_depth);
    bracket_access->SetAccessor(move(accessor));
    *instruction = move(bracket_access);
    return accessor_status;
  } else if (operation == opcodes::kInteger) {
    char to_read;
    auto reader_status = reader.GetChar(&to_read);
    if (!reader_status.Ok()) {
      to_read = '0';
    }
    auto integer = make_unique<ExpressionLiteral>(to_string((uint8_t)to_read));
    *instruction = move(integer);
    return reader_status;
  } else if (operation == opcodes::kReal) {
    char real, fraction;
    auto real_reader_status = reader.GetChar(&real);
    auto fraction_reader_status = reader.GetChar(&fraction);
    if (!real_reader_status.Ok()) {
      real = '0';
    }
    if (!fraction_reader_status.Ok()) {
      fraction = '0';
    }
    auto literal = make_unique<ExpressionLiteral>(to_string(real) + "." +
                                                  to_string((uint8_t)fraction));
    *instruction = move(literal);
    return fraction_reader_status;
  } else if (operation == opcodes::kBoolean) {
    char to_read;
    auto reader_status = reader.GetChar(&to_read);
    if (!reader_status.Ok()) {
      *instruction = make_unique<ExpressionLiteral>("false");
      return reader_status;
    }
    if (to_read % 2) {
      *instruction = make_unique<ExpressionLiteral>("true");
    } else {
      *instruction = make_unique<ExpressionLiteral>("false");
    }
  } else if (operation == opcodes::kString) {
    char length = 0;
    auto reader_status = reader.GetChar(&length);
    if (!reader_status.Ok()) {
      *instruction = make_unique<ExpressionLiteral>("\"\"");
    }
    string string_literal = "";
    char to_read;
    for (int char_count = 0; char_count < length; char_count++) {
      auto reader_status = reader.GetChar(&to_read);
      if (!reader_status.Ok()) {
        *instruction = make_unique<ExpressionLiteral>(string_literal);
        return reader_status;
      }
      string_literal += to_read;
    }
    *instruction = make_unique<ExpressionLiteral>("\"" + string_literal + "\"");
  } else if (operation == opcodes::kSimpleArray) {
    char length;
    auto status = reader.GetChar(&length);
    if (!status.Ok()) {
      *instruction = make_unique<ExpressionLiteral>("[]");
      return status;
    }
    string contents = "[";
    for (int element = 0; element < length; element++) {
      unique_ptr<Expression> expression;
      status = GetExpression(reader, &expression, allocator,
                             identifier_register, max_recursion_depth);
      contents += expression->Emit();
      if (element != length - 1) {
        contents += ", ";
      }
    }
    contents += "]";
    *instruction = make_unique<ExpressionLiteral>(contents);
    return status;
  } else if (operation == opcodes::kNull) {
    *instruction = make_unique<ExpressionLiteral>("NULL");
  } else if (operation == opcodes::kTryCatchFinally) {
    auto try_catch = make_unique<InstructionTryCatchFinally>();
    std::string catch_variable;
    auto allocator_status = allocator->GetId(&catch_variable);
    if (!allocator_status.Ok()) {
      *instruction = move(try_catch);
      return allocator_status;
    }
    try_catch->SetCatchVariable(catch_variable);
    identifier_register->RegisterVariable(catch_variable);
    char instruction_count;
    auto reader_status = reader.GetChar(&instruction_count);
    if (!reader_status.Ok()) {
      *instruction = move(try_catch);
      return reader_status;
    }
    vector<unique_ptr<Instruction>> try_instructions;
    auto status = Status::OkStatus();
    for (int instruction = 0; instruction < instruction_count; instruction++) {
      status = GetInstruction(reader, &try_instructions, identifier_register,
                              allocator, max_recursion_depth);
      if (!status.Ok()) {
        break;
      }
    }
    for (auto &instruction : try_instructions) {
      try_catch->AddInstructionTry(move(instruction));
    }

    reader_status = reader.GetChar(&instruction_count);
    if (!reader_status.Ok()) {
      *instruction = move(try_catch);
      return reader_status;
    }
    vector<unique_ptr<Instruction>> catch_instructions;
    for (int instruction = 0; instruction < instruction_count; instruction++) {
      if (!GetInstruction(reader, &catch_instructions, identifier_register,
                          allocator, max_recursion_depth)
               .Ok()) {
        break;
      }
    }
    for (auto &instruction : catch_instructions) {
      try_catch->AddInstructionCatch(move(instruction));
    }
    reader_status = reader.GetChar(&instruction_count);
    if (!reader_status.Ok()) {
      *instruction = move(try_catch);
      return reader_status;
    }
    vector<unique_ptr<Instruction>> finally_instructions;
    for (int instruction = 0; instruction < instruction_count; instruction++) {
      if (!GetInstruction(reader, &finally_instructions, identifier_register,
                          allocator, max_recursion_depth)
               .Ok()) {
        break;
      }
    }
    for (auto &instruction : finally_instructions) {
      try_catch->AddInstructionFinally(move(instruction));
    }
    *instruction = move(try_catch);
  } else if (operation == opcodes::kWhile) {
    auto i_while = make_unique<InstructionWhile>();
    char instruction_count;
    auto reader_status = reader.GetChar(&instruction_count);
    if (!reader_status.Ok()) {
      *instruction = move(i_while);
      return reader_status;
    }
    unique_ptr<Expression> expression;
    auto expression_status =
        GetExpression(reader, &expression, allocator, identifier_register,
                      max_recursion_depth);
    vector<unique_ptr<Instruction>> while_instructions;
    for (int instruction = 0; instruction < instruction_count; instruction++) {
      expression_status =
          GetInstruction(reader, &while_instructions, identifier_register,
                         allocator, max_recursion_depth);
      if (!expression_status.Ok()) {
        break;
      }
    }
    for (auto &instruction : while_instructions) {
      i_while->AddInstruction(move(instruction));
    }
    i_while->SetExpression(move(expression));
    *instruction = move(i_while);
    return expression_status;
  } else if (operation == opcodes::kFor) {
    auto i_for = make_unique<InstructionFor>();
    char instruction_count;
    auto reader_status = reader.GetChar(&instruction_count);
    if (!reader_status.Ok()) {
      instruction_count = 0;
    }
    vector<unique_ptr<Instruction>> instruction_initial;
    auto get_instruction_status =
        GetInstruction(reader, &instruction_initial, identifier_register,
                       allocator, max_recursion_depth);
    unique_ptr<Expression> expression_check;
    auto get_expression_1_status =
        GetExpression(reader, &expression_check, allocator, identifier_register,
                      max_recursion_depth);
    unique_ptr<Expression> expression_post;
    auto get_expression_2_status =
        GetExpression(reader, &expression_post, allocator, identifier_register,
                      max_recursion_depth);
    vector<unique_ptr<Instruction>> for_instructions;
    for (int instruction = 0; instruction < instruction_count; instruction++) {
      auto get_body_status =
          GetInstruction(reader, &for_instructions, identifier_register,
                         allocator, max_recursion_depth);
      if (!get_body_status.Ok()) {
        break;
      }
    }
    for (auto &instruction : for_instructions) {
      i_for->AddInstruction(move(instruction));
    }
    if (get_instruction_status.Ok()) {
      i_for->SetInitialInstruction(move(instruction_initial.at(0)));
    }
    i_for->SetCheckExpression(move(expression_check));
    i_for->SetPostExpression(move(expression_post));
    *instruction = move(i_for);
    return get_expression_2_status;
  } else if (operation == opcodes::kIf) {
    auto i_if = make_unique<InstructionIf>();
    char instruction_count;
    auto reader_status = reader.GetChar(&instruction_count);
    if (!reader_status.Ok()) {
      instruction_count = 0;
    }
    unique_ptr<Expression> expression;
    auto get_expression_status =
        GetExpression(reader, &expression, allocator, identifier_register,
                      max_recursion_depth);
    vector<unique_ptr<Instruction>> if_instructions;
    for (int instruction = 0; instruction < instruction_count; instruction++) {
      auto get_instruction_status =
          GetInstruction(reader, &if_instructions, identifier_register,
                         allocator, max_recursion_depth);
      if (!get_instruction_status.Ok()) {
        break;
      }
    }
    for (auto &instruction : if_instructions) {
      i_if->AddInstruction(move(instruction));
    }
    i_if->SetExpression(move(expression));
    *instruction = move(i_if);
    return get_expression_status;
  } else if (operation == opcodes::kIfElse) {
    auto i_ifelse = make_unique<InstructionIfElse>();
    char instruction_count;
    auto reader_status = reader.GetChar(&instruction_count);
    if (!reader_status.Ok()) {
      instruction_count = 0;
    }
    char else_count;
    reader_status = reader.GetChar(&else_count);
    if (!reader_status.Ok()) {
      else_count = 0;
    }
    unique_ptr<Expression> expression;
    auto get_expression_status =
        GetExpression(reader, &expression, allocator, identifier_register,
                      max_recursion_depth);
    vector<unique_ptr<Instruction>> if_instructions;
    for (int instruction = 0; instruction < instruction_count; instruction++) {
      if (!GetInstruction(reader, &if_instructions, identifier_register,
                          allocator, max_recursion_depth)
               .Ok()) {
        break;
      }
    }
    vector<unique_ptr<Instruction>> else_instructions;
    for (int instruction = 0; instruction < else_count; instruction++) {
      if (!GetInstruction(reader, &else_instructions, identifier_register,
                          allocator, max_recursion_depth)
               .Ok()) {
        break;
      }
    }
    for (auto &instruction : if_instructions) {
      i_ifelse->AddInstruction(move(instruction));
    }
    for (auto &instruction : else_instructions) {
      i_ifelse->AddElseInstruction(move(instruction));
    }
    i_ifelse->SetExpression(move(expression));
    *instruction = move(i_ifelse);
    return get_expression_status;
  } else if (operation == opcodes::kVariableDeclaration) {
    auto definition = make_unique<InstructionVar>();
    (void)definition->UseIdAllocator(allocator);
    unique_ptr<Expression> expression;
    auto expression_status =
        GetExpression(reader, &expression, allocator, identifier_register,
                      max_recursion_depth);
    if (auto *fun = dynamic_cast<ExpressionFunction *>(expression.get())) {
      (void)fun;
      identifier_register->RegisterFunction(definition->GetId());
    } else {
      identifier_register->RegisterVariable(definition->GetId());
      if (LooksLikeArrayLiteral(expression->Emit())) {
        identifier_register->RegisterArray(definition->GetId());
      }
    }
    definition->SetExpression(move(expression));
    *instruction = move(definition);
    return expression_status;
  } else if (operation == opcodes::kLetDeclaration) {
    auto definition = make_unique<InstructionLet>();
    (void)definition->UseIdAllocator(allocator);
    unique_ptr<Expression> expression;
    auto get_expression_status =
        GetExpression(reader, &expression, allocator, identifier_register,
                      max_recursion_depth);
    if (auto *fun = dynamic_cast<ExpressionFunction *>(expression.get())) {
      (void)fun;
      identifier_register->RegisterFunction(definition->GetId());
    } else {
      identifier_register->RegisterVariable(definition->GetId());
      if (LooksLikeArrayLiteral(expression->Emit())) {
        identifier_register->RegisterArray(definition->GetId());
      }
    }
    definition->SetExpression(move(expression));
    *instruction = move(definition);
    return get_expression_status;
  } else if (operation == opcodes::kConstDeclaration) {
    auto definition = make_unique<InstructionConst>();
    (void)definition->UseIdAllocator(allocator);
    unique_ptr<Expression> expression;
    auto get_expression_status =
        GetExpression(reader, &expression, allocator, identifier_register,
                      max_recursion_depth);
    if (auto *fun = dynamic_cast<ExpressionFunction *>(expression.get())) {
      (void)fun;
      identifier_register->RegisterFunction(definition->GetId());
    } else {
      identifier_register->RegisterVariable(definition->GetId());
      if (LooksLikeArrayLiteral(expression->Emit())) {
        identifier_register->RegisterArray(definition->GetId());
      }
    }
    definition->SetExpression(move(expression));
    *instruction = move(definition);
    return get_expression_status;
  } else if (operation == opcodes::kReturn) {
    auto i_ret = make_unique<InstructionReturn>();
    unique_ptr<Expression> expression;
    auto get_expression_status =
        GetExpression(reader, &expression, allocator, identifier_register,
                      max_recursion_depth);
    i_ret->SetExpression(move(expression));
    *instruction = move(i_ret);
    return get_expression_status;
  } else if (operation == opcodes::kContinue) {
    *instruction = make_unique<InstructionContinue>();
  } else if (operation == opcodes::kBreak) {
    *instruction = make_unique<InstructionBreak>();
  } else if (operation == opcodes::kVariable) {
    string identifier;
    char to_read;
    if (!reader.GetChar(&to_read).Ok()) {
      to_read = 0;
    }
    auto identifier_status =
        identifier_register->GetVariable(to_read, &identifier);
    auto variable = make_unique<ExpressionVariable>();
    if (identifier_status.Ok()) {
      variable->SetId(identifier);
    }
    *instruction = move(variable);
  } else if (operation == opcodes::kFunctionDefinition) {
    auto function = make_unique<ExpressionFunction>();
    string identifier;
    if (allocator->GetId(&identifier).Ok()) {
      function->SetIdentifier(identifier);
      identifier_register->RegisterFunction(identifier);
      // In JS you can do things like:
      // function y() { ... }
      // y.apply(null, [])
      // Therefore we should threat functions like object.
      // This is a quick hack for now. TODO: refactor.
      identifier_register->RegisterVariable(identifier);
    }
    char arguments_count;
    if (!reader.GetChar(&arguments_count).Ok()) {
      arguments_count = 0;
    }
    function->SetArgumentCount(arguments_count);
    for (int i = 0; i < arguments_count; i++) {
      identifier_register->RegisterVariable("arg" + to_string(i));
    }
    char instruction_count;
    if (!reader.GetChar(&instruction_count).Ok()) {
      instruction_count = 0;
    }
    vector<unique_ptr<Instruction>> instructions;
    for (int i = 0; i < instruction_count; i++) {
      if (!GetInstruction(reader, &instructions, identifier_register, allocator,
                          max_recursion_depth)
               .Ok()) {
        break;
      }
    }
    for (auto &instruction : instructions) {
      function->AddInstruction(move(instruction));
    }
    *instruction = move(function);
  } else if (operation == opcodes::kClassDefinition) {
    auto object = make_unique<ExpressionObject>();
    char method_count;
    char variable_count;
    if (!reader.GetChar(&method_count).Ok()) {
      method_count = 0;
    }
    if (!reader.GetChar(&variable_count).Ok()) {
      variable_count = 0;
    }
    for (int method = 0; method < method_count; method++) {
      char argument_count;
      auto function = make_unique<ExpressionFunction>();
      if (!reader.GetChar(&argument_count).Ok()) {
        argument_count = 0;
      }
      char instruction_count;
      if (!reader.GetChar(&instruction_count).Ok()) {
        instruction_count = 0;
      }
      vector<unique_ptr<Instruction>> instructions;
      for (int i = 0; i < instruction_count; i++) {
        if (!GetInstruction(reader, &instructions, identifier_register,
                            allocator, max_recursion_depth)
                 .Ok()) {
          break;
        }
      }
      for (auto &instruction : instructions) {
        function->AddInstruction(move(instruction));
      }
      string identifier;
      if (allocator->GetId(&identifier).Ok()) {
        function->SetIdentifier(identifier);
        identifier_register->RegisterMethod(identifier);
      }
      object->AddField(identifier, move(function));
    }
    auto status = Status::OkStatus();
    for (int variable = 0; variable < variable_count; variable++) {
      unique_ptr<Expression> value;
      status = GetExpression(reader, &value, allocator, identifier_register,
                             max_recursion_depth);
      string identifier;
      if (!allocator->GetId(&identifier).Ok()) {
        identifier = "something";
      }
      identifier_register->RegisterVariable(identifier);
      object->AddField(identifier, move(value));
      if (!status.Ok()) {
        break;
      }
    }
    *instruction = move(object);
  } else if (operation == opcodes::kFunctionApplication) {
    // In JS the number of arguments is not verified - you can call a function
    // with more, or less arguments than what is declared.
    auto application = make_unique<ExpressionFunctionApplication>();
    char function_number;
    if (!reader.GetChar(&function_number).Ok()) {
      function_number = 0;
    }
    string identifier;
    if (!identifier_register->GetFunction(function_number, &identifier).Ok()) {
      identifier = "something";
    }
    application->SetId(identifier);
    char argument_count;
    if (!reader.GetChar(&argument_count).Ok()) {
      argument_count = 0;
    }
    auto status = Status::OkStatus();
    for (int argument = 0; argument < argument_count; argument++) {
      unique_ptr<Expression> expression;
      status = GetExpression(reader, &expression, allocator,
                             identifier_register, max_recursion_depth);
      application->AddArgument(move(expression));
      if (!status.Ok()) {
        break;
      }
    }
    *instruction = move(application);
    return status;
  } else if (operation == opcodes::kMethodApplication) {
    // Simmilarly to function applications, number of arguments in method
    // applications is not verified.
    auto application = make_unique<ExpressionMethodCall>();
    char method_number;
    if (!reader.GetChar(&method_number).Ok()) {
      method_number = 0;
    }
    string identifier;
    if (!identifier_register->GetMethod(method_number, &identifier).Ok()) {
      identifier = "something";
    }
    application->SetMethodId(identifier);
    char object_number;
    if (!reader.GetChar(&object_number).Ok()) {
      object_number = 0;
    }
    if (!identifier_register->GetVariable(object_number, &identifier).Ok()) {
      identifier = "something";
    }
    application->SetObjectId(identifier);
    char argument_count;
    auto status = reader.GetChar(&argument_count);
    if (!status.Ok()) {
      argument_count = 0;
    }
    for (int argument = 0; argument < argument_count; argument++) {
      unique_ptr<Expression> expression;
      status = GetExpression(reader, &expression, allocator,
                             identifier_register, max_recursion_depth);
      application->AddArgument(move(expression));
      if (!status.Ok()) {
        break;
      }
    }
    *instruction = move(application);
    return status;
  } else if (operation == opcodes::kNewObject) {
    auto expression_new = make_unique<ExpressionNew>();
    char function_number;
    if (!reader.GetChar(&function_number).Ok()) {
      function_number = 0;
    }
    string identifier;
    if (!identifier_register->GetFunction(function_number, &identifier).Ok()) {
      identifier = "something";
    }
    expression_new->SetType(identifier);
    char argument_count;
    if (!reader.GetChar(&argument_count).Ok()) {
      argument_count = 0;
    }
    auto status = Status::OkStatus();
    for (int argument = 0; argument < argument_count; argument++) {
      unique_ptr<Expression> expression;
      status = GetExpression(reader, &expression, allocator,
                             identifier_register, max_recursion_depth);

      expression_new->AddArgument(move(expression));
      if (!status.Ok()) {
        break;
      }
    }
    *instruction = move(expression_new);
    return status;
  } else if (operation == opcodes::kGetter) {
    auto expression_getter = make_unique<ExpressionGetter>();
    auto expression_function = make_unique<ExpressionFunction>();
    vector<unique_ptr<Instruction>> instructions;
    char instruction_count;
    if (!reader.GetChar(&instruction_count).Ok()) {
      instruction_count = 0;
    }
    for (int instruction = 0; instruction < instruction_count; instruction++) {
      if (!GetInstruction(reader, &instructions, identifier_register, allocator,
                          max_recursion_depth)
               .Ok()) {
        break;
      }
    }
    for (auto &instruction : instructions) {
      expression_function->AddInstruction(move(instruction));
    }
    expression_getter->AddField(move(expression_function));
    *instruction = move(expression_getter);
  } else if (operation == opcodes::kSetter) {
    auto expression_setter = make_unique<ExpressionSetter>();
    auto expression_function = make_unique<ExpressionFunction>();
    vector<unique_ptr<Instruction>> instructions;
    char instruction_count;
    if (!reader.GetChar(&instruction_count).Ok()) {
      instruction_count = 0;
    }
    identifier_register->RegisterVariable("arg0");
    for (int instruction = 0; instruction < instruction_count; instruction++) {
      if (!GetInstruction(reader, &instructions, identifier_register, allocator,
                          max_recursion_depth)
               .Ok()) {
        break;
      }
    }
    expression_function->SetArgumentCount(1);
    for (auto &instruction : instructions) {
      expression_function->AddInstruction(move(instruction));
    }
    expression_setter->AddField(move(expression_function));
    *instruction = move(expression_setter);
  } else if (operation == opcodes::kShortIf) {
    auto short_if = make_unique<ExpressionShortIf>();
    unique_ptr<Expression> condition;
    auto condition_status =
        GetExpression(reader, &condition, allocator, identifier_register,
                      max_recursion_depth);
    unique_ptr<Expression> truthy_expression;
    auto truthy_status =
        GetExpression(reader, &truthy_expression, allocator,
                      identifier_register, max_recursion_depth);
    unique_ptr<Expression> falsy_expression;
    auto falsy_status = GetExpression(reader, &falsy_expression, allocator,
                                      identifier_register, max_recursion_depth);
    short_if->SetCondition(move(condition));
    short_if->SetTrufyExpression(move(truthy_expression));
    short_if->SetFalsyExpression(move(falsy_expression));
    *instruction = move(short_if);
    return falsy_status;
  } else if (operation == opcodes::kLambda) {
    auto lambda = make_unique<ExpressionLambda>();
    char arguments_count;
    if (!reader.GetChar(&arguments_count).Ok()) {
      arguments_count = 0;
    }
    lambda->SetArgumentCount(arguments_count);
    for (int i = 0; i < arguments_count; i++) {
      identifier_register->RegisterVariable("arg" + to_string(i));
    }
    char instruction_count;
    if (!reader.GetChar(&instruction_count).Ok()) {
      instruction_count = 0;
    }
    vector<unique_ptr<Instruction>> instructions;
    for (int i = 0; i < instruction_count; i++) {
      if (!GetInstruction(reader, &instructions, identifier_register, allocator,
                          max_recursion_depth)
               .Ok()) {
        break;
      }
    }
    for (auto &instruction : instructions) {
      lambda->AddInstruction(move(instruction));
    }
    *instruction = move(lambda);
  } else {
    // This should never happen - it indicates an error in either grammar
    // or this function.
    return Status::Error("Unknown operation: " + operation);
  }
  return Status::OkStatus();
}

Status Parser::GetBinaryOperatorOperands(
    ExpressionArithmetic *expression, Reader &reader,
    VariableIdAllocator *allocator, IdentifierRegister *identifier_register,
    int max_recursion_depth) const {
  unique_ptr<Expression> lhs;
  auto lhs_status = GetExpression(reader, &lhs, allocator, identifier_register,
                                  max_recursion_depth);
  unique_ptr<Expression> rhs;
  auto rhs_status = GetExpression(reader, &rhs, allocator, identifier_register,
                                  max_recursion_depth);
  expression->SetLhs(move(lhs));
  expression->SetRhs(move(rhs));
  return rhs_status;
}

Status Parser::GetVariablePPID(Reader &reader,
                               IdentifierRegister *identifier_register,
                               ExpressionPPID *ppid) const {
  char variable_number;
  string identifier;
  if (!reader.GetChar(&variable_number).Ok()) {
    variable_number = 0;
  }
  auto status = identifier_register->GetVariable(variable_number, &identifier);
  if (!status.Ok()) {
    identifier = "something";
  }
  ppid->SetId(identifier);
  return status;
}

Status Parser::GetAssignmentOperands(IdentifierRegister *identifier_register,
                                     ExpressionAssignment *assignment,
                                     Reader &reader,
                                     VariableIdAllocator *allocator,
                                     int max_recursion_depth) const {
  auto variable = make_unique<ExpressionVariable>();
  char to_read;
  if (!reader.GetChar(&to_read).Ok()) {
    to_read = 0;
  }
  string identifier;
  if (!identifier_register->GetVariable(to_read, &identifier).Ok()) {
    identifier = "something";
  }
  variable->SetId(identifier);
  unique_ptr<Expression> expression;
  auto expression_status = GetExpression(
      reader, &expression, allocator, identifier_register, max_recursion_depth);
  assignment->SetVariable(move(variable));
  assignment->SetExpression(move(expression));
  return expression_status;
}

Status Parser::CorruptStatement(Reader &reader,
                                unique_ptr<Instruction> *instruction) const {
  if (!pure_run_) {
    char to_read;
    if (!reader.GetChar(&to_read).Ok()) {
      to_read = 0;
    }
    (*instruction)->Corrupt(to_read);
  }
  return Status::OkStatus();
}
