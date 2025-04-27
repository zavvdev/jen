void slice_str(char copy[], const char source[], const int start_pos,
               const int len) {
  int i = 0;

  while (i < len) {
    copy[i] = source[start_pos + i];
    i++;
  }

  copy[i] = '\0';
}
