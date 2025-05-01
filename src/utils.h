#ifndef UTILS_H
#define UTILS_H

#include "types.h"

void slice_str(char copy[], const char source[], const int start_pos,
               const int len);

const char *get_file_ext(const char filename[]);

exec_options_t alloc_get_exec_options(int argc, char *argv[]);
void free_get_exec_options(exec_options_t *options);

exec_file_descriptor_t alloc_get_exec_file_descriptor(const char path[]);
void free_get_exec_file_descriptor(exec_file_descriptor_t *options);

#endif
