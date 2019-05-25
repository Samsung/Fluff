cc_library(
    name = "status",
    srcs = ["status.cc"],
    hdrs = ["status.h"],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "reader",
    hdrs = ["reader.h"],
    deps = [
        ":status",
    ],
)

cc_library(
    name = "reader_file",
    srcs = ["reader_file.cc"],
    hdrs = ["reader_file.h"],
    linkopts = ["-lyaml-cpp"],
    deps = [
        ":reader",
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "variable_id_allocator",
    hdrs = ["variable_id_allocator.h"],
    deps = [
        ":status",
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "variable_id_allocator_impl",
    srcs = ["variable_id_allocator_impl.cc"],
    hdrs = ["variable_id_allocator_impl.h"],
    deps = [
        ":status",
        ":variable_id_allocator",
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "identifier_register",
    srcs = ["identifier_register.cc"],
    hdrs = ["identifier_register.h"],
    deps = [
        ":status",
        ":reader_file",
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "parser",
    srcs = ["parser.cc"],
    hdrs = ["parser.h"],
    deps = [
        "//statements:expression",
        "//statements:expression_ppid",
        "//utils:identifier_register",
        "//statements:instruction",
        "//utils:parser_opcodes_util",
        "//utils:reader",
        "//utils:status",
        "//utils:variable_id_allocator",
        "//utils:variable_id_allocator_impl",
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "parser_opcodes_util",
    hdrs = ["parser_opcodes_util.h"],
    deps = [
        "//statements:expression_addition",
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
        "//statements:expression_bitwise_and",
        "//statements:expression_bitwise_or",
        "//statements:expression_bitwise_xor",
        "//statements:expression_class_field_access_bracket",
        "//statements:expression_class_field_access_dot",
        "//statements:expression_division",
        "//statements:expression_equals",
        "//statements:expression_equals_type",
        "//statements:expression_function",
        "//statements:expression_function_application",
        "//statements:expression_getter",
        "//statements:expression_greater",
        "//statements:expression_greater_equal",
        "//statements:expression_lambda",
        "//statements:expression_left_shift",
        "//statements:expression_literal",
        "//statements:expression_logical_and",
        "//statements:expression_logical_or",
        "//statements:expression_method_call",
        "//statements:expression_modulo",
        "//statements:expression_multiplication",
        "//statements:expression_new",
        "//statements:expression_not",
        "//statements:expression_not_equals",
        "//statements:expression_not_equals_type",
        "//statements:expression_object",
        "//statements:expression_postdecrement",
        "//statements:expression_postincrement",
        "//statements:expression_predecrement",
        "//statements:expression_preincrement",
        "//statements:expression_right_shift_signed",
        "//statements:expression_right_shift_unsigned",
        "//statements:expression_setter",
        "//statements:expression_short_if",
        "//statements:expression_smaller",
        "//statements:expression_smaller_equal",
        "//statements:expression_subtraction",
        "//statements:expression_variable",
        "//statements:instruction_break",
        "//statements:instruction_const",
        "//statements:instruction_continue",
        "//statements:instruction_for",
        "//statements:instruction_if",
        "//statements:instruction_if_else",
        "//statements:instruction_let",
        "//statements:instruction_return",
        "//statements:instruction_try_catch_finally",
        "//statements:instruction_var",
        "//statements:instruction_while",
    ],
)