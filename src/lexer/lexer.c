#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

token_vec_t *alloc_token_vec(const long capacity) {
  char MEM_ALLOC_ERROR[] = "Memory allocation error\n";

  token_vec_t *vec = malloc(sizeof(token_vec_t));

  if (vec == NULL) {
    printf("%s", MEM_ALLOC_ERROR);
    exit(1);
  }

  long allocated_capacity = capacity / 4;

  if ((vec->tokens = calloc(allocated_capacity, sizeof(token_t)))) {
    vec->capacity = allocated_capacity;
    vec->length = 0;

    return vec;
  } else {
    printf("%s", MEM_ALLOC_ERROR);
    free(vec);
    exit(1);
  }
}

void free_token_vec(token_vec_t *vec) {
  if (vec) {
    if (vec->tokens) {
      free(vec->tokens);
    }
    free(vec);
  }
}

void token_vec_push_back(token_vec_t *vec, token_t token) {
  if (vec->length >= vec->capacity) {
    // TODO: Add heuristic to determine new capacity more efficiently
    vec->capacity *= 2;

    token_t *next_tokens_location =
        realloc(vec->tokens, vec->capacity * sizeof(token_t));

    if (next_tokens_location == NULL) {
      printf("Memory allocation error\n");
      free_token_vec(vec);
      exit(1);
    } else {
      vec->tokens = next_tokens_location;
    }
  }
  vec->tokens[vec->length++] = token;
}

token_vec_t *tokenize(const long length, const char input[]) {
  token_vec_t *tokens_vec = alloc_token_vec(length);

  for (int i = 0; i < length; i++) {
    if (input[i] != '\n') {
      printf("%c\n", input[i]);
    }
  }

  return tokens_vec;
}
