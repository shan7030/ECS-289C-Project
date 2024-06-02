// Link to the Compiler Explorer: https://godbolt.org/z/j8coqj375

// Reproducer:
#include <stdio.h>
bool a, b;
int d, c;
const int &e(const int &f, const int &g) { return !f ? f : g; }
int main() {
  c = e(b, 0) > ((b ? d : b) ?: 8);
  a = b ? d : b;
  printf("%d\n", a);
  if (a != 0)
    __builtin_abort();
}

// Error:
// >$ g++ -O2 driver.cpp && ./a.out 

// 1
// Aborted (core dumped)
// >$ g++ -O0 driver.cpp && ./a.out 

// 0