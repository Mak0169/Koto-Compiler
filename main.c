#include <stdio.h>
#include <stdlib.h>

typedef enum {
    TOKEN_IDENTIFER,
    TOKEN_KEYWORD,
    TOKEN_NUMBER,
    TOKEN_STRING_LITERAL,
    TOKEN_SEPARATOR
} tokenType;

typedef enum {
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
    OPEN_BRACK,
    CLOSE_BRAK
} tokenSeperator;

typedef enum {
    IF,
    ELSE,
    WHILE,
    FOR,
    RETURN,
    INT,
    FLOAT
} tokenKeyword;

typedef struct {
    TokenType type; 
} Token;


int main() {
    
}

