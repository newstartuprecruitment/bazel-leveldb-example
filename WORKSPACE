workspace(name = "leveldb-bazel-example")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

BAZEL_SKYLIB_VERSION = "1.5.0"

http_archive(
    name = "bazel_skylib",
    urls = [
        "https://github.com/bazelbuild/bazel-skylib/releases/download/{version}/bazel-skylib-{version}.tar.gz".format(version = BAZEL_SKYLIB_VERSION),
    ],
)

http_archive(
    name = "com_github_google_leveldb",
    build_file = "//leveldb:leveldb.BUILD",
    strip_prefix = "leveldb-068d5ee1a3ac40dabd00d211d5013af44be55bea",
    urls = ["https://github.com/google/leveldb/archive/068d5ee1a3ac40dabd00d211d5013af44be55bea.tar.gz"],
)

http_archive(
    name = "com_github_google_snappy",
    build_file = "//:snappy.BUILD",
    strip_prefix = "snappy-1.1.7",
    urls = ["https://github.com/google/snappy/archive/1.1.7.tar.gz"],
)

http_archive(
    name = "com_github_google_crc32c",
    build_file = "//:crc32c.BUILD",
    strip_prefix = "crc32c-21fc8ef30415a635e7351ffa0e5d5367943d4a94",
    urls = ["https://github.com/google/crc32c/archive/21fc8ef30415a635e7351ffa0e5d5367943d4a94.tar.gz"],
)
