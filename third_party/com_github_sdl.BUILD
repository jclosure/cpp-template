load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "all_files",
    srcs = glob(["**/*"]),
)

config_setting(
    name = "debug_build",
    values = {
        "compilation_mode": "dbg",
    },
)

cmake(
    name = "sdl",
    build_args = ["-j"],
    cache_entries = {
        "SDL_SHARED": "OFF",
        "SDL_STATIC": "ON",
        "SDL_TEST": "OFF",
        "SDL_AUDIO": "OFF",
    },
    lib_source = ":all_files",
    out_static_libs = select({
        ":debug_build": ["libSDL2d.a"],
        "//conditions:default": ["libSDL2.a"],
    }),
)
