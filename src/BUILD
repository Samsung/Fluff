cc_binary(
    name = "fluff_moz",
    srcs = ["fluff.cc"],
    linkopts = ["-lyaml-cpp"],
    deps = [
        "//utils:identifier_register",
        "//statements:instruction",
        "//interfaces:javascript_interface_spidermonkey",
        "//utils:parser",
        "//utils:reader_file",
        "//utils:status",
        "@moz//:moz_lib",
    ],
)

cc_binary(
    name = "fluff_njs",
    srcs = ["fluff.cc"],
    linkopts = [
        "-lyaml-cpp",
        "-lpcre",
        "-fsanitize=address"
    ],
    deps = [
        "//utils:identifier_register",
        "//statements:instruction",
        "//interfaces:javascript_interface_njs",
        "//interfaces:builtins",
        "//utils:parser",
        "//utils:reader_file",
        "//utils:status",
        "@njs//:njs_lib",
    ],
    defines = ["FUZZ_NJS"]
)


cc_binary(
    name = "fluff_njs_dry",
    srcs = ["fluff.cc"],
    linkopts = [
        "-lyaml-cpp",
        "-lpcre",
        "-fsanitize=address"
    ],
    deps = [
        "//utils:identifier_register",
        "//statements:instruction",
        "//interfaces:javascript_interface_dryrun",
        "//interfaces:builtins",
        "//utils:parser",
        "//utils:reader_file",
        "//utils:status",
        "@njs//:njs_lib",
    ],
    defines = ["FUZZ_NJS"]
)

cc_binary(
    name = "fluff_v8",
    srcs = ["fluff.cc"],
    linkopts = [
        "-lyaml-cpp",
        "-lpthread"
    ],
    deps = [
        "//utils:identifier_register",
        "//statements:instruction",
        "//interfaces:javascript_interface_v8",
        "//interfaces:builtins",
        "//utils:parser",
        "//utils:reader_file",
        "//utils:status",
        "@v8//:v8_lib",
    ],
    defines = ["FUZZ_V8"]
)

cc_binary(
    name = "fluff_v8_dry",
    srcs = ["fluff.cc"],
    linkopts = [
        "-lyaml-cpp",
        "-lpthread",
    ],
    deps = [
        "//utils:identifier_register",
        "//statements:instruction",
        "//interfaces:javascript_interface_dryrun",
        "//interfaces:builtins",
        "//utils:parser",
        "//utils:reader_file",
        "//utils:status",
    ],
    defines = ["FUZZ_V8"]
)

cc_binary(
    name = "fluff_duktape",
    srcs = ["fluff.cc"],
    linkopts = [
        "-lyaml-cpp",
    ],
    deps = [
        "//utils:identifier_register",
        "//statements:instruction",
        "//interfaces:builtins",
        "//interfaces:javascript_interface_duktape",
        "//utils:parser",
        "//utils:reader_file",
        "//utils:status"
    ],
    defines = ["FUZZ_DUKTAPE"]
)

cc_binary(
    name = "fluff_duktape_dry",
    srcs = ["fluff.cc"],
    linkopts = [
        "-lyaml-cpp",
    ],
    deps = [
        "//utils:identifier_register",
        "//statements:instruction",
        "//interfaces:builtins",
        "//interfaces:javascript_interface_dryrun",
        "//utils:parser",
        "//utils:reader_file",
        "//utils:status"
    ],
    defines = ["FUZZ_DUKTAPE"]
)

cc_binary(
    name = "fluff_jerryscript",
    srcs = ["fluff.cc"],
    linkopts = [
        "-lyaml-cpp",
    ],
    deps = [
        "//utils:identifier_register",
        "//statements:instruction",
        "//interfaces:builtins",
        "//interfaces:javascript_interface_jerryscript",
        "//utils:parser",
        "//utils:reader_file",
        "//utils:status"
    ],
    defines = ["FUZZ_JERRYSCRIPT"]
)

cc_binary(
    name = "fluff_jerryscript_dry",
    srcs = ["fluff.cc"],
    linkopts = [
        "-lyaml-cpp",
    ],
    deps = [
        "//utils:identifier_register",
        "//statements:instruction",
        "//interfaces:builtins",
        "//interfaces:javascript_interface_dryrun",
        "//utils:parser",
        "//utils:reader_file",
        "//utils:status"
    ],
    defines = ["FUZZ_JERRYSCRIPT"]
)
