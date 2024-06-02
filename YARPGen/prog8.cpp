// The same reproducer also triggers ICE for Sapphire Rapids with a different stack trace.

// Link to the Compiler Explorer: https://godbolt.org/z/nxqPhnnoe

// Reproducer:
bool a[80];
short b, f;
void g(short h[][8][16]) {
  for (bool c = 0; c < b;)
    for (bool d = 0; d < (bool)f; d = 1)
      for (short e = 0; e < 16; e++)
        a[e] = h[b][1][e];
}

// Error:
// >$ g++ -O3 -c func.cpp