#pragma once
#include "lexer.h"
#include "ast.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    std::vector<Stmt*> parseProgram();

private:
    Stmt* parseStatement();
    Stmt* parseLet();
    Stmt* parseAssign();
    Stmt* parsePrint();
    Stmt* parseWhile();

    Expr* parseExpr();
    Expr* parseTerm();
    Expr* parseFactor();
    Expr* parseComparison();

    Token peek();
    Token get();
    bool match(TokenType t);

    std::vector<Token> tokens;
    size_t pos = 0;
};
