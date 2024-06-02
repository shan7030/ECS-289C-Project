// Clang produces incorrect result with -O3 -march=skx
//42833
// Reproducer:
#include <stdio.h>

int b;
unsigned c[49];
int d[49];

void i() {
  for (int g = 32; g <= 48; g++) {
    d[g] -= c[g] + b;
    c[g] += c[g] + b;
    b -= b;
  }
}

int main() {
  for (int g = 0; g < 49; ++g)
    c[g] = 3;
  i();
  printf("%d\n", d[36]);
}

// Error:
// >$ clang -O3 -march=skx small.c ; ./a.out

// 0
// >$ clang -O0 -march=skx small.c ; ./a.out

// -3

// LLVM version:
// clang version 10.0.0 (trunk 367162)
// Target: x86_64-unknown-linux-gnu
// Thread model: posix
// Comment 1