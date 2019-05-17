cc_test(
    name = "reader_file_test",
    size = "small",
    srcs = ["reader_file_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lyaml-cpp",
        "-lpthread",
    ],
    deps = [
        "//utils:reader_file",
    ],
)

cc_library(
    name = "variable_id_allocator_mock",
    hdrs = ["variable_id_allocator_mock.h"],
    deps = [
        "//utils:variable_id_allocator",
    ],
)

cc_library(
    name = "reader_mock",
    hdrs = ["reader_mock.h"],
)

cc_test(
    name = "status_test",
    size = "small",
    srcs = ["status_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        "//utils:status",
    ],
)

cc_test(
    name = "variable_id_allocator_impl_test",
    size = "small",
    srcs = ["variable_id_allocator_impl_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        "//utils:status",
        "//utils:variable_id_allocator_impl",
    ],
)

cc_test(
    name = "expression_literal_test",
    size = "small",
    srcs = ["expression_literal_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_literal",
    ],
)

cc_test(
    name = "expression_arithmetic_test",
    size = "small",
    srcs = ["expression_arithmetic_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_addition",
        "//statements:expression_bitwise_and",
        "//statements:expression_bitwise_or",
        "//statements:expression_bitwise_xor",
        "//statements:expression_division",
        "//statements:expression_equals",
        "//statements:expression_equals_type",
        "//statements:expression_greater",
        "//statements:expression_greater_equal",
        "//statements:expression_left_shift",
        "//statements:expression_literal",
        "//statements:expression_logical_and",
        "//statements:expression_logical_or",
        "//statements:expression_modulo",
        "//statements:expression_multiplication",
        "//statements:expression_not_equals",
        "//statements:expression_not_equals_type",
        "//statements:expression_right_shift_signed",
        "//statements:expression_right_shift_unsigned",
        "//statements:expression_smaller",
        "//statements:expression_smaller_equal",
        "//statements:expression_subtraction",
    ],
)

cc_test(
    name = "expression_unary_test",
    size = "small",
    srcs = ["expression_unary_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_class_field_access_bracket",
        "//statements:expression_class_field_access_dot",
        "//statements:expression_literal",
        "//statements:expression_not",
    ],
)

cc_test(
    name = "expression_ppid_test",
    size = "small",
    srcs = ["expression_ppid_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_postdecrement",
        "//statements:expression_postincrement",
        "//statements:expression_predecrement",
        "//statements:expression_preincrement",
    ],
)

cc_test(
    name = "expression_new_test",
    size = "small",
    srcs = ["expression_new_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_literal",
        "//statements:expression_new",
    ],
)

cc_test(
    name = "expression_variable_test",
    size = "small",
    srcs = ["expression_variable_test.cc"],
    copts = ["-Iexternal/gtest/include"],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_variable",
    ],
)

cc_test(
    name = "parser_test",
    size = "small",
    srcs = ["parser_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
        "-lyaml-cpp",
    ],
    deps = [
        "//statements:expression_addition",
        "//statements:expression_literal",
        "//utils:identifier_register",
        "//statements:instruction",
        "//utils:parser",
        ":reader_mock",
        "//utils:status",
    ],
)

cc_test(
    name = "instruction_definition_test",
    size = "small",
    srcs = ["instruction_definition_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_addition",
        "//statements:expression_literal",
        "//statements:instruction_const",
        "//statements:instruction_let",
        "//statements:instruction_var",
        "//utils:status",
        ":variable_id_allocator_mock",
    ],
)

cc_test(
    name = "instruction_while_test",
    size = "small",
    srcs = ["instruction_while_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_literal",
        "//statements:instruction_while",
    ],
)

cc_test(
    name = "instruction_try_catch_finally_test",
    size = "small",
    srcs = ["instruction_try_catch_finally_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_literal",
        "//statements:instruction_try_catch_finally",
    ],
)

cc_test(
    name = "instruction_if_test",
    size = "small",
    srcs = ["instruction_if_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_literal",
        "//statements:instruction_if",
    ],
)

cc_test(
    name = "instruction_if_else_test",
    size = "small",
    srcs = ["instruction_if_else_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_literal",
        "//statements:instruction_if_else",
    ],
)

cc_test(
    name = "instruction_for_test",
    size = "small",
    srcs = ["instruction_for_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_literal",
        "//statements:instruction_for",
        ":instruction_mock",
    ],
)

cc_test(
    name = "expression_function_test",
    size = "small",
    srcs = ["expression_function_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_function",
        ":instruction_mock",
    ],
)

cc_test(
    name = "expression_function_application_test",
    size = "small",
    srcs = ["expression_function_application_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_function_application",
        "//statements:expression_literal",
    ],
)

cc_test(
    name = "expression_assignment_test",
    size = "small",
    srcs = ["expression_assignment_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression",
        "//statements:expression_assignment_add",
        "//statements:expression_assignment_bitwise_and",
        "//statements:expression_assignment_bitwise_or",
        "//statements:expression_assignment_bitwise_xor",
        "//statements:expression_assignment_divide",
        "//statements:expression_assignment_left_shift",
        "//statements:expression_assignment_modulo",
        "//statements:expression_assignment_multiply",
        "//statements:expression_assignment_right_shift_signed",
        "//statements:expression_assignment_right_shift_unsigned",
        "//statements:expression_assignment_simple",
        "//statements:expression_assignment_subtract",
        "//statements:expression_literal",
        "//statements:expression_variable",
        "//utils:status",
    ],
)

cc_test(
    name = "expression_object_test",
    size = "small",
    srcs = ["expression_object_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_literal",
        "//statements:expression_object",
    ],
)

cc_test(
    name = "expression_method_call_test",
    size = "small",
    srcs = ["expression_method_call_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_literal",
        "//statements:expression_method_call",
    ],
)

cc_test(
    name = "instruction_break_test",
    size = "small",
    srcs = ["instruction_break_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:instruction_break",
    ],
)

cc_test(
    name = "instruction_continue_test",
    size = "small",
    srcs = ["instruction_continue_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:instruction_continue",
    ],
)

cc_test(
    name = "instruction_return_test",
    size = "small",
    srcs = ["instruction_return_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_literal",
        "//statements:instruction_return",
    ],
)

cc_test(
    name = "identifier_register_test",
    size = "small",
    srcs = ["identifier_register_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//utils:identifier_register",
    ],
)

cc_test(
    name = "expression_getter_test",
    size = "small",
    srcs = ["expression_getter_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_function_mock",
        "//statements:expression_getter",
    ],
)

cc_test(
    name = "expression_setter_test",
    size = "small",
    srcs = ["expression_setter_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        ":expression_function_mock",
        "//statements:expression_setter",
    ],
)

cc_test(
    name = "expression_short_if_test",
    size = "small",
    srcs = ["expression_short_if_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_literal",
        "//statements:expression_short_if",
    ],
)

cc_test(
    name = "expression_lambda_test",
    size = "small",
    srcs = ["expression_lambda_test.cc"],
    linkopts = [
        "-lgtest",
        "-lgmock",
        "-lpthread",
    ],
    deps = [
        "//statements:expression_lambda",
        ":instruction_mock",
    ],
)

cc_library(
    name = "instruction_mock",
    hdrs = ["instruction_mock.h"],
    deps = [
        "//statements:instruction",
    ],
    visibility = ["//visibility:public"], 
)

cc_library(
    name = "expression_function_mock",
    hdrs = ["expression_function_mock.h"],
    visibility = ["//visibility:public"], 
)