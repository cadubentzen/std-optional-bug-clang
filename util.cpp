#include <string.h>

int incrementIntIfStringsEqual(const char *c1, const char *c2, int *v) {
  auto result = !strcmp(c1, c2);
  if (result)
    *v += 1;
  return result;
}
