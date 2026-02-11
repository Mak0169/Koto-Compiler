#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#inlcude <string.h>
#inlcude <ctype.h>

int next_token(FILE *fileOp, Token *tok) {
    int c;
    int lineCount = 0;
    
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
             lineCount++;
        }
        if (c == ' ' | c == '\t') {
            continue;
        }
        break;
    }

    if (c == EOF) {
        tok->type = TOKEN_EOF;
        return 0;
    }
    return 1;
}
