#include <stdio.h>

int main(void)
{
    int num = 30 + 40; // 30과 40은 상수입니다.
    
    printf("[*] 리터럴 상수\n");
    printf("상수 %d과 %d를 더한 결과를 int형 변수 num에 저장 후 num의 값은? %d\n", 30, 40, num);
    
    printf("\n");
    
    printf("[*] 리터럴 상수의 크기\n");
    printf("int형 리터럴 상수의 크기 %lu\n", sizeof(10));
    printf("double형 리터럴 상수의 크기 %lu\n", sizeof(1.234));
    printf("char형 리터럴 상수의 크기 %lu\n", sizeof('A'));
    
    printf("\n");

    printf("[*] char형 리터럴 상수의 크기와 char형 변수의 크기\n");
    char ch1 = 'A';
    printf("char형 리터럴 상수의 크기: %lu, char형 변수의 크기: %lu\n", sizeof('A'), sizeof(ch1));
    printf("char형 리터럴 상수 'A'와 int형 리터럴 상수 10을 덧셈할 때의 크기는? %lu \n", sizeof('A'+15));
    printf("char형 변수 ch1과 int형 리터럴 상수 10을 덧셈할 때의 크기는? %lu \n", sizeof(ch1+15));

    printf("\n");

    printf("[*] 접미사를 이용한 상수의 표현\n");
    printf("15U (unsigned int)의 크기 %lu \n", sizeof(15U));
    printf("123456789L (long)의 크기 %lu \n", sizeof(123456789L));
    printf("123456789012345LL (long long)의 크기 %lu \n", sizeof(123456789012345LL));
    printf("1.23F (float)의 크기 %lu \n", sizeof(1.23F));
    printf("1.23L (long double)의 크기 %lu \n", sizeof(1.23L));

    return 0;
}