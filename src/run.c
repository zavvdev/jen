#include "lexer/lexer.h"
#include "types.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int run(int argc, char *argv[]) {
  exec_options_t exec_options = alloc_get_exec_options(argc, argv);

  exec_file_descriptor_t file_descriptor =
      alloc_get_exec_file_descriptor(exec_options.path);

  tokenize(file_descriptor.size, file_descriptor.content);

  free_get_exec_file_descriptor(&file_descriptor);
  free_get_exec_options(&exec_options);

  return 0;
}
