#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Config

const char EXT[] = "js";

// Flags

const char F_PATH[] = "--path=";

// Collect options

void terminate_no_path_flag() {
  printf("%s flag is required\n", F_PATH);
  exit(1);
}

void terminate_invalid_ext() {
  printf("File should have \"%s\" extension\n", EXT);
  exit(1);
}

void terminate_internal() {
  printf("Internal error\n");
  exit(1);
}

typedef struct {
  char *path;
} options_t;

options_t collect_options(int argc, char *argv[]) {
  if (argc < 2) {
    terminate_no_path_flag();
  }

  options_t options = {NULL};

  for (int i = 1; i < argc; i++) {
    char *arg = argv[i];
    int arg_len = strlen(arg);

    if (strstr(arg, F_PATH) != NULL) {
      int flag_len = strlen(F_PATH);
      int path_len = arg_len - flag_len;

      if (path_len <= 0) {
        terminate_no_path_flag();
      }

      if (strcmp(get_file_extension(arg), EXT) != 0) {
        terminate_invalid_ext();
      }

      options.path = malloc((path_len + 1) * sizeof(char));

      if (options.path == NULL) {
        terminate_internal();
      }

      slice_str(options.path, arg, flag_len, arg_len - flag_len);
    } else {
      terminate_no_path_flag();
    }
  }

  return options;
}

// Run

int run(int argc, char *argv[]) {
  options_t options = collect_options(argc, argv);
  printf("Path: %s\n", options.path);
  free(options.path);
  return 0;
}
