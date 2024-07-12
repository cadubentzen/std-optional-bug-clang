# Compiler bug with std::optional

This repo contains a minimal reproducer for a [bug found in WebKit](https://bugs.webkit.org/show_bug.cgi?id=276224).

It has been reproduced with Clang++ 18 and libstdc++ 13.2. It requires at least `-O1` optimization level.

The code has been reduced to a minimum, now with no dependencies to libstdc++ anymore.

It has been introduced by [this commit](https://github.com/llvm/llvm-project/commit/060de415af335fdd82910f409e2be3b8457eaa43) in LLVM.

Example in Compiler Explorer: https://godbolt.org/z/zvsvqvMnz


