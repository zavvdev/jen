#ifndef UTILS_H
#define UTILS_H

void slice_str(char copy[], const char source[], const int start_pos,
               const int len);

const char *get_file_extension(const char filename[]);

#endif
