#ifndef PROFILER_RUNTIME_H
#define PROFILER_RUNTIME_H

#ifdef __cplusplus
extern "C" {
#endif

void prof_hit(const char* l);
void prof_dump();

#ifdef __cplusplus
}
#endif

#endif
