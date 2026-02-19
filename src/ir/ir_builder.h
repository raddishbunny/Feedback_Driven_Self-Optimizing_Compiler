#pragma once
#include "../frontend/ast.h"
#include "ir_node.h"
#include <vector>
#include <string>

class IRBuilder {

    int tempCount = 0;
    int labelCount = 0;

    std::string newTemp() {
        return "t" + std::to_string(tempCount++);
    }

    std::string newLabel() {
        return "L" + std::to_string(labelCount++);
    }

public:
    std::vector<IRInstr> build(const std::vector<Stmt*>& prog);

private:
    std::string genExpr(Expr* e, std::vector<IRInstr>& ir);
    void genStmt(Stmt* s, std::vector<IRInstr>& ir);
};
