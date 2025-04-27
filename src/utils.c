#include "utils.h"
#include "config.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Copies a substring from the source string to the destination string.
 */
void slice_str(char copy[], const char source[], const int start_pos,
               const int len) {
  int i = 0;

  while (i < len) {
    copy[i] = source[start_pos + i];
    i++;
  }

  copy[i] = '\0';
}

/**
 * Returns the file extension of a given filename.
 */
const char *get_file_ext(const char filename[]) {
  const char *dot = strrchr(filename, '.');
  if (!dot || dot == filename) {
    return "";
  }
  return dot + 1;
}

/**
 * INCLUDES MEMORY ALLOCATIONS
 *
 * Parses incoming execution flags and returns constructed options.
 *
 * Allocations:
 * - options.path
 */
exec_options_t ALLOC_get_exec_options(int argc, char *argv[]) {
  const char MSG_NO_FLAG[] = "%s flag is required\n";

  if (argc < 2) {
    printf(MSG_NO_FLAG, EXEC_FLAG_PATH);
    exit(1);
  }

  exec_options_t options = {NULL};

  for (int i = 1; i < argc; i++) {
    char *arg = argv[i];
    int arg_len = strlen(arg);

    if (strstr(arg, EXEC_FLAG_PATH) != NULL) {
      int flag_len = strlen(EXEC_FLAG_PATH);
      int path_len = arg_len - flag_len;

      if (path_len <= 0) {
        printf(MSG_NO_FLAG, EXEC_FLAG_PATH);
        exit(1);
      }

      if (strcmp(get_file_ext(arg), EXEC_FILE_EXT) != 0) {
        printf("File should have \"%s\" extension\n", EXEC_FILE_EXT);
        exit(1);
      }

      options.path = malloc((path_len + 1) * sizeof(char));

      if (options.path == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
      }

      slice_str(options.path, arg, flag_len, arg_len - flag_len);

      if (options.path == NULL) {
        printf("Unexpected error\n");
        exit(1);
      }
    } else {
      printf(MSG_NO_FLAG, EXEC_FLAG_PATH);
      exit(1);
    }
  }

  return options;
}

/**
 * INCLUDES MEMORY ALLOCATIONS
 *
 * Reads the file content from the given path and returns a file descriptor.
 *
 * Allocations:
 * - file.content
 */
exec_file_descriptor_t ALLOC_get_exec_file_descriptor(const char path[]) {
  FILE *f = fopen(path, "rb");

  if (f == NULL) {
    printf("File not found\n");
    exit(1);
  }

  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  rewind(f);

  char *content = malloc(fsize + 1);

  if (content == NULL) {
    fclose(f);
    printf("Memory allocation failed\n");
    exit(1);
  }

  fread(content, fsize, 1, f);
  fclose(f);

  content[fsize] = 0;

  return (exec_file_descriptor_t){.content = content, .size = fsize};
}
