#include <stdio.h>

void show2DArray(int arr[][3], int rows, int cols) // arr[][3] 대신, (*arr)[3]도 가능
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    } 
}

int main() {

    printf("[*] 배열과 포인터의 관계\n");
    int arr1[5] = {1, 2, 3, 4, 5};
    int * ptr1 = arr1;
    printf("arr1의 주소: %p, arr1[0]의 주소: %p\n", arr1, &arr1[0]);
    printf("arr1[1]: %d, *(arr1+1): %d\n", arr1[1], *(arr1+1));
    printf("arr1[1]: %d, ptr[1]: %d\n", arr1[1], ptr1[1]);

    printf("\n");

    printf("[*] 2차원 배열의 포인터 형\n");
    int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int rows = 2;
    int cols = 3;
    show2DArray(arr2, rows, cols);

    printf("\n");

    printf("[*] 2차원 배열 포인터의 연산\n");
    int arr[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    printf("int arr[3][2] = {{1, 2}, {3, 4}, {5, 6}};\n");
    arr[2][1] = 4;
    printf("arr[2][1] = 4; 결과: %d\n", arr[2][1]);
    (*(arr+2))[1] = 5;
    printf("(*(arr+2))[1] = 5; 결과: %d\n", arr[2][1]);
    *(*(arr+2)+1) = 7;
    printf("*(*(arr+2)+1) = 7; 결과: %d\n", arr[2][1]);
    *((arr[2])+1) = 8;
    printf("*((arr[2])+1) = 8; 결과: %d\n", arr[2][1]);

    return 0;
}