#include <iostream>

int incrementIntIfTrue(int &v, bool c) {
  if (c)
    v += 1;
  return c;
}

void useInt(int a) { std::cout << a << std::endl; }
