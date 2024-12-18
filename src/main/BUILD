load("@rules_cc//cc:defs.bzl", "cc_binary")

# Demo of genrul
genrule(
    name = "test",
    srcs = [],
    outs = ["test.txt"],
    cmd = "echo 'Hello world' > $@",
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["//src/lib:CPPLib"],
)

cc_binary(
    name = "main_fib",
    srcs = ["main_fib.cc"],
    deps = ["//src/lib:CPPLib"],
)

cc_binary(
    name = "main_logger",
    srcs = ["main_logger.cc"],
    deps = [
        "//src/lib:CPPLib",
        "@gflags//:gflags",
        "@glog",
    ],
)

cc_binary(
    name = "main_flags_absl",
    srcs = ["main_flags_absl.cc"],
    deps = [
        "@abseil-cpp//absl/flags:flag",
        "@abseil-cpp//absl/flags:parse",
        "@abseil-cpp//absl/flags:usage",
        "@glog",
    ],
)

cc_binary(
    name = "main_address_sanitize",
    srcs = ["main_address_sanitize.cc"],
    # Set this variable to the right path for llvm-symbolizer on your machine.
    env =
        {
            # "ASAN_SYMBOLIZER_PATH": "/usr/local/Cellar/llvm/13.0.0_1/bin/llvm-symbolizer"
            "ASAN_OPTIONS": "detect_stack_use_after_return=1",
        },
    deps = [
    ],
)

cc_binary(
    name = "main_undefined_behavior_sanitizer",
    srcs = ["main_undefined_behavior_sanitizer.cc"],
    deps = [
        "@abseil-cpp//absl/flags:flag",
        "@abseil-cpp//absl/flags:parse",
        "@abseil-cpp//absl/flags:usage",
        "@glog",
    ],
)

cc_binary(
    name = "fib_main",
    srcs = ["fib_main.cc"],
    deps = [
    ],
)

# Supported Platforms
config_setting(
    name = "darwin",
    constraint_values = ["@platforms//os:osx"],
)

config_setting(
    name = "linux",
    constraint_values = ["@platforms//os:linux"],
)

cc_binary(
    name = "main_sdl",
    srcs = ["main_sdl.cc"],
    linkopts = select({
        ":darwin": [
            "-framework Cocoa",
            "-framework CoreHaptics",
            "-framework CoreVideo",
            "-framework ForceFeedback",
            "-framework GameController",
            "-framework IOKit",
            "-framework Carbon",
            "-framework Metal",
        ],
        ":linux": ["-ldl"],
    }),
    deps = [
        "@sdl",
        "@abseil-cpp//absl/log:absl_log",
        "@abseil-cpp//absl/log:globals",
        "@abseil-cpp//absl/log:initialize",
        "@abseil-cpp//absl/status",
        "@abseil-cpp//absl/strings",
        "@glm"
    ]
)


# load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")
# refresh_compile_commands(
#     name = "refresh_compile_commands",
#     targets = {
#         ":all": "",
#     },
# )

