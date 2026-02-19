#include <iostream>
#include <fstream>
#include <sstream>
#include "frontend/lexer.h"
#include "frontend/parser.h"
#include "ir/ir_builder.h"
#include "frontend/ast.h"
#include "backend/optimizer.h"
#include "backend/codegen.h"
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./compiler <file>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string source = buffer.str();
    std::cout << "Source loaded (" << source.size() << " bytes)\n";

    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    for (auto& t : tokens) {
        std::cout << (int)t.type << " : " << t.value << std::endl;
    }
    //Parser
    Parser parser(tokens);
    auto program = parser.parseProgram();
    std::cout << "Parsed " << program.size() << " statements successfully\n";
    //IR Builder
    IRBuilder builder;
    auto ir = builder.build(program);
    //Optimizer
    Optimizer optimizer;
    //optimizer.constantFold(ir);
    optimizer.loadProfile("profile.txt");
    optimizer.optimize(ir);

    //CodeGen
    CodeGen gen;
    gen.emitC(ir, "output.c");

    //optimizer.deadCodeElimination(ir);
    std::cout << "\n=== OPTIMIZED IR ===\n";
    for (auto &i : ir) {

        if (i.op == "label")
            std::cout << i.res << ":\n";

        else if (i.op == "goto")
            std::cout << "GOTO " << i.res << "\n";

        else if (i.op == "ifgoto")
            std::cout << "IF " << i.a1 << " == " << i.a2 << " GOTO " << i.res << "\n";

        else if (i.op == "assign")
            std::cout << i.res << " = " << i.a1 << "\n";

        else if (i.op == "print")
            std::cout << "print " << i.a1 << "\n";

        else
            std::cout << i.res << " = " << i.a1 << " " << i.op << " " << i.a2 << "\n";
    }
    return 0;
}
