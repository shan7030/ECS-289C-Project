//[NewGVN] Assertion `BeforeCC->isEquivalentTo(AfterCC) && "Value number changed after main loop completed!"' failed #53807
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
int a, b, c, d;
unsigned e;
char f;
long g(long i, long n) { return n ? n : i; }
char o(char i, char n) { return n < i; }
short *p;
void q(bool i[][3][2][1], char n[][3][2][1]) {
  for (short h; e ; h = 109)
    for (int l = 0; e;)
      for (int m = 0; e ;) {
        for (short j = 0; j < f; j = 4)
          ;
        for (unsigned k = 0; 0 < b; k = 90) {
          a = o(n[h][l][m][k] ? i[h][l][m][k] : 0, i[h][l][m][k]);
          c = g(d ? d : p[k], i[109][0][0][k]);
        }
      }
}

//>$ clang++ -O3 -fopenmp-simd -mllvm -enable-newgvn -c func.cpp
//clang++: /testing/llvm/llvm_src_main/llvm/lib/Transforms/Scalar/NewGVN.cpp:3307: void {anonymous}::NewGVN::verifyIterationSettled(llvm::Function&): Assert
//ion `BeforeCC->isEquivalentTo(AfterCC) && "Value number changed after main loop completed!"' failed.