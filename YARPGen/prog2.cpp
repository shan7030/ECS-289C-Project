//SLPVectorizer: Assertion
// `isVectorLikeInstWithConstOps(FirstInst) && isVectorLikeInstWithConstOps(I) && "Expected vector-like insts only."' failed with -O3 -march=skx #58616

extern char a[];
const int &c(int &d, const int &f) { return d ? f : d; }
int e, g;
long h;
char *i;
void n(bool d, long f[], int o[][5], long q[], unsigned s[][2][5][12]) {
  for (int j = 0; j < 13; j += 4)
    for (unsigned k(!((d ? q[j] : f[j]) ?: i[j])); k < 2; k += g) {
      const int &r = c(o[j][g], 0);
      int b = r;
      for (short l(b); l; l += 2)
        for (short m = 1; m < 9; m += 3)
          for (bool p(s[j][g][2][3]); s[j][g][2][3] < (bool)h;)
            a[p] = e;
    }
}


