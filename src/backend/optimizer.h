#pragma once
#include "../ir/ir_node.h"
#include <vector>
#include <string>
#include <unordered_map>

class Optimizer {
public:
    void loadProfile(const std::string& file);
    void optimize(std::vector<IRInstr>& ir);

private:
    std::unordered_map<std::string,int> hot;

    void hotLoopUnroll(std::vector<IRInstr>& ir);
    void constantFold(std::vector<IRInstr>& ir);
    void deadCodeElimination(std::vector<IRInstr>& ir);
};

