#include <stdio.h>
#include <string.h>

int atoi(const char *str) {
  int mult = 1;
  int ret = 0;
  for (int i = strlen(str) - 1; i >= 0; --i) {
    int digit = str[i] - '0';
    ret += digit * mult;
    mult *= 10;
  }
  return ret;
}

int main(int argc, char **argv) {
  if (argc <= 1) {
    printf("usage: ./atoi [args...]\n");
    return 0;
  }
  int sum = 0;
  int prod = 1;
  for (int i = 1; i < argc; ++i) {
    printf("%d\n", atoi(argv[i]));
    sum += atoi(argv[i]);
    prod *= atoi(argv[i]);
  }

  printf("%d %d\n", sum, prod);

  return 0;
}
