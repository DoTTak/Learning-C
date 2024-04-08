# 서식문자

## 서식문자란?

서식 문자는 출력 형식을 지정하기 위해 사용되는 문자 입니다. 예를 들어, 정수를 출력하기 위해서는 `%d` 를 사용하고, 소수를 출력하기 위해서는 `%f` 를, 문자를 출력하기 위해서는 `%c` 를 이용합니다.

대표적으로 `printf` 함수를 이용할 때 서식을 지정하여 데이터를 출력할 수 있습니다.

```c
int num=10;
float num2=1.234;
char ch1='A';
printf("정수 출력 %d", num);
printf("소수 출력 %f", num2);
printf("문자 출력 %c", ch1);

/*
정수 출력 10 
소수 출력 1.234000 
문자 출력 A 
*/

```

## 서식문자의 종류

| 서식문자 | 출력 대상(자료형) | 출력 형태 |
| --- | --- | --- |
| `%d` | char, short, int | 부호 있는 10진수 정수 |
| `%ld` | long | 부호 있는 long 형 10진수 정수 |
| `%lld` | long long | 부호 있는 long long 형 10진수 정수 |
| `%u` | unsigned int | 부호 없는 10진수 정수 |
| `%o` | unsigned int | 부호 없는 8진수 정수 |
| `%x`, `%X` | unsigned int | 부호 없는 16진수 정수 (x는 소문자, X는 대문자) |
| `%f` | flat, double | 소수점 이하 6자리까지의 부동소수점 숫자 |
| `%Lf` | long double | long double 형 부동소수점 숫자 |
| `%e`, `%E` | float, double | 지수 표현을 가진 부동소수점 숫자 (e는 소문자, E는 대문자) |
| `%g`, `%G` | float, double | 값에 따라 `%f` 또는 `%e`(`%E`)를 선택하여 출력 |
| `%c` | char, short, int | 단일 문자 |
| `%s` | char * | 문자열 |
| `%p` | void * | 포인터의 주소 |

# 예제 출력

```bash
$ gcc -o format_specifier.o format_specifier.c
$ ./format_specifier.o
%d(char, short, int): 123
%ld(long): 1234567890
%lld(long long): 1234567890123456789
%u(unsigned int): 12345
%o(8진수, unsigned int): 30071
%x or %X(16진수, unsigned int): 3039, 3039
%f(float, double): 1.234567
%Lf(long double): 1.234568
%e or %(E지수 표현, float, double): 1.234568e+00, 1.234568E+00
%g or %G(float, double): 1.23457, 1.23457
%c(char): A
%s(문자열): Hello, World!
%p(포인터의 주소): 0x16bcb7024
```