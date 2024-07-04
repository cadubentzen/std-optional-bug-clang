// Defining `incrementIntIfStringsEqual` in the same compilation unit fixes the
// bug, it needs to be in a separate one.
#include "util.h"
#include <iostream>
#include <optional>

#define UNLIKELY(x) __builtin_expect(!!(x), 0)

std::optional<int> shouldReturnEmptyOptional() {
  int v = 1;
  // Fixes the issue:
  // if (UNLIKELY(incrementIntIfStringsEqual("a", "b", &v)))
  if (incrementIntIfStringsEqual("a", "b", &v))
    return v;
  return std::nullopt;
}

int main(int argc, char **argv) {
  auto opt = shouldReturnEmptyOptional();
  // The issue is gone if `*opt > 0` is removed.
  if (opt && *opt > 0) {
    // If opt is not dereferenced inside this scope, the bug is also gone
    std::cout << "SHOULD NOT BE PRINTED: *opt = " << *opt << std::endl;
  }
}
