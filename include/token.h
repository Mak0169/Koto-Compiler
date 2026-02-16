#ifdef TOKEN_H
#define TOKEN_H

typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_KEYWORD,
    TOKEN_SEPERATOR,
    TOKEN_STRING
} TokenType;

typedef enum {
    KW_LET,
    KW_PRINT
} TokenKeyword;

typedef enum {
    SEP_SEMI,
    SEP_PLUS,
    SEP_MINUS,
    SEP_STAR,
    SEP_SLASH,
    SEP_EQ
} TokenSeperator;

typedef struct {
    TokenType type;
    union {
        int num;
        char *identifier;
        char *string;
        TokenKeyword keyword;
        TokenSeperator seperator;
    };
    int line;
    int column;
} Token;

void token_print(const Token *t);
void token_free(Token *t);

#endif
