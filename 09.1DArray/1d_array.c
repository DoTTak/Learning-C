#include <stdio.h>

void showArr(int *arr, size_t len)
{   
    printf(">> ");
    for(int i=0;i<len;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void showChar(char *arr)
{
    printf(">> ");
    int idx = 0;
    while(arr[idx] != '\0')
    {
        printf("%c", arr[idx]);
        idx++;
    }
    printf("\n");
}

int main(void)
{   
    printf("[*] 배열의 선언 및 초기화\n");

    // 배열의 선언
    int arr[5];
    // 배열의 접근
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    printf("int arr[5];\n");
    printf("arr[0] = 10\n");
    printf("arr[1] = 20\n");
    printf("arr[2] = 30\n");
    showArr(arr, 5);
    // 배열의 초기화
    int arr1[5] = {1, 2, 3, 4, 5};
    printf("int arr1[5] = {1, 2, 3, 4, 5};\n");
    showArr(arr1, 5);
    int arr3[] = {1, 2, 3};
    printf("int arr3[] = {1, 2, 3};\n");
    showArr(arr3, (sizeof(arr3) / sizeof(int)));
    int arr2[5] = {1, 2, 3};
    printf("int arr2[5] = {1, 2, 3};\n");
    showArr(arr2, 5);

    printf("\n");

    printf("[*] char형 배열의 문자열 저장과 널(Null) 문자 \n");
    char str1[] = "Hello";
    printf("char str1[] = \"Hello\";\n");
    printf("배열 str의 크기: %lu \n", sizeof(str1));
    printf("널 문자 문자형 출력: %c \n", str1[5]);
    printf("널 문자 정수형 출력: %d \n", str1[5]);
    
    printf("\n");

    printf("[*] 배열을 이용한 문자열 변수\n");
    char name[7] = "DoTTak"; // 'D', 'o', 'T', 'T', 'a', 'k', '\0'의 7개의 문자를 저장
    printf("char name[7] = \"DoTTak\";\n");
    showChar(name);
    char str2[] = "Hello, world!"; // 컴파일러에 의해 자동으로 [] 안에 문자열의 길이 삽입
    printf("char str2[] = \"Hello, world!\";\n");
    showChar(str2);

    printf("\n");
    printf("[*] 문자열 입력 받기\n");
    char str3[100];
    char str4[100];
    char temp;

    printf("scanf()\n");
    printf("아무런 문자를 입력해주세요: ");
    scanf("%s", str3);
    showChar(str3);
    
    while ((temp = getchar()) != '\n' && temp != EOF); // 버퍼 지우기

    printf("fgets()\n");
    printf("아무런 문자를 입력해주세요: ");
    fgets(str4, sizeof(str4), stdin);
    showChar(str4);

    return 0;
}