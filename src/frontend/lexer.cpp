#include "lexer.h"
#include <cctype>
#include <iostream>
using namespace std;
Lexer::Lexer(const string& src) : source(src) {}

char Lexer::peek() {
    if (pos >= source.size()) return '\0';
    return source[pos];
}

char Lexer::get() {
    if (pos >= source.size()) return '\0';
    return source[pos++];
}

void Lexer::skipWhitespace() {
    while (isspace(peek())) get();
}

vector<Token> Lexer::tokenize() {
    vector<Token> tokens;

    while (peek() != '\0') {
        skipWhitespace();
        char c = peek();

        if (isalpha(c)) {
            string id;
            while (isalnum(peek()))
                id += get();

            if (id == "let") tokens.push_back({TokenType::LET, id});
            else if (id == "print") tokens.push_back({TokenType::PRINT, id});
            else if (id == "while") tokens.push_back({TokenType::WHILE, id});
            else tokens.push_back({TokenType::IDENTIFIER, id});
        }

        else if (isdigit(c)) {
            string num;
            while (isdigit(peek()))
                num += get();
            tokens.push_back({TokenType::NUMBER, num});
        }

        else {
            switch (get()) {
                case '+': tokens.push_back({TokenType::PLUS, "+"}); break;
                case '-': tokens.push_back({TokenType::MINUS, "-"}); break;
                case '*': tokens.push_back({TokenType::MUL, "*"}); break;
                case '/': tokens.push_back({TokenType::DIV, "/"}); break;
                case '=':
                    if (peek() == '=') {        // for comparison op ==
                        get();                 // consume second '='
                        tokens.push_back({TokenType::EQ, "=="});
                    }
                    else {
                        tokens.push_back({TokenType::ASSIGN, "="}); // for assignment op =
                    }
                    break;
                case ';': tokens.push_back({TokenType::SEMICOLON, ";"}); break;
                case '<': tokens.push_back({TokenType::LT, "<"}); break;
                case '{': tokens.push_back({TokenType::LBRACE, "{"}); break;
                case '}': tokens.push_back({TokenType::RBRACE, "}"}); break;
                default: break;
            }
        }
    }

    tokens.push_back({TokenType::END, ""});
    return tokens;
}
