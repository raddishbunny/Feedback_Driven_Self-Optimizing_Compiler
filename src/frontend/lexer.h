#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
enum class TokenType {
    LET,
    PRINT,
    WHILE,
    IDENTIFIER,
    NUMBER,

    PLUS,
    MINUS,
    MUL,
    DIV,
    ASSIGN,
    SEMICOLON,

    LT,

    LBRACE,
    RBRACE,
    EQ, // for '=='
    END
};

struct Token {
    TokenType type;
    string value;
};

class Lexer {
public:
    Lexer(const string& src);
    vector<Token> tokenize();

private:
    char peek();
    char get();
    void skipWhitespace();

    string source;
    size_t pos = 0;
};