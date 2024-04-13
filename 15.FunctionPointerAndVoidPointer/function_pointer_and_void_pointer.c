#include <stdio.h>

int Add(int num1, int num2)
{
    return num1+num2;
}

void printVoidPoint(void * vptr)
{
    printf("vptr: %p\n", vptr);
}

int main(int argc, char * argv[])
{   
    printf("[*] 함수형 포인터 \n");
    int (*fptr_add)(int, int) = Add;
    int result = fptr_add(3,4);
    printf("%d\n", result);

    printf("\n");

    printf("[*] void 포인터\n");
    int num = 3;
    char ch = 'A';
    char * str = "Hello";
    printVoidPoint(&num);
    printVoidPoint(&ch);
    printVoidPoint(&str);

    printf("\n");

    printf("[*] main 함수의 인자 값\n");
    printf("인자 총 갯수: %d\n", argc);
    for(int i=0; i<argc; i++){
        printf("[%d]: %s\n", i, argv[i]);
    }
    return 0;
}