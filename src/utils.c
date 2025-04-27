#include <string.h>

void slice_str(char copy[], const char source[], const int start_pos,
               const int len) {
  int i = 0;

  while (i < len) {
    copy[i] = source[start_pos + i];
    i++;
  }

  copy[i] = '\0';
}

const char *get_file_ext(const char filename[]) {
  const char *dot = strrchr(filename, '.');
  if (!dot || dot == filename) {
    return "";
  }
  return dot + 1;
}
