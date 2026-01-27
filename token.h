#ifndef TOKEN_H
#define TOKEN_H

typdef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_KEYWORD,
    TOKEN_SEPERATOR
} TokenType;

typdef enum {
    KW_LET,
    KW_PRINT
} TokenKeyword;

typdef enum {
    SEP_SEMI,
    SEP_PLUS,
    SEP_MINUS,
    SEP_STAR,
    SEP_SLASH,
    SEP_EQ
} TokenSeperator;

typdef struct {
    TokenType type;
    union {
        int num;
        char *identifier;
        TokenKeyword keyword;
        TokenSeperator seperator;
    };
    int line;
    int column;
} Token;

void token_print(const Token *t);
void token_free(Token *t);

#endif
