load("@bazel_skylib//rules:copy_file.bzl", "copy_file")
load("@rules_cc//cc:defs.bzl", "cc_library")

copy_file(
    name = "port_config_h",
    src = "@//leveldb:port_config.h",
    out = "port/port_config.h",
    allow_symlink = True,
)

copy_file(
    name = "port_h",
    src = "@//leveldb:port.h",
    out = "port/port.h",
    allow_symlink = True,
)

cc_library(
    name = "leveldb",
    srcs = glob(
        [
            "db/**/*.cc",
            "db/**/*.h",
            "helpers/**/*.cc",
            "helpers/**/*.h",
            "port/**/*.cc",
            "port/**/*.h",
            "table/**/*.cc",
            "table/**/*.h",
            "util/**/*.cc",
            "util/**/*.h",
        ],
        exclude = [
            "**/*_test.cc",
            "**/testutil.*",
            "**/*_bench.cc",
            "**/*_windows*",
            "db/leveldbutil.cc",
        ],
    ),
    hdrs = glob(
        ["include/**/*.h"],
        exclude = ["doc/**"],
    ) + [
        ":port_config_h",
        ":port_h",
    ],
    includes = [
        ".",
        "include",
    ],
    linkopts = ["-lpthread"],
    visibility = ["//visibility:public"],
    deps = [
        "@com_github_google_crc32c//:crc32c",
        "@com_github_google_snappy//:snappy",
    ],
)
