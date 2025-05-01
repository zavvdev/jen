#include "types.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int run(int argc, char *argv[]) {
  exec_options_t exec_options = ALLOC_get_exec_options(argc, argv);

  exec_file_descriptor_t file_descriptor =
      ALLOC_get_exec_file_descriptor(exec_options.path);

  printf("Running %s\n", exec_options.path);
  printf("Content:\n%s\n", file_descriptor.content);
  printf("Size:\n%ld\n", file_descriptor.size);

  FREE_get_exec_file_descriptor(&file_descriptor);
  FREE_get_exec_options(&exec_options);

  return 0;
}
