#include <stdio.h>

int main(void)
{
    printf("[*] 2차원 배열\n");
    int arr1[4][3] = {
        {1, 2, 3},
        {10, 20, 30},
        {100, 200, 300},
        {1000, 2000, 3000}
    };
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            printf("arr1[%d][%d](%p): %d\n", i, j, &arr1[i][j], arr1[i][j]);
        }
    }
    
    printf(">> sizeof(arr1): %lu\n", sizeof(arr1));
    printf(">> arr1 address: %p\n", arr1);
    printf(">> arr1[0][0] address: %p\n", &arr1[0][0]);

    printf("\n");

    printf("[*] 3차원 배열\n");
    int arr2[2][3][4] = {
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<4; k++){
                printf("arr2[%d][%d][%d](%p): %d\n", i, j, k, &arr2[i][j][k], arr2[i][j][k]);
            }
        }
    }

    printf(">> sizeof(arr2): %lu\n", sizeof(arr2));
    printf(">> arr2 address: %p\n", arr2);
    printf(">> arr2[0][0][0] address: %p\n", &arr2[0][0][0]);
    return 0;
}