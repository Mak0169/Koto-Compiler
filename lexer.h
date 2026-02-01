#ifdef LEXER_H
#define LEXER_H

#include "token.h"
#include <stdio.h>

int next_token(FILE *fileOp, Token *tok);

#endif
