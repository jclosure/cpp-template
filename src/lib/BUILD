load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "CPPLib",
    srcs = ["cpplib.cc"],
    hdrs = ["cpplib.h"],
    visibility = ["//visibility:public"],
)

# load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")
# refresh_compile_commands(
#     name = "refresh_compile_commands",
#     targets = {
#         ":all": "",
#     },
# )