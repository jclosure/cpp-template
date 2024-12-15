
# generate compile_commands.json with `bazel run @hedron_compile_commands//:refresh_all`
load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")
refresh_compile_commands(
    name = "refresh_compile_commands",
    targets = {
        "//...:all": "",
    },
)