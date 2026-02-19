#include <stdio.h>
#include <string.h>
#include "profiler_runtime.h"
static struct {
    char label[32];
    int count;
} hits[256];

static int n = 0;

void prof_hit(const char* l) {

    for(int i = 0; i < n; i++) {
        if(strcmp(hits[i].label, l) == 0) {
            hits[i].count++;
            return;
        }
    }

    strcpy(hits[n].label, l);
    hits[n].count = 1;
    n++;
}

void prof_dump() {

    FILE* f = fopen("profile.txt", "w");

    for(int i = 0; i < n; i++)
        fprintf(f, "%s %d\n", hits[i].label, hits[i].count);

    fclose(f);
}
