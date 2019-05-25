#include "statements/expression.h"
#include "statements/expression_addition.h"
#include "statements/expression_arithmetic.h"
#include "statements/expression_assignment.h"
#include "statements/expression_assignment_add.h"
#include "statements/expression_assignment_bitwise_and.h"
#include "statements/expression_assignment_bitwise_or.h"
#include "statements/expression_assignment_bitwise_xor.h"
#include "statements/expression_assignment_divide.h"
#include "statements/expression_assignment_left_shift.h"
#include "statements/expression_assignment_modulo.h"
#include "statements/expression_assignment_multiply.h"
#include "statements/expression_assignment_right_shift_signed.h"
#include "statements/expression_assignment_right_shift_unsigned.h"
#include "statements/expression_assignment_simple.h"
#include "statements/expression_assignment_subtract.h"
#include "statements/expression_bitwise_and.h"
#include "statements/expression_bitwise_or.h"
#include "statements/expression_bitwise_xor.h"
#include "statements/expression_class_field_access_bracket.h"
#include "statements/expression_class_field_access_dot.h"
#include "statements/expression_division.h"
#include "statements/expression_equals.h"
#include "statements/expression_equals_type.h"
#include "statements/expression_function.h"
#include "statements/expression_function_application.h"
#include "statements/expression_getter.h"
#include "statements/expression_greater.h"
#include "statements/expression_greater_equal.h"
#include "statements/expression_lambda.h"
#include "statements/expression_left_shift.h"
#include "statements/expression_literal.h"
#include "statements/expression_logical_and.h"
#include "statements/expression_logical_or.h"
#include "statements/expression_method_call.h"
#include "statements/expression_modulo.h"
#include "statements/expression_multiplication.h"
#include "statements/expression_new.h"
#include "statements/expression_not.h"
#include "statements/expression_not_equals.h"
#include "statements/expression_not_equals_type.h"
#include "statements/expression_object.h"
#include "statements/expression_postdecrement.h"
#include "statements/expression_postincrement.h"
#include "statements/expression_predecrement.h"
#include "statements/expression_preincrement.h"
#include "statements/expression_right_shift_signed.h"
#include "statements/expression_right_shift_unsigned.h"
#include "statements/expression_setter.h"
#include "statements/expression_short_if.h"
#include "statements/expression_smaller.h"
#include "statements/expression_smaller_equal.h"
#include "statements/expression_subtraction.h"
#include "statements/expression_unary.h"
#include "statements/expression_variable.h"
#include "statements/instruction.h"
#include "statements/instruction_break.h"
#include "statements/instruction_const.h"
#include "statements/instruction_continue.h"
#include "statements/instruction_definition.h"
#include "statements/instruction_for.h"
#include "statements/instruction_if.h"
#include "statements/instruction_if_else.h"
#include "statements/instruction_let.h"
#include "statements/instruction_return.h"
#include "statements/instruction_try_catch_finally.h"
#include "statements/instruction_var.h"
#include "statements/instruction_while.h"

namespace opcodes {

constexpr char kWhile[] = "LoopWhile";
constexpr char kFor[] = "LoopFor";
constexpr char kIf[] = "ConditionalIf";
constexpr char kIfElse[] = "ConditionalIfElse";
constexpr char kVariableDeclaration[] = "VariableDeclaration";
constexpr char kLetDeclaration[] = "LetDeclaration";
constexpr char kConstDeclaration[] = "ConstDeclaration";
constexpr char kReturn[] = "Return";
constexpr char kBreak[] = "Break";
constexpr char kContinue[] = "Continue";
constexpr char kAddition[] = "Addition";
constexpr char kSubtraction[] = "Subtraction";
constexpr char kMultiplication[] = "Multiplication";
constexpr char kDivision[] = "Division";
constexpr char kModulo[] = "Modulo";
constexpr char kVariable[] = "Variable";
constexpr char kLeftShift[] = "LeftShift";
constexpr char kRightShiftSigned[] = "RightShiftSigned";
constexpr char kRightShiftUnsigned[] = "RightShiftUnsigned";
constexpr char kBitwiseOr[] = "BitwiseOr";
constexpr char kBitwiseXor[] = "BitwiseXor";
constexpr char kBitwiseAnd[] = "BitwiseAnd";
constexpr char kLogicalOr[] = "LogicalOr";
constexpr char kLogicalAnd[] = "LogicalAnd";
constexpr char kLogicalNot[] = "LogicalNot";
constexpr char kVariableAssignment[] = "SimpleAssign";
constexpr char kVariableAssignmentAdd[] = "AddAssign";
constexpr char kVariableAssignmentSub[] = "SubAssign";
constexpr char kVariableAssignmentMul[] = "MulAssign";
constexpr char kVariableAssignmentDiv[] = "DivAssign";
constexpr char kVariableAssignmentMod[] = "ModAssign";
constexpr char kVariableAssignmentLeftShift[] = "LeftShiftAssign";
constexpr char kVariableAssignmentRightShiftSigned[] = "RightShiftSignedAssign";
constexpr char kVariableAssignmentRightShiftUnsigned[] =
    "RightShiftUnsignedAssign";
constexpr char kVariableAssignmentBitwiseOr[] = "BitwiseOrAssign";
constexpr char kVariableAssignmentBitwiseAnd[] = "BitwiseAndAssign";
constexpr char kVariableAssignmentBitwiseXor[] = "BitwiseXorAssign";
constexpr char kFunctionApplication[] = "FunctionApplication";
constexpr char kMethodApplication[] = "MethodApplication";
constexpr char kClassFieldDotAccess[] = "ClassFieldDotAccess";
constexpr char kClassFieldBracketAccess[] = "ClassFieldBracketAccess";
constexpr char kPreIncrement[] = "PreIncrement";
constexpr char kPostIncrement[] = "PostIncrement";
constexpr char kPreDecrement[] = "PreDecrement";
constexpr char kPostDecrement[] = "PostDecrement";
constexpr char kFunctionDefinition[] = "FunctionDefinition";
constexpr char kClassDefinition[] = "ClassDefinition";
constexpr char kGreater[] = "Greater";
constexpr char kSmaller[] = "Smaller";
constexpr char kGreaterEqual[] = "GreaterEqual";
constexpr char kSmallerEqual[] = "SmallerEqual";
constexpr char kEqual[] = "Equal";
constexpr char kNotEqual[] = "NotEqual";
constexpr char kEqualType[] = "EqualType";
constexpr char kNotEqualType[] = "NotEqualType";
constexpr char kInteger[] = "Integer";
constexpr char kReal[] = "Real";
constexpr char kBoolean[] = "Boolean";
constexpr char kString[] = "String";
constexpr char kNull[] = "ENull";
constexpr char kSimpleArray[] = "SimpleArray";
constexpr char kNewObject[] = "NewObject";
constexpr char kTryCatchFinally[] = "TryCatchFinally";
constexpr char kGetter[] = "Getter";
constexpr char kSetter[] = "Setter";
constexpr char kShortIf[] = "ShortIf";
constexpr char kLambda[] = "Lambda";

}  // namespace opcodes
