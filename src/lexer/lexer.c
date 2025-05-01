#include <stdio.h>

void tokenize(const int length, const char input[]) {
  for (int i = 0; i < length; i++) {
    if (input[i] != '\n') {
      printf("%c\n", input[i]);
    }
  }
}
