// gcc trunk, rev250545, x86_64.
// Bug 81556 - [7/8 Regression] Wrong code at -O2
// This one seems to be different from previously reported bugs. Minimum opt level to trigger bug is -O2, switching slsr doesn't help (-fno-tree-slsr).

// > cat f.cpp

#include <stdio.h>

unsigned long int var_0 = 13272098465497875865UL;
unsigned long int var_1 = 15341539099603541390UL;
unsigned long int var_2 = 2;
unsigned long int var_3 = 17471558040813171499UL;
unsigned long int var_4 = 1;
unsigned long int var_5 = 0;
unsigned long int var_6 = 0;

void foo() {
  bool a = var_2 > 1;
  var_5 = var_4 % ((var_2 > 1) << 9);
  var_6 = a & (var_3 & (a & var_0 & var_1));
}

int main() {
  foo();
  printf("0x%llx, 0x%llx\n", var_5, var_6);
  return 0;
}

// > g++ -O0 f.cpp -o out; ./out

// 0x1, 0x0

// > g++ -O2 f.cpp -o out; ./out

// 0x1, 0x9020100000000108