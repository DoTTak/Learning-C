#include <stdio.h>

int main(void)
{
    /* 변수의 선언 및 초기화 */
    int num1; // 정수형(int) 변수 num의 선언
    num1=10; // 변수 num을 10으로 초기화
    num1=20; // 변수 num에 20을 대입

    /* 여러 개의 변수 선언 및 초기화 */
    int num2, num3; // 변수 num2, num3 선언
    int num4=40, num5=50; // 변수 num4, num5을 선언하고 각각 10과 20으로 초기화

    /* 초기화 되지 않은 변수에 값 할당 */
    num2=20;
    num3=30;

    /* 정수형 변수의 출력 */
    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    printf("num3: %d\n", num3);
    printf("num4: %d\n", num4);
    printf("num5: %d\n", num5);

    return 0;
}