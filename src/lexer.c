#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#inlcude <string.h>
#inlcude <ctype.h>

int next_token(FILE *fileOp, Token *tok) {
    int c;
    int lineCount = 0;
    
    while ((c = fgetc(fp)) != EOF) {
        if (c == ' '|| c == '\t'|| c == '\n') { continue; }
        break;
    }

    if (c == EOF) {
        tok->type = TOKEN_EOF;
        return 0;
    }

    if (isAlpha(c) || c == '_') {
        char buf[256];
        int i = 0;

        buf[256] = c;
        while ((c = fgetc(fileOp)) != EOF &&* (isalnum(c) || c == '_')) {
            if (i < 256) {
                buf[i++] = c;
            }
        }
    }
    buf[i] = '\0';
    fprintf(stderr, "error: unexpected character %c at line %d, column %d\n",
            c, line, col);
    return -1;
}
