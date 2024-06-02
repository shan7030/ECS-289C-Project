unsigned long long int tf_3_var_118 = 12702665990007799801ULL;
unsigned char tf_3_var_84 = 195;
unsigned long int tf_3_var_220 = 10859745545766433084UL;
unsigned char tf_3_var_108 = 183;
unsigned long int tf_3_array_1 [2] = {3625445792498952486UL, 1515764644577139006UL};
unsigned long int tf_3_array_4 [2] = {6823003974340523417ul, 8985037393681294663ul};
unsigned long int tf_3_var_132 = 5052410635626804928UL;
void foo() {
  tf_3_var_118 = char(tf_3_var_118) < tf_3_var_84;
  tf_3_var_220 = (tf_3_var_108 ? tf_3_array_1[0] : 0) -
                 (tf_3_array_4[1] * tf_3_var_118 ? 1 : tf_3_var_132);
}

int main() {
    foo();
    __builtin_printf("%lld, %ld\n", tf_3_var_118, tf_3_var_220);
    return 0;
}

// > g++ f.cpp -o out -O0; ./out

// 1, 3625445792498952485
// > g++ f.cpp -o out -O2; ./out

// 1, -142696484312785244