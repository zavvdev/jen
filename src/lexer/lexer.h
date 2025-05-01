#ifndef LEXER_H
#define LEXER_H

// In V8 they use a token list generation with macros.
// Not sure if we should do the same, so I think we just
// stick to the regular enum + constants for now.
//
// Token should have:
// - enum type
// - string representation
// - start position
// - end position
// - line number
// - column number

void tokenize(const int length, const char input[]);

#endif
