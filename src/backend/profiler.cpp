#include "profiler.h"
#include <fstream>

static std::unordered_map<std::string,int> counts;

void Profiler::hit(const std::string& label) {
    counts[label]++;
}

void Profiler::dump(const std::string& file) {
    std::ofstream out(file);
    for (auto& p : counts)
        out << p.first << " " << p.second << "\n";
}
