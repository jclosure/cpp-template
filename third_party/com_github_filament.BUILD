load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "all_files",
    srcs = glob(
        ["**/*"],
        # exclude = [
        #     "filament/third_party/**/*",
        # ]
    ),
)

config_setting(
    name = "debug_build",
    values = {
        "compilation_mode": "dbg",
    },
)

# In this example:
# - We specify a couple of cache entries to ensure static builds.
# - Filament builds multiple libraries; adjust out_static_libs according to the 
#   actual output. For example, on Linux x86_64 builds, you might expect:
#   - libfilament.a
#   - libutils.a
#   - libmath.a
#   - libfilabridge.a
#   - libbackend.a
#   - libbluegl.a
#   - libbluevk.a
#   - libfilameshio.a
#   - libgltfio.a
#
# The exact set of libraries depends on the Filament version and build options.
# If unsure, build Filament separately first, then list the libs found in the build output directory.
#
# Also, consider setting CMAKE_BUILD_TYPE based on debug or not:
# - If dbg: set CMAKE_BUILD_TYPE=Debug
# - Otherwise: set CMAKE_BUILD_TYPE=Release

cmake(
    name = "filament",
    build_args = ["-j"],
    cache_entries = {
        # "CMAKE_BUILD_TYPE": select({
        #     ":debug_build": "Debug",
        #     "//conditions:default": "Release",
        # }),
        "FILAMENT_BUILD_STATIC": "ON",   # Ensure static builds
        "FILAMENT_SKIP_SAMPLES": "ON",   # Skip building samples, if desired
        "FILAMENT_SKIP_TESTS": "ON",     # Skip tests to speed build
    },
    lib_source = ":all_files",
    # Adjust these libraries based on what Filament produces after the build.
    # Typically, after a successful build, you'll find them in out/cmake-release/filament/lib
    # or a similar directory structure. The cmake() rule will place them in
    # a staging area. You may need to update these paths after verifying a local build.
    out_static_libs = [
        "libfilament.a",
        "libutils.a",
        "libmath.a",
        "libfilabridge.a",
        "libbackend.a",
        "libbluegl.a",
        "libbluevk.a",
        "libfilameshio.a",
        "libgltfio.a",
    ],
)
