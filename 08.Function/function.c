#include <stdio.h>

// 선 함수 선언
int add(int num1, int num2);
int inputNum(void);
void showNum(int num);
void init(void);

int global_num=10; // 전역변수

void testLocalGlobalVariable() {
    int local_var = 20; // 지역변수
    printf("함수 내부 - 전역변수: %d, 지역변수: %d \n", global_num, local_var);
}

void Counter() {
    static int count = 0; // static 변수
    count++;
    printf("Count: %d\n", count);
}

int factorial(int n)
{
    if (n == 0)  // 종료 조건
        return 1;
    else
        return n * factorial(n - 1);  // 재귀 호출
}

int main(void)
{   
    printf("[*] 반환 값, 전달 인자에 따른 함수 형태 \n");
    init(); // 반환 값 X, 전달 인자 X
    int i_num1=inputNum(); // 반환 값 O, 전달 인자 X
    showNum(i_num1); // 반환 값 X, 전달 인자 O
    int i_num2=inputNum(); // 반환 값 O, 전달 인자 X
    showNum(i_num2); // 반환 값 X, 전달 인자 O
    int sum_i_num=add(i_num1, i_num2); // 반환 값 O, 전달 인자 O
    printf("합계 결과\n");
    showNum(sum_i_num); // 반환 값 X, 전달 인자 O

    printf("\n");

    printf("[*] 지역변수와 전역변수 \n");
    printf("함수 외부 - 전역변수: %d\n", global_num);
    testLocalGlobalVariable();
    
    printf("\n");

    printf("[*] static 변수 \n");
    Counter();
    Counter();
    Counter();

    printf("\n");

    printf("[*] 재귀 함수 \n");
    int num=5;
    printf("%d 팩토리얼은? %d\n", num, factorial(num));

    return 0;
}

int add(int num1, int num2)
{
	return num1+num2;
}

int inputNum(void)
{
	int num;
    printf("숫자를 입력하세요: ");
	scanf("%d", &num);
	return num;
}

void showNum(int num)
{
	printf("num: %d \n", num);
}

void init(void)
{
	printf("두 개의 정수를 입력하시면 덧셈결과가 출력됩니다. \n");
}