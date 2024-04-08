#include <stdio.h>

int main(void)
{
    char c = 'A';
    int i = 123;
    long l = 1234567890L;
    long long ll = 1234567890123456789LL;
    unsigned int u = 12345U;
    float f = 1.234567F;
    double d = 1.2345678901234;
    long double ld = 1.234567890123456789L;
    char* str = "Hello, World!";
    void* p = &i;

    printf("%%d(char, short, int): %d\n", i);
    printf("%%ld(long): %ld\n", l);
    printf("%%lld(long long): %lld\n", ll);
    printf("%%u(unsigned int): %u\n", u);
    printf("%%o(8진수, unsigned int): %o\n", u);
    printf("%%x or %%X(16진수, unsigned int): %x, %X\n", u, u);
    printf("%%f(float, double): %f\n", f);
    printf("%%Lf(long double): %Lf\n", ld);
    printf("%%e or %%(E지수 표현, float, double): %e, %E\n", d, d);
    printf("%%g or %%G(float, double): %g, %G\n", d, d);
    printf("%%c(char): %c\n", c);
    printf("%%s(문자열): %s\n", str);
    printf("%%p(포인터의 주소): %p\n", p);

    return 0;
}