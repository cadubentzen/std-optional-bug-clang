// Defining `incrementIntIfStringsEqual` in the same compilation unit fixes the
// bug, it needs to be in a separate one.
int incrementIntIfTrue(int &, bool);
void useInt(int a);

// Very stripped-down version of std::optional from libstdc++.
// The minimum to reproduce the issue.
class OptInt {
public:
  // Fixes the issue by replacing the empty ctor with:
  // constexpr OptInt() = default;
  constexpr OptInt() {}
  constexpr OptInt(int t) : payload(t), engaged(true) {}

  constexpr const int &operator*() const & noexcept { return this->payload; }
  constexpr explicit operator bool() const noexcept { return this->engaged; }

private:
  int payload;
  bool engaged{false};
};

// Also fixes the issue by adding __attribute__((noinline)
static OptInt shouldReturnEmptyOptional() {
  int v = 1;
  if (incrementIntIfTrue(v, false))
    return v;
  return {};
}

int main(int argc, char **argv) {
  auto opt = shouldReturnEmptyOptional();
  // The issue is gone if `*opt > 0` is removed.
  if (opt && *opt > 0) {
    // If opt is not dereferenced inside this scope, the bug is also gone
    useInt(*opt);
  }
}
