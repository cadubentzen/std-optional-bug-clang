# Compiler bug with std::optional

This repo contains a minimal reproducer for a [bug found in WebKit](https://bugs.webkit.org/show_bug.cgi?id=276224).

So far, it has been reproduced with Clang++ 18 and libstdc++ 13.2. It requires at least `-O1` optimization level.
