#pragma once
#include "../ir/ir_node.h"
#include <vector>
#include <string>

class CodeGen {
public:
    void emitC(const std::vector<IRInstr>& ir, const std::string& outFile);
};