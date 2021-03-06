// These functions were introduced in GCC 3.3
// You need to add -mmmx and -msse to the compiler 
// configuration (for gcc to enable these).

#if 0
// Builtin functions specific to GNU 4.4.1 (likely 4.4.x)
int __builtin_ia32_psllwi(short,int);
int __builtin_ia32_pslldi(int,int);
int __builtin_ia32_psllqi(long long,int);
int __builtin_ia32_psrawi(short,int);
int __builtin_ia32_psradi(int,int);
int __builtin_ia32_psrlwi(int,int);
int __builtin_ia32_psrldi(int,int);
int __builtin_ia32_psrlqi(long long,int);
#endif

// int __builtin_ia32_paddq(long long,long long);

#ifdef __INTEL_COMPILER
// Added type for Intel compilers.
// typedef __m64 v2si;
// typedef unsigned long int __m64;
// typedef __v2si __m64;
// #define __m64
#endif

#ifdef __MMX__
//#error "Note: __MMX__ is defined"
  #include<emmintrin.h>
#endif

int main()
   {
     return 0;
   }
