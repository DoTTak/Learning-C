#include <stdio.h>

void showArr(int * arr, int len){ // int * arr 대신, int arr[] 도 가능
	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
    printf("\n");
}

void callByValue(int x) // Call-by-Value
{
    x = 20;
}

void callByReference(int* pX) // Call-by-Reference
{
    *pX = 20;
}

void modifyArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] += 1;
    }
}

int main(void)
{
    printf("[*] 함수의 인자 값으로 배열을 전달\n");
    int arr[5] = {11, 22, 33, 44, 55};
    showArr(arr, sizeof(arr)/sizeof(int));
    
    printf("\n");

    printf("[*] Call-by-Value\n");
    int x = 10;
    printf("Before function call, x = %d\n", x);
    callByValue(x);
    printf("After function call, x = %d\n", x);

    printf("\n");
    
    printf("[*] Call-by-Reference\n");
    printf("Before function call, x = %d\n", x);
    callByReference(&x);
    printf("After function call, x = %d\n", x);

    printf("\n");

    printf("[*] Call-by-Reference with Array\n");
    int arr2[] = {10, 20, 30, 40};
    int size = sizeof(arr2) / sizeof(int);

    printf("Before modification: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    modifyArray(arr2, size);

    printf("After modification: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}