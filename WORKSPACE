load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

http_archive(
    name = "platforms",
    sha256 = "a07fe5e75964361885db725039c2ba673f0ee0313d971ae4f50c9b18cd28b0b5",
    url = "https://github.com/bazelbuild/platforms/archive/441afe1bfdadd6236988e9cac159df6b5a9f5a98.zip",
    strip_prefix = "platforms-441afe1bfdadd6236988e9cac159df6b5a9f5a98"
)

git_repository(
    name = "bazel_skylib",
    commit = "f80bc733d4b9f83d427ce3442be2e07427b2cc8d",
    remote = "git@gitlab.tableausoftware.com:tableaubuild/bazel/mirrors/bazel/bazel-skylib.git",
    shallow_since = "1611945497 -0500",
)

