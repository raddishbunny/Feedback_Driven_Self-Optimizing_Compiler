#pragma once
#include <unordered_map>
#include <string>

class Profiler {
public:
    static void hit(const std::string& label);
    static void dump(const std::string& file);
};
