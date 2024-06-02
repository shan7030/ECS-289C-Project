// Created attachment 38187 [details]
// Reproducer.

// Test case produces incorrect result with -O3 -mavx2 (and -march=knl and -march=skylake-avx512. Everything works fine with gcc version 4.9.4 20160401 (prerelease) (Revision=234686) and gcc version 5.3.1 20160401 (Revision=234686).

// Output:
// g++ -O2 -mavx2 repr.cpp; ./a.out
// 1540
// > g++ -O3 -mavx2 repr.cpp; ./a.out

// 1204

// GCC version:
// > g++ -v

// Using built-in specs.
// COLLECT_GCC=g++
// COLLECT_LTO_WRAPPER=/export/users/vlivinsk/gcc-trunk/bin/libexec/gcc/x86_64-pc-linux-gnu/6.0.0/lto-wrapper
// Target: x86_64-pc-linux-gnu
// Configured with: /export/users/vlivinsk/gcc-trunk/gcc/configure --with-arch=corei7 --with-cpu=corei7 --enable-clocale=gnu --with-system-zlib --enable-shared --with-demangler-in-ld --enable-cloog-backend=isl --with-fpmath=sse --enable-checking=release --enable-languages=c,c++,lto --with-gmp=/export/users/vlivinsk/gcc-trunk/gmp-6.1.0/bin --with-mpfr=/export/users/vlivinsk/gcc-trunk/mpfr-3.1.3/bin --with-mpc=/export/users/vlivinsk/gcc-trunk/mpc-1.0.3/bin --prefix=/export/users/vlivinsk/gcc-trunk/bin
// Thread model: posix
// gcc version 6.0.0 20160404 (experimental) (Revision=234705)


#include <cstdlib>

int a[520];
short b[482];
short c[480];
int d[963];
short e[320];

int main() {
    for (int i = 0; i < 520; ++i)
        a[i] = -636544305;

    for (int i = 0; i < 386; ++i)
        b[i] = -31804;

    for (long i = 1; i <= 112; ++i) {
        c[i] = b[i] >> ((a[i] & 1587842570) - 1510214139);
        if (a[i])
            d[i] = i;
        e[i] = 7 << ((2312631697 - b[i]) - 2312663500);
    }

    unsigned long long g = 0;
    for (int i = 0; i < 111; ++i) {
        g = e[i] + g;
    }

    if (g != 1540)
        abort();
}