# local_repos.bzl

load("@bazel_tools//tools/build_defs/repo:repo.bzl", "new_local_repository")

def _local_repos_impl(ctx):
    # Create the usr_local repository
    new_local_repository(
        name = "usr_local",
        build_file = ctx.read_file("third_party/usr_local.BUILD"),
        path = "/usr/local",
    )

    # Create the zlib repository
    new_local_repository(
        name = "zlib",
        build_file = ctx.read_file("third_party/zlib.BUILD"),
        path = "/opt/homebrew/opt/zlib",
    )

local_repos = module_extension(
    implementation = _local_repos_impl,
    # documentation and other fields can be added if needed
)
