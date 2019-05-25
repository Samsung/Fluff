cc_binary(
    name = "fluff",
    srcs = ["fluff.cc"],
    linkopts = ["-lyaml-cpp"],
    deps = [
        ":builtins",
        ":fuzz_target",
        ":identifier_register",
        ":instruction",
        ":javascript_interface",
        ":parser",
        ":reader_file",
        ":status",
    ],
)

cc_library(
    name = "fuzz_target",
    hdrs = ["interfaces/fuzz_target.h"],
    deps = [
    ],
)

cc_library(
    name = "javascript_interface",
    srcs = [
        "interfaces/javascript_interface_chakra.cc",
        "interfaces/javascript_interface_dryrun.cc",
        "interfaces/javascript_interface_espruino.cc",
        "interfaces/javascript_interface_jerryscript.cc",
    ],
    hdrs = ["interfaces/javascript_interface.h"],
    deps = [
        ":fuzz_target",
        ":instruction",
    ],
)

cc_library(
    name = "status",
    srcs = ["utils/status.cc"],
    hdrs = ["utils/status.h"],
)

cc_library(
    name = "reader",
    hdrs = ["utils/reader.h"],
    deps = [
        ":status",
    ],
)

cc_library(
    name = "reader_file",
    srcs = ["utils/reader_file.cc"],
    hdrs = ["utils/reader_file.h"],
    linkopts = ["-lyaml-cpp"],
    deps = [
        ":reader",
    ],
)

cc_library(
    name = "reader_mock",
    hdrs = ["tests/reader_mock.h"],
)

cc_library(
    name = "variable_id_allocator",
    hdrs = ["utils/variable_id_allocator.h"],
    deps = [
        ":status",
    ],
)

cc_library(
    name = "variable_id_allocator_impl",
    srcs = ["utils/variable_id_allocator_impl.cc"],
    hdrs = ["utils/variable_id_allocator_impl.h"],
    deps = [
        ":status",
        ":variable_id_allocator",
    ],
)

cc_library(
    name = "identifier_register",
    srcs = ["utils/identifier_register.cc"],
    hdrs = ["utils/identifier_register.h"],
    deps = [
        ":status",
    ],
)

cc_library(
    name = "variable_id_allocator_mock",
    hdrs = ["tests/variable_id_allocator_mock.h"],
    deps = [
        ":variable_id_allocator",
    ],
)

cc_library(
    name = "parser",
    srcs = ["utils/parser.cc"],
    hdrs = ["utils/parser.h"],
    deps = [
        ":expression",
        ":identifier_register",
        ":instruction",
        ":parser_opcodes_util",
        ":expression_ppid",
        ":reader",
        ":status",
        ":variable_id_allocator",
        ":variable_id_allocator_impl",
    ],
)

cc_library(
    name = "instruction",
    hdrs = ["statements/instruction.h"],
)

cc_library(
    name = "instruction_mock",
    hdrs = ["tests/instruction_mock.h"],
    deps = [
        ":instruction",
    ],
)

cc_library(
    name = "expression",
    hdrs = ["statements/expression.h"],
    deps = [
        ":instruction",
    ],
)

cc_library(
    name = "instruction_definition",
    srcs = ["statements/instruction_definition.cc"],
    hdrs = ["statements/instruction_definition.h"],
    deps = [
        ":expression",
        ":expression_literal",
        ":instruction",
        ":status",
        ":variable_id_allocator",
    ],
)

cc_library(
    name = "instruction_var",
    srcs = ["statements/instruction_var.cc"],
    hdrs = ["statements/instruction_var.h"],
    deps = [
        ":instruction_definition",
    ],
)

cc_library(
    name = "instruction_let",
    srcs = ["statements/instruction_let.cc"],
    hdrs = ["statements/instruction_let.h"],
    deps = [
        ":instruction_definition",
    ],
)

cc_library(
    name = "instruction_const",
    srcs = ["statements/instruction_const.cc"],
    hdrs = ["statements/instruction_const.h"],
    deps = [
        ":instruction_definition",
    ],
)

cc_library(
    name = "expression_function",
    srcs = ["statements/expression_function.cc"],
    hdrs = ["statements/expression_function.h"],
    deps = [
        ":expression",
        ":instruction",
    ],
)

cc_library(
    name = "instruction_break",
    srcs = ["statements/instruction_break.cc"],
    hdrs = ["statements/instruction_break.h"],
    deps = [
        ":instruction",
    ],
)

cc_library(
    name = "instruction_continue",
    srcs = ["statements/instruction_continue.cc"],
    hdrs = ["statements/instruction_continue.h"],
    deps = [
        ":instruction",
    ],
)

cc_library(
    name = "instruction_return",
    srcs = ["statements/instruction_return.cc"],
    hdrs = ["statements/instruction_return.h"],
    deps = [
        ":expression",
        ":instruction",
    ],
)

cc_library(
    name = "instruction_while",
    srcs = ["statements/instruction_while.cc"],
    hdrs = ["statements/instruction_while.h"],
    deps = [
        ":expression",
        ":expression_literal",
        ":instruction",
    ],
)

cc_library(
    name = "instruction_try_catch_finally",
    srcs = ["statements/instruction_try_catch_finally.cc"],
    hdrs = ["statements/instruction_try_catch_finally.h"],
    deps = [
        ":instruction",
    ],
)

cc_library(
    name = "instruction_if",
    srcs = ["statements/instruction_if.cc"],
    hdrs = ["statements/instruction_if.h"],
    deps = [
        ":expression",
        ":expression_literal",
        ":instruction",
    ],
)

cc_library(
    name = "instruction_if_else",
    srcs = ["statements/instruction_if_else.cc"],
    hdrs = ["statements/instruction_if_else.h"],
    deps = [
        ":expression",
        ":expression_literal",
        ":instruction",
    ],
)

cc_library(
    name = "instruction_for",
    srcs = ["statements/instruction_for.cc"],
    hdrs = ["statements/instruction_for.h"],
    deps = [
        ":expression",
        ":instruction",
    ],
)

cc_library(
    name = "expression_arithmetic",
    srcs = ["statements/expression_arithmetic.cc"],
    hdrs = ["statements/expression_arithmetic.h"],
    deps = [
        ":expression",
        ":expression_literal",
    ],
)

cc_library(
    name = "expression_literal",
    srcs = ["statements/expression_literal.cc"],
    hdrs = ["statements/expression_literal.h"],
    deps = [
        ":expression",
    ],
)

cc_library(
    name = "expression_object",
    srcs = ["statements/expression_object.cc"],
    hdrs = ["statements/expression_object.h"],
    deps = [
        ":expression",
    ],
)

cc_library(
    name = "expression_method_call",
    srcs = ["statements/expression_method_call.cc"],
    hdrs = ["statements/expression_method_call.h"],
    deps = [
        ":expression",
    ],
)

cc_library(
    name = "expression_function_application",
    srcs = ["statements/expression_function_application.cc"],
    hdrs = ["statements/expression_function_application.h"],
    deps = [
        ":expression",
    ],
)

cc_library(
    name = "expression_new",
    srcs = ["statements/expression_new.cc"],
    hdrs = ["statements/expression_new.h"],
    deps = [
        ":expression",
    ],
)

cc_library(
    name = "expression_equals",
    srcs = ["statements/expression_equals.cc"],
    hdrs = ["statements/expression_equals.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_not_equals",
    srcs = ["statements/expression_not_equals.cc"],
    hdrs = ["statements/expression_not_equals.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_equals_type",
    srcs = ["statements/expression_equals_type.cc"],
    hdrs = ["statements/expression_equals_type.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_not_equals_type",
    srcs = ["statements/expression_not_equals_type.cc"],
    hdrs = ["statements/expression_not_equals_type.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_greater",
    srcs = ["statements/expression_greater.cc"],
    hdrs = ["statements/expression_greater.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_greater_equal",
    srcs = ["statements/expression_greater_equal.cc"],
    hdrs = ["statements/expression_greater_equal.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_smaller",
    srcs = ["statements/expression_smaller.cc"],
    hdrs = ["statements/expression_smaller.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_smaller_equal",
    srcs = ["statements/expression_smaller_equal.cc"],
    hdrs = ["statements/expression_smaller_equal.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_addition",
    srcs = ["statements/expression_addition.cc"],
    hdrs = ["statements/expression_addition.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_subtraction",
    srcs = ["statements/expression_subtraction.cc"],
    hdrs = ["statements/expression_subtraction.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_multiplication",
    srcs = ["statements/expression_multiplication.cc"],
    hdrs = ["statements/expression_multiplication.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_division",
    srcs = ["statements/expression_division.cc"],
    hdrs = ["statements/expression_division.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_right_shift_signed",
    srcs = ["statements/expression_right_shift_signed.cc"],
    hdrs = ["statements/expression_right_shift_signed.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_right_shift_unsigned",
    srcs = ["statements/expression_right_shift_unsigned.cc"],
    hdrs = ["statements/expression_right_shift_unsigned.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_left_shift",
    srcs = ["statements/expression_left_shift.cc"],
    hdrs = ["statements/expression_left_shift.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_modulo",
    srcs = ["statements/expression_modulo.cc"],
    hdrs = ["statements/expression_modulo.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_bitwise_or",
    srcs = ["statements/expression_bitwise_or.cc"],
    hdrs = ["statements/expression_bitwise_or.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_bitwise_and",
    srcs = ["statements/expression_bitwise_and.cc"],
    hdrs = ["statements/expression_bitwise_and.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_bitwise_xor",
    srcs = ["statements/expression_bitwise_xor.cc"],
    hdrs = ["statements/expression_bitwise_xor.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_logical_and",
    srcs = ["statements/expression_logical_and.cc"],
    hdrs = ["statements/expression_logical_and.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_logical_or",
    srcs = ["statements/expression_logical_or.cc"],
    hdrs = ["statements/expression_logical_or.h"],
    deps = [
        ":expression_arithmetic",
    ],
)

cc_library(
    name = "expression_variable",
    srcs = ["statements/expression_variable.cc"],
    hdrs = ["statements/expression_variable.h"],
    deps = [
        ":expression",
    ],
)

cc_library(
    name = "expression_unary",
    srcs = ["statements/expression_unary.cc"],
    hdrs = ["statements/expression_unary.h"],
    deps = [
        ":expression",
        ":expression_literal",
    ],
)

cc_library(
    name = "expression_not",
    srcs = ["statements/expression_not.cc"],
    hdrs = ["statements/expression_not.h"],
    deps = [
        ":expression_unary",
    ],
)

cc_library(
    name = "expression_ppid",
    srcs = ["statements/expression_ppid.cc"],
    hdrs = ["statements/expression_ppid.h"],
    deps = [
        ":expression"
    ],
)

cc_library(
    name = "expression_preincrement",
    srcs = ["statements/expression_preincrement.cc"],
    hdrs = ["statements/expression_preincrement.h"],
    deps = [
        ":expression_ppid",
    ],
)

cc_library(
    name = "expression_postincrement",
    srcs = ["statements/expression_postincrement.cc"],
    hdrs = ["statements/expression_postincrement.h"],
    deps = [
        ":expression_ppid",
    ],
)

cc_library(
    name = "expression_predecrement",
    srcs = ["statements/expression_predecrement.cc"],
    hdrs = ["statements/expression_predecrement.h"],
    deps = [
        ":expression_ppid",
    ],
)

cc_library(
    name = "expression_postdecrement",
    srcs = ["statements/expression_postdecrement.cc"],
    hdrs = ["statements/expression_postdecrement.h"],
    deps = [
        ":expression_ppid",
    ],
)

cc_library(
    name = "expression_class_field_access_dot",
    srcs = ["statements/expression_class_field_access_dot.cc"],
    hdrs = ["statements/expression_class_field_access_dot.h"],
    deps = [
        ":expression_unary",
    ],
)

cc_library(
    name = "expression_class_field_access_bracket",
    srcs = ["statements/expression_class_field_access_bracket.cc"],
    hdrs = ["statements/expression_class_field_access_bracket.h"],
    deps = [
        ":expression_unary",
    ],
)

cc_library(
    name = "expression_assignment",
    srcs = ["statements/expression_assignment.cc"],
    hdrs = ["statements/expression_assignment.h"],
    deps = [
        ":expression",
        ":expression_literal",
        ":expression_variable",
    ],
)

cc_library(
    name = "expression_assignment_simple",
    srcs = ["statements/expression_assignment_simple.cc"],
    hdrs = ["statements/expression_assignment_simple.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_assignment_add",
    srcs = ["statements/expression_assignment_add.cc"],
    hdrs = ["statements/expression_assignment_add.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_assignment_subtract",
    srcs = ["statements/expression_assignment_subtract.cc"],
    hdrs = ["statements/expression_assignment_subtract.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_assignment_multiply",
    srcs = ["statements/expression_assignment_multiply.cc"],
    hdrs = ["statements/expression_assignment_multiply.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_assignment_divide",
    srcs = ["statements/expression_assignment_divide.cc"],
    hdrs = ["statements/expression_assignment_divide.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_assignment_modulo",
    srcs = ["statements/expression_assignment_modulo.cc"],
    hdrs = ["statements/expression_assignment_modulo.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_assignment_left_shift",
    srcs = ["statements/expression_assignment_left_shift.cc"],
    hdrs = ["statements/expression_assignment_left_shift.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_assignment_right_shift_unsigned",
    srcs = ["statements/expression_assignment_right_shift_unsigned.cc"],
    hdrs = ["statements/expression_assignment_right_shift_unsigned.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_assignment_right_shift_signed",
    srcs = ["statements/expression_assignment_right_shift_signed.cc"],
    hdrs = ["statements/expression_assignment_right_shift_signed.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_assignment_bitwise_and",
    srcs = ["statements/expression_assignment_bitwise_and.cc"],
    hdrs = ["statements/expression_assignment_bitwise_and.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_assignment_bitwise_xor",
    srcs = ["statements/expression_assignment_bitwise_xor.cc"],
    hdrs = ["statements/expression_assignment_bitwise_xor.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_assignment_bitwise_or",
    srcs = ["statements/expression_assignment_bitwise_or.cc"],
    hdrs = ["statements/expression_assignment_bitwise_or.h"],
    deps = [
        ":expression_assignment",
    ],
)

cc_library(
    name = "expression_getter",
    srcs = ["statements/expression_getter.cc"],
    hdrs = ["statements/expression_getter.h"],
    deps = [
        ":expression_function",
    ],
)

cc_library(
    name = "expression_function_mock",
    hdrs = ["tests/expression_function_mock.h"],
)

cc_library(
    name = "expression_short_if",
    srcs = ["statements/expression_short_if.cc"],
    hdrs = ["statements/expression_short_if.h"],
    deps = [
        ":expression",
        ":expression_literal",
    ],
)

cc_library(
    name = "expression_setter",
    srcs = ["statements/expression_setter.cc"],
    hdrs = ["statements/expression_setter.h"],
    deps = [
        ":expression_function",
    ],
)

cc_library(
    name = "expression_lambda",
    srcs = ["statements/expression_lambda.cc"],
    hdrs = ["statements/expression_lambda.h"],
    deps = [
        ":expression",
    ],
)

cc_library(
    name = "builtins",
    hdrs = ["interfaces/builtins.h"],
)

cc_library(
    name = "parser_opcodes_util",
    hdrs = ["utils/parser_opcodes_util.h"],
    deps = [
        ":expression_addition",
        ":expression_assignment_add",
        ":expression_assignment_bitwise_and",
        ":expression_assignment_bitwise_or",
        ":expression_assignment_bitwise_xor",
        ":expression_assignment_divide",
        ":expression_assignment_left_shift",
        ":expression_assignment_modulo",
        ":expression_assignment_multiply",
        ":expression_assignment_right_shift_signed",
        ":expression_assignment_right_shift_unsigned",
        ":expression_assignment_simple",
        ":expression_assignment_subtract",
        ":expression_bitwise_and",
        ":expression_bitwise_or",
        ":expression_bitwise_xor",
        ":expression_class_field_access_bracket",
        ":expression_class_field_access_dot",
        ":expression_division",
        ":expression_equals",
        ":expression_equals_type",
        ":expression_function",
        ":expression_function_application",
        ":expression_getter",
        ":expression_greater",
        ":expression_greater_equal",
        ":expression_lambda",
        ":expression_left_shift",
        ":expression_literal",
        ":expression_logical_and",
        ":expression_logical_or",
        ":expression_method_call",
        ":expression_modulo",
        ":expression_multiplication",
        ":expression_new",
        ":expression_not",
        ":expression_not_equals",
        ":expression_not_equals_type",
        ":expression_object",
        ":expression_postdecrement",
        ":expression_postincrement",
        ":expression_predecrement",
        ":expression_preincrement",
        ":expression_right_shift_signed",
        ":expression_right_shift_unsigned",
        ":expression_setter",
        ":expression_short_if",
        ":expression_smaller",
        ":expression_smaller_equal",
        ":expression_subtraction",
        ":expression_variable",
        ":instruction_break",
        ":instruction_const",
        ":instruction_continue",
        ":instruction_for",
        ":instruction_if",
        ":instruction_if_else",
        ":instruction_let",
        ":instruction_return",
        ":instruction_try_catch_finally",
        ":instruction_var",
        ":instruction_while",
    ],
)

cc_test(
    name = "reader_file_test",
    size = "small",
    srcs = ["tests/reader_file_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lyaml-cpp",
        "-lpthread",
    ],
    deps = [
        ":reader_file",
    ],
)

cc_test(
    name = "status_test",
    size = "small",
    srcs = ["tests/status_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        ":status",
    ],
)

cc_test(
    name = "variable_id_allocator_impl_test",
    size = "small",
    srcs = ["tests/variable_id_allocator_impl_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        ":status",
        ":variable_id_allocator_impl",
    ],
)

cc_test(
    name = "expression_literal_test",
    size = "small",
    srcs = ["tests/expression_literal_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        ":expression_literal",
    ],
)

cc_test(
    name = "expression_arithmetic_test",
    size = "small",
    srcs = ["tests/expression_arithmetic_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        ":expression_addition",
        ":expression_bitwise_and",
        ":expression_bitwise_or",
        ":expression_bitwise_xor",
        ":expression_division",
        ":expression_equals",
        ":expression_equals_type",
        ":expression_greater",
        ":expression_greater_equal",
        ":expression_left_shift",
        ":expression_literal",
        ":expression_logical_and",
        ":expression_logical_or",
        ":expression_modulo",
        ":expression_multiplication",
        ":expression_not_equals",
        ":expression_not_equals_type",
        ":expression_right_shift_signed",
        ":expression_right_shift_unsigned",
        ":expression_smaller",
        ":expression_smaller_equal",
        ":expression_subtraction",
    ],
)

cc_test(
    name = "expression_unary_test",
    size = "small",
    srcs = ["tests/expression_unary_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        ":expression_class_field_access_bracket",
        ":expression_class_field_access_dot",
        ":expression_literal",
        ":expression_not"
    ],
)

cc_test(
    name = "expression_ppid_test",
    size = "small",
    srcs = ["tests/expression_ppid_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        ":expression_preincrement",
        ":expression_postincrement",
        ":expression_predecrement",
        ":expression_postdecrement"
    ],
)


cc_test(
    name = "expression_new_test",
    size = "small",
    srcs = ["tests/expression_new_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        ":expression_literal",
        ":expression_new",
    ],
)

cc_test(
    name = "expression_variable_test",
    size = "small",
    srcs = ["tests/expression_variable_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        "expression_variable",
    ],
)

cc_test(
    name = "parser_test",
    size = "small",
    srcs = ["tests/parser_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
        "-lyaml-cpp",
    ],
    deps = [
        ":expression_addition",
        ":expression_literal",
        ":identifier_register",
        ":instruction",
        ":parser",
        ":reader_mock",
        ":status",
    ],
)

cc_test(
    name = "instruction_definition_test",
    size = "small",
    srcs = ["tests/instruction_definition_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_addition",
        ":expression_literal",
        ":instruction_const",
        ":instruction_let",
        ":instruction_var",
        ":status",
        ":variable_id_allocator_mock",
    ],
)

cc_test(
    name = "instruction_while_test",
    size = "small",
    srcs = ["tests/instruction_while_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_literal",
        ":instruction_while",
    ],
)

cc_test(
    name = "instruction_try_catch_finally_test",
    size = "small",
    srcs = ["tests/instruction_try_catch_finally_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_literal",
        ":instruction_try_catch_finally",
    ],
)

cc_test(
    name = "instruction_if_test",
    size = "small",
    srcs = ["tests/instruction_if_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_literal",
        ":instruction_if",
    ],
)

cc_test(
    name = "instruction_if_else_test",
    size = "small",
    srcs = ["tests/instruction_if_else_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_literal",
        ":instruction_if_else",
    ],
)

cc_test(
    name = "instruction_for_test",
    size = "small",
    srcs = ["tests/instruction_for_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_literal",
        ":instruction_for",
        ":instruction_mock",
    ],
)

cc_test(
    name = "expression_function_test",
    size = "small",
    srcs = ["tests/expression_function_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_function",
        ":instruction_mock",
    ],
)

cc_test(
    name = "expression_function_application_test",
    size = "small",
    srcs = ["tests/expression_function_application_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_function_application",
        ":expression_literal",
    ],
)

cc_test(
    name = "expression_assignment_test",
    size = "small",
    srcs = ["tests/expression_assignment_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression",
        ":expression_assignment_add",
        ":expression_assignment_bitwise_and",
        ":expression_assignment_bitwise_or",
        ":expression_assignment_bitwise_xor",
        ":expression_assignment_divide",
        ":expression_assignment_left_shift",
        ":expression_assignment_modulo",
        ":expression_assignment_multiply",
        ":expression_assignment_right_shift_signed",
        ":expression_assignment_right_shift_unsigned",
        ":expression_assignment_simple",
        ":expression_assignment_subtract",
        ":expression_literal",
        ":expression_variable",
        ":status",
    ],
)

cc_test(
    name = "expression_object_test",
    size = "small",
    srcs = ["tests/expression_object_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_literal",
        ":expression_object",
    ],
)

cc_test(
    name = "expression_method_call_test",
    size = "small",
    srcs = ["tests/expression_method_call_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_literal",
        ":expression_method_call",
    ],
)

cc_test(
    name = "instruction_break_test",
    size = "small",
    srcs = ["tests/instruction_break_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":instruction_break",
    ],
)

cc_test(
    name = "instruction_continue_test",
    size = "small",
    srcs = ["tests/instruction_continue_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":instruction_continue",
    ],
)

cc_test(
    name = "instruction_return_test",
    size = "small",
    srcs = ["tests/instruction_return_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_literal",
        ":instruction_return",
    ],
)

cc_test(
    name = "identifier_register_test",
    size = "small",
    srcs = ["tests/identifier_register_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":identifier_register",
    ],
)

cc_test(
    name = "expression_getter_test",
    size = "small",
    srcs = ["tests/expression_getter_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_function_mock",
        ":expression_getter",
    ],
)

cc_test(
    name = "expression_setter_test",
    size = "small",
    srcs = ["tests/expression_setter_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_function_mock",
        ":expression_setter",
    ],
)

cc_test(
    name = "expression_short_if_test",
    size = "small",
    srcs = ["tests/expression_short_if_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_literal",
        ":expression_short_if",
    ],
)

cc_test(
    name = "expression_lambda_test",
    size = "small",
    srcs = ["tests/expression_lambda_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_lambda",
        ":instruction_mock",
    ],
)
