// It looks like LoopVectorizePass introduces changes that uncover a bug in the backend. The transformation was verified with alive2. I've attached C++ and LLVM IR reproducers.
//Bug 52335 - Incorrect result with -O1 -march=skx
// C++ reproducer:
// func.cpp
extern int var_3;
extern bool var_23;
extern int arr_12[];
extern short arr_13[];
void test() {
#pragma clang loop vectorize_predicate(enable)
  for (char a = 4; a < var_3; a++) {
    arr_13[a] = arr_12[a - 3];
    var_23 = arr_12[a - 1];
  }
}

// driver.cpp 
#include <stdio.h>

int var_3 = 24;
bool var_23 = 1;
int arr_12 [25];
unsigned short arr_13 [25];

void test();

int main() {
    for (size_t i_0 = 0; i_0 < 25; ++i_0)
        arr_12 [i_0] = 1;
    test();
    printf("%d\n", (int)var_23);
}

// >$ clang++ -O0 -march=skx func.cpp driver.cpp && sde -skx -- ./a.out 

// 1
// >$ clang++ -O1 -march=skx func.cpp driver.cpp && sde -skx -- ./a.out 

// 0