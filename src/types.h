#ifndef TYPES_H
#define TYPES_H

typedef struct {
  char *path;
} exec_options_t;

typedef struct {
  char *content;
  long size;
} exec_file_descriptor_t;

#endif
