#include "profiler_runtime.h"

int main() {
    prof_hit("L0");
    prof_hit("L0");
    prof_hit("L1");
    prof_dump();
    return 0;
}
