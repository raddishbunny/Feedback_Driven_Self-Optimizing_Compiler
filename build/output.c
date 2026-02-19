#include "profiler_runtime.h"
#include <stdio.h>

int main() {
int N = 10;
int a = 0;
prof_hit("L0");
L0:
int t0 = a < N;
if (t0 == 0) goto L1;
int t1 = a + 1;
a = t1;
prof_hit("L0");
goto L0;
prof_hit("L1");
L1:
printf("%d\n", a);
prof_dump();
return 0;
}
