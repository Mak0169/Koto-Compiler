#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int line = 1;
static int col = 0;

int next_token(FILE *fileOp, Token *tok) {
    char buf[256];
    int c;
    int i = 0;
    
    while ((c = fgetc(fp)) != EOF) {
        col++;
        if (c == '\n') {
            line++;
            col = 0;
            continue;
        }
        if (c == ' '|| c == '\t') { continue; }
        break;
    }

    if (c == EOF) {
        tok->type = TOKEN_EOF;
        tok->line = line;
        tok->column = col;
        return 0;
    }
    tok->line;
    tok->column = col;
    
    /**
     *
     */
    if (isAlpha(c) || c == '_') {
        buf[i++] = c;
        while ((c = fgetc(fileOp)) != EOF && (isalnum(c) || c == '_')) {
            col++;
            if (i < 255) { buf[i++] = c; }
        }
        buf[i] = '\0';
        if (c != EOF) { ungetc(c, fileOp); }
        return 1;
    }

    if (isdigit(c)) {
        i = 0;
        buf[i++] = c;
        while ((c = fgetc(fileOp)) != EOF && (isdigit(c))) {
            col++;
            if (i < 255) { buf[i++] = c; }
        }
        buf[i] = '\0';
        if (c != EOF) { ungetc(c, fileOp); }
        tok->type = TOKEN_NUMBER;
        tok->num = atoi(buf);
        return 1;
    }
    fprintf(stderr, "error: unexpected character %c at line %d, column %d\n",
            c, line, col);
    return -1;
}
