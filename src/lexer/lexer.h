#ifndef LEXER_H
#define LEXER_H

typedef enum {
  T_NUMBER,
  T_ADD,
  T_SUB,
  T_MUL,
  T_DIV,
} token_type_t;

typedef struct {
  token_type_t type;
  char *value;
  int start;
  int end;
  int line;
  int column;
} token_t;

typedef struct {
  token_t *tokens;
  long length;
  long capacity;
} token_vec_t;

token_vec_t *alloc_token_vec(const long capacity);

void free_token_vec(token_vec_t *vec);

void token_vec_push_back(token_vec_t *vec, const token_t token);

token_vec_t *tokenize(const long length, const char input[]);

#endif
