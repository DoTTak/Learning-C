#include <stdio.h>

int main(void) {

    printf("[*] 포인터 변수 \n");
    int num = 20; // 정수형 변수 num을 선언하고 20으로 초기화
    int * pnum; // 정수형 변수의 주소를 저장하는 포인터 변수 pnum을 선언
    pnum = &num; // num 변수의 주소를 pnum에 저장
    printf("변수 num의 값: %d\n", num);
    printf("변수 num의 주소: %p\n", &num);
    printf("변수 num의 주소: %p\n", &num);
    printf("포인터 변수 pnum이 가리키는 주소: %p\n", pnum);
    printf("포인터 변수 pnum이 가리키는 주소: %p\n", pnum);
    printf("포인터 변수 pnum이 가리키는 주소의 값: %d\n", *pnum);

    printf("\n");

    printf("[*] 포인터와 배열의 관계\n");
    int arr[] = {1, 2, 3}; // 배열 선언
    int *ptr = arr; // 포인터 변수에 배열의 주소 저장
    printf("배열의 첫 번째 요소: %d \n", arr[0]); // 배열 인덱싱
    printf("포인터를 통한 첫 번째 요소 접근: %d \n", *ptr); // 포인터를 통한 값 접근
    printf("%d %d\n", arr[0], ptr[0]);
    printf("%d %d\n", arr[1], ptr[1]);
    printf("%d %d\n", arr[2], ptr[2]);

    printf("\n");

    printf("[*] 포인터 연산 1\n");
    int numArr[3] = {11, 22, 33};
    int *ptr2 = numArr;
    printf("%d \n", *ptr2);     // 11: 포인터가 가리키는 메모리 주소의 값 출력
    printf("%d \n", *(ptr2 + 1)); // 22: 포인터가 가리키는 메모리 주소에서 한 단위 더한 메모리 주소의 값 출력
    printf("%d \n", *(ptr2 + 2)); // 33: 포인터가 가리키는 메모리 주소에서 두 단위 더한 메모리 주소의 값 출력
    printf("%ld \n", ptr2 + 2 - ptr2); // 2: 두 메모리 주소의 거리 출력

    printf("\n");

    printf("[*] 포인터 연산 2 (ptr[i] == *(ptr + i))\n");
    int arr3[3] = {10, 20, 30};
    int * ptr3 = arr3;
    printf("%d %d %d \n", *(ptr3+0), *(ptr3+1), *(ptr3+2));    // *(ptr3+0) 은 *ptr과 동일
    printf("%d %d %d \n", ptr3[0], ptr3[1], ptr3[2]);

    printf("\n");
    
    printf("[*] 변수형 문자열과 상수형 문자열\n");
    char str1[] = "Hello, Wolrd!";
    str1[0]='X';
    printf("%s \n", str1);
    char * str2 = "Hello, Wolrd!";
    str2 = "Hi C Language";
    printf("%s \n", str2);

    printf("\n");
    
    printf("[*] 포인터 배열\n");
    int num1 = 10, num2 = 20, num3 = 30;
    int * arr2[3] = {&num1, &num2, &num3};

    printf("%d \n", *arr2[0]);
    printf("%d \n", *arr2[1]);
    printf("%d \n", *arr2[2]);
    
    printf("\n");
    
    printf("[*] 문자열을 저장하는 포인터 배열\n");
    char * strArr[3] = {"Hello", "C Language", "~!"};
    printf("%s \n", strArr[0]);
    printf("%s \n", strArr[1]);
    printf("%s \n", strArr[2]);

    return 0;
}
