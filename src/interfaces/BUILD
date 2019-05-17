package(default_visibility = ["//visibility:public"])

cc_library(
    name = "javascript_interface_njs",
    srcs = [
        "javascript_interface_njs.cc",
    ],
    hdrs = ["javascript_interface.h"],
    deps = [
        "builtins",
        "//statements:instruction",
        "@njs//:njs_lib",
    ]
)

cc_library(
    name = "javascript_interface_dryrun",
    srcs = [
        "javascript_interface_dryrun.cc",
    ],
    hdrs = ["javascript_interface.h"],
    deps = [
        "//statements:instruction",
    ]
)

cc_library(
    name = "javascript_interface_spidermonkey",
    srcs = ["javascript_interface_spidermonkey.cc"],
    hdrs = ["javascript_interface.h"],
    deps = [
        "builtins",
        "//statements:instruction",
        "@moz//:moz_lib",
    ]
)

cc_library(
    name = "javascript_interface_duktape",
    srcs = ["javascript_interface_duktape.cc"],
    hdrs = ["javascript_interface.h"],
    deps = [
        "builtins",
        "//statements:instruction",
        "@duktape//:duktape_lib"
    ]
)

cc_library(
    name = "javascript_interface_jerryscript",
    srcs = ["javascript_interface_jerryscript.cc"],
    hdrs = ["javascript_interface.h"],
    deps = [
        "builtins",
        "//statements:instruction",
        "@jerryscript//:jerryscript_core",
        "@jerryscript//:jerryscript_libm",
        "@jerryscript//:jerryscript_port",
        "@jerryscript//:jerryscript_ext"
    ]
)

cc_library(
    name = "javascript_interface_v8",
    srcs = ["javascript_interface_v8.cc"],
    hdrs = ["javascript_interface.h"],
    deps = [
        "builtins",
        "//statements:instruction",
        "@v8//:v8_lib"
    ]
)

cc_library(
    name = "builtins",
    hdrs = ["builtins.h", "builtins_chakra.h", "builtins_njs.h",
            "builtins_duktape.h", "builtins_espruino.h", "builtins_jerryscript.h",
            "builtins_spidermonkey.h", "builtins_v8.h"]
)
