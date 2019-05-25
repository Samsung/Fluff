cc_library(
    name = "instruction",
    hdrs = ["instruction.h"],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "expression",
    hdrs = ["expression.h"],
    deps = [
        ":instruction",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_definition",
    srcs = ["instruction_definition.cc"],
    hdrs = ["instruction_definition.h"],
    deps = [
        ":expression",
        ":expression_literal",
        ":instruction",
        "//utils:status",
        "//utils:variable_id_allocator",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_var",
    srcs = ["instruction_var.cc"],
    hdrs = ["instruction_var.h"],
    deps = [
        ":instruction_definition",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_let",
    srcs = ["instruction_let.cc"],
    hdrs = ["instruction_let.h"],
    deps = [
        ":instruction_definition",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_const",
    srcs = ["instruction_const.cc"],
    hdrs = ["instruction_const.h"],
    deps = [
        ":instruction_definition",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_function",
    srcs = ["expression_function.cc"],
    hdrs = ["expression_function.h"],
    deps = [
        ":expression",
        ":instruction",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_break",
    srcs = ["instruction_break.cc"],
    hdrs = ["instruction_break.h"],
    deps = [
        ":instruction",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_continue",
    srcs = ["instruction_continue.cc"],
    hdrs = ["instruction_continue.h"],
    deps = [
        ":instruction",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_return",
    srcs = ["instruction_return.cc"],
    hdrs = ["instruction_return.h"],
    deps = [
        ":expression",
        ":instruction",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_while",
    srcs = ["instruction_while.cc"],
    hdrs = ["instruction_while.h"],
    deps = [
        ":expression",
        ":expression_literal",
        ":instruction",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_try_catch_finally",
    srcs = ["instruction_try_catch_finally.cc"],
    hdrs = ["instruction_try_catch_finally.h"],
    deps = [
        ":instruction",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_if",
    srcs = ["instruction_if.cc"],
    hdrs = ["instruction_if.h"],
    deps = [
        ":expression",
        ":expression_literal",
        ":instruction",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_if_else",
    srcs = ["instruction_if_else.cc"],
    hdrs = ["instruction_if_else.h"],
    deps = [
        ":expression",
        ":expression_literal",
        ":instruction",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "instruction_for",
    srcs = ["instruction_for.cc"],
    hdrs = ["instruction_for.h"],
    deps = [
        ":expression",
        ":instruction",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_arithmetic",
    srcs = ["expression_arithmetic.cc"],
    hdrs = ["expression_arithmetic.h"],
    deps = [
        ":expression",
        ":expression_literal",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_literal",
    srcs = ["expression_literal.cc"],
    hdrs = ["expression_literal.h"],
    deps = [
        ":expression",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_object",
    srcs = ["expression_object.cc"],
    hdrs = ["expression_object.h"],
    deps = [
        ":expression",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_method_call",
    srcs = ["expression_method_call.cc"],
    hdrs = ["expression_method_call.h"],
    deps = [
        ":expression",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_function_application",
    srcs = ["expression_function_application.cc"],
    hdrs = ["expression_function_application.h"],
    deps = [
        ":expression",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_new",
    srcs = ["expression_new.cc"],
    hdrs = ["expression_new.h"],
    deps = [
        ":expression",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_equals",
    srcs = ["expression_equals.cc"],
    hdrs = ["expression_equals.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_not_equals",
    srcs = ["expression_not_equals.cc"],
    hdrs = ["expression_not_equals.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_equals_type",
    srcs = ["expression_equals_type.cc"],
    hdrs = ["expression_equals_type.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_not_equals_type",
    srcs = ["expression_not_equals_type.cc"],
    hdrs = ["expression_not_equals_type.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_greater",
    srcs = ["expression_greater.cc"],
    hdrs = ["expression_greater.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_greater_equal",
    srcs = ["expression_greater_equal.cc"],
    hdrs = ["expression_greater_equal.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_smaller",
    srcs = ["expression_smaller.cc"],
    hdrs = ["expression_smaller.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_smaller_equal",
    srcs = ["expression_smaller_equal.cc"],
    hdrs = ["expression_smaller_equal.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_addition",
    srcs = ["expression_addition.cc"],
    hdrs = ["expression_addition.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_subtraction",
    srcs = ["expression_subtraction.cc"],
    hdrs = ["expression_subtraction.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_multiplication",
    srcs = ["expression_multiplication.cc"],
    hdrs = ["expression_multiplication.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_division",
    srcs = ["expression_division.cc"],
    hdrs = ["expression_division.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_right_shift_signed",
    srcs = ["expression_right_shift_signed.cc"],
    hdrs = ["expression_right_shift_signed.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_right_shift_unsigned",
    srcs = ["expression_right_shift_unsigned.cc"],
    hdrs = ["expression_right_shift_unsigned.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_left_shift",
    srcs = ["expression_left_shift.cc"],
    hdrs = ["expression_left_shift.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_modulo",
    srcs = ["expression_modulo.cc"],
    hdrs = ["expression_modulo.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_bitwise_or",
    srcs = ["expression_bitwise_or.cc"],
    hdrs = ["expression_bitwise_or.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_bitwise_and",
    srcs = ["expression_bitwise_and.cc"],
    hdrs = ["expression_bitwise_and.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_bitwise_xor",
    srcs = ["expression_bitwise_xor.cc"],
    hdrs = ["expression_bitwise_xor.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_logical_and",
    srcs = ["expression_logical_and.cc"],
    hdrs = ["expression_logical_and.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_logical_or",
    srcs = ["expression_logical_or.cc"],
    hdrs = ["expression_logical_or.h"],
    deps = [
        ":expression_arithmetic",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_variable",
    srcs = ["expression_variable.cc"],
    hdrs = ["expression_variable.h"],
    deps = [
        ":expression",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_unary",
    srcs = ["expression_unary.cc"],
    hdrs = ["expression_unary.h"],
    deps = [
        ":expression",
        ":expression_literal",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_not",
    srcs = ["expression_not.cc"],
    hdrs = ["expression_not.h"],
    deps = [
        ":expression_unary",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_ppid",
    srcs = ["expression_ppid.cc"],
    hdrs = ["expression_ppid.h"],
    deps = [
        ":expression",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_preincrement",
    srcs = ["expression_preincrement.cc"],
    hdrs = ["expression_preincrement.h"],
    deps = [
        ":expression_ppid",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_postincrement",
    srcs = ["expression_postincrement.cc"],
    hdrs = ["expression_postincrement.h"],
    deps = [
        ":expression_ppid",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_predecrement",
    srcs = ["expression_predecrement.cc"],
    hdrs = ["expression_predecrement.h"],
    deps = [
        ":expression_ppid",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_postdecrement",
    srcs = ["expression_postdecrement.cc"],
    hdrs = ["expression_postdecrement.h"],
    deps = [
        ":expression_ppid",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_class_field_access_dot",
    srcs = ["expression_class_field_access_dot.cc"],
    hdrs = ["expression_class_field_access_dot.h"],
    deps = [
        ":expression_unary",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_class_field_access_bracket",
    srcs = ["expression_class_field_access_bracket.cc"],
    hdrs = ["expression_class_field_access_bracket.h"],
    deps = [
        ":expression_unary",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment",
    srcs = ["expression_assignment.cc"],
    hdrs = ["expression_assignment.h"],
    deps = [
        ":expression",
        ":expression_literal",
        ":expression_variable",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_simple",
    srcs = ["expression_assignment_simple.cc"],
    hdrs = ["expression_assignment_simple.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_add",
    srcs = ["expression_assignment_add.cc"],
    hdrs = ["expression_assignment_add.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_subtract",
    srcs = ["expression_assignment_subtract.cc"],
    hdrs = ["expression_assignment_subtract.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_multiply",
    srcs = ["expression_assignment_multiply.cc"],
    hdrs = ["expression_assignment_multiply.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_divide",
    srcs = ["expression_assignment_divide.cc"],
    hdrs = ["expression_assignment_divide.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_modulo",
    srcs = ["expression_assignment_modulo.cc"],
    hdrs = ["expression_assignment_modulo.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_left_shift",
    srcs = ["expression_assignment_left_shift.cc"],
    hdrs = ["expression_assignment_left_shift.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_right_shift_unsigned",
    srcs = ["expression_assignment_right_shift_unsigned.cc"],
    hdrs = ["expression_assignment_right_shift_unsigned.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_right_shift_signed",
    srcs = ["expression_assignment_right_shift_signed.cc"],
    hdrs = ["expression_assignment_right_shift_signed.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_bitwise_and",
    srcs = ["expression_assignment_bitwise_and.cc"],
    hdrs = ["expression_assignment_bitwise_and.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_bitwise_xor",
    srcs = ["expression_assignment_bitwise_xor.cc"],
    hdrs = ["expression_assignment_bitwise_xor.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_assignment_bitwise_or",
    srcs = ["expression_assignment_bitwise_or.cc"],
    hdrs = ["expression_assignment_bitwise_or.h"],
    deps = [
        ":expression_assignment",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_getter",
    srcs = ["expression_getter.cc"],
    hdrs = ["expression_getter.h"],
    deps = [
        ":expression_function",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_short_if",
    srcs = ["expression_short_if.cc"],
    hdrs = ["expression_short_if.h"],
    deps = [
        ":expression",
        ":expression_literal",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_setter",
    srcs = ["expression_setter.cc"],
    hdrs = ["expression_setter.h"],
    deps = [
        ":expression_function",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_lambda",
    srcs = ["expression_lambda.cc"],
    hdrs = ["expression_lambda.h"],
    deps = [
        ":expression",
    ],
    visibility = ["//visibility:public"], 
)
