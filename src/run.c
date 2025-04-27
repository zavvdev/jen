#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Config

const char EXT[] = "js";

// Flags

const char F_PATH[] = "--path=";

// ===================

void terminate_no_path_flag() {
  printf("%s flag is required\n", F_PATH);
  exit(1);
}

void terminate_invalid_ext() {
  printf("File should have \"%s\" extension\n", EXT);
  exit(1);
}

void terminate_mem() {
  printf("Memory allocation failed\n");
  exit(1);
}

void terminate_file_not_found() {
  printf("File not found\n");
  exit(1);
}

void terminate_unexpected() {
  printf("Unexpected error\n");
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

      if (strcmp(get_file_ext(arg), EXT) != 0) {
        terminate_invalid_ext();
      }

      options.path = malloc((path_len + 1) * sizeof(char));

      if (options.path == NULL) {
        terminate_mem();
      }

      slice_str(options.path, arg, flag_len, arg_len - flag_len);

      if (options.path == NULL) {
        terminate_unexpected();
      }
    } else {
      terminate_no_path_flag();
    }
  }

  return options;
}

typedef struct {
  char *content;
  long size;
} file_t;

file_t get_file_content(const char path[]) {
  FILE *f = fopen(path, "rb");

  if (f == NULL) {
    terminate_file_not_found();
  }

  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  rewind(f);

  char *content = malloc(fsize + 1);

  if (content == NULL) {
    fclose(f);
    terminate_mem();
  }

  fread(content, fsize, 1, f);
  fclose(f);

  content[fsize] = 0;

  return (file_t){.content = content, .size = fsize};
}

int run(int argc, char *argv[]) {
  options_t options = collect_options(argc, argv);
  file_t file = get_file_content(options.path);

  printf("Running %s\n", options.path);
  printf("Content:\n%s\n", file.content);
  printf("Size:\n%ld\n", file.size);

  free(file.content);
  free(options.path);

  return 0;
}
