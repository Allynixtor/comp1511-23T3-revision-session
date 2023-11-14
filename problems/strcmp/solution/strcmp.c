#include <stdio.h>
#include <string.h>

int strcmp(const char *s1, const char *s2) {

  int len;
  // Choose len as the shorter size string
  if (strlen(s1) > strlen(s2)) {
    len = strlen(s2);
  }
  len = strlen(s1);

  // Check if the two substrings are the same
  for (int i = 0; i < len; ++i) {
    if (s1[i] != s2[i]) {
      return (s1[i] - s2[i] > 0) ? 1 : -1;
    }
  }
  if (strlen(s1) == strlen(s2)) {
    return 0;
  }
  // If the shorter string is s1, then s2 and vice versa.
  if (len == strlen(s1)) {
    return -1;
  } else if (len == strlen(s2)) {
    return 1;
  }

  return 0;
}

int main(int argc, char **argv) { printf("%d\n", strcmp(argv[1], argv[2])); }
