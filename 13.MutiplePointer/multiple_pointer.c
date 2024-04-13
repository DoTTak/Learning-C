#include <stdio.h>

void Increment(int **dptr)
{
    (**dptr)++;
}

int main() {
    printf("[*] 이중 포인터(더블 포인터)\n");
    int num = 10;
    int *ptr = &num;
    int **dptr = &ptr;
    printf("num 주소: %9p, num 값: %d\n", &num, num);
    printf("ptr 주소: %9p, ptr의 값: %9p\n", &ptr, ptr);
    printf("dptr 주소: %9p, dptr의 값: %9p\n", &dptr, dptr);
    
    printf("ptr이 가리키는 변수 num의 값: %d\n", *ptr);
    printf("dptr이 가리키는 포인터 변수 ptr이 가리키는 변수 num의 값: %d\n", **dptr);

    printf("\n");

    printf("[*] 포인터 변수의 Call-By-Reference\n");
    int num2=10;
    int * ptr2 = &num2;
    int ** dptr2 = &ptr2;
    printf("num2의 값: %d\n", num2);
    Increment(dptr2);
    printf("num2의 값: %d\n", num2);

    printf("\n");
    printf("[*] 포인터 배열의 포인터 형\n");
    int n1=10, n2=20, n3=30;
    printf("n1(%p): %d\n", &n1, n1);
    printf("n2(%p): %d\n", &n2, n2);
    printf("n3(%p): %d\n", &n3, n3);
    int * nptr1=&n1;
    int * nptr2=&n2;
    int * nptr3=&n3;
    int * ptrArr[3] = {nptr1, nptr2, nptr3};
    printf("ptrArr의 주소: %p\n", ptrArr);
    for(int i=0; i<3; i++){
        printf("ptrArr[%d]의 주소: %p, 저장된 값: %p, 저장된 값이 가리키는 값: %d\n", i, &ptrArr[i], ptrArr[i], *(ptrArr[i]));
    }

    printf("\n");
    printf("[*] 삼중 포인터\n");
    int num3 = 10;
    int *ptr3 = &num3;
    int **dptr3 = &ptr3;
    int ***tptr3 = &dptr3;

    printf("num3 주소: %9p, num3 값: %d\n", &num3, num3);
    printf("ptr3 주소: %9p, ptr3의 값: %9p\n", &ptr3, ptr3);
    printf("dptr3 주소: %9p, dptr3의 값: %9p\n", &dptr3, dptr3);
    printf("tptr3 주소: %9p, tptr3의 값: %9p\n", &tptr3, tptr3);

    printf("ptr3이 가리키는 변수 num3의 값: %d\n", *ptr3);
    printf("dptr3이 가리키는 포인터 변수 ptr3이 가리키는 변수 num3의 값: %d\n", **dptr);
    printf("tptr3이 가리키는 이중 포인터 변수 dptr3이 가리키는 포인터 변수 ptr3이 가리키는 변수 num3의 값: %d\n", ***tptr3);
    return 0;
}
