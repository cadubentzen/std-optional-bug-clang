int takeIntRefReturn0(int &);
void assertNotReached(int);

static bool logicalAnd(bool a, bool b) { return a && b; }

int main() {
  bool v3;
  int v4;
  {
    int v1 = 1;
    int v2 = takeIntRefReturn0(v1);
    v3 = v2 != 0;
    v4 = v3 ? v1 : v4;
  }
  if (logicalAnd(v3, v4 > 0))
    assertNotReached(v4);

  return 0;
}
