#include "exec.h"
#include "exec-flags.h"
#include <stdio.h>

int exec(int argc, char *argv[]) {
  printf("----Number of arguments: %d\n", argc);
  for (int i = 1; i < argc; i++) {
    printf("PATH FLAG: %s\n", EF_PATH);
    printf("Argument %d: %s\n", i, argv[i]);
  }
  return 0;
}
