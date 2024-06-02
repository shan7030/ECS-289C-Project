// Clang generates incorrect code with -m32 -O0 -march=skx options (same problem for knl). Everything works fine with -m64 and other optimizations levels.
// Bug 32241 - Incorrect result with -march=skx -O0 -m32
// Reproducer:
#include <iostream>

int main () {
    unsigned short aa = 10959;
    unsigned short bb = 50038;
    short cc = 19417;
    bb = ~(aa < (cc || 0)) || 0;
    std::cout << bb << std::endl;
    return 0;
}

// >$ clang++ -m32 -w -O0 -march=skx repr.cpp ; sde -skx -- ./a.out

// 0
// >$ clang++ -m32 -w -O0 repr.cpp ; ./a.out

// 1