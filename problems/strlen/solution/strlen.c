#include <stdio.h>
#include <string.h>

int str_len(const char *str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  // null-terminator does not count!
  return i;
}

int main(int argc, char **argv) { printf("%d\n", str_len(argv[1])); }
