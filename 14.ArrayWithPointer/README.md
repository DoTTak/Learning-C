# 배열과 포인터의 관계

배열과 포인터의 관계는 아래의 내용을 토대로 상당히 밀접하게 연관되어 있습니다. 

- 배열의 이름이 포인터로 해석될 수 있는 점
    - `int arr[5];` 에서 `arr` 은 `arr[0]` 과 동일
- 포인터를 사용하여 배열 요소에 접근할 수 있는 점
    - `arr[i]` 는 `*(arr+i)`와 동일
- 배열의 요소를 포인터의 연산을 통해 접근할 수 있는 점
    - `int arr[3] = {1, 2, 3};` 과 `int *ptr = arr;` 를 사용하여 `arr[2]` 와 `ptr[2]` 는 동일

## 포인터 형

포인터 형은 포인터가 가리키는 메모리 공간에 저장된 데이터의 타입을 나타냅니다. 즉, 포인터 변수를 선언할 때 해당 변수가 가리키는 데이터 타입을 명시해야 하며, 이를 포인터 형이라 합니다.

```c
int arr[3] = {1, 2, 3};
int *ptr = arr; // int형 포인터 형
```

여기서 `ptr` 은 `int` 포인터 형 이며, `ptr` 이 가리키는 메모리 공간에 저장된 데이터 타입은 `int` 입니다.

그래서 `ptr` 을 사용하여 배열 `arr` 의 각 요소에 접근할 수 있습니다.

## 배열 이름의 포인터 형

포인터 형은 포인터가 가리키는 데이터의 타입을 나타내므로, 배열의 차원에 따라 포인터 형이 다르게 적용됩니다.

### 1차원 배열

1차원 배열은 연속된 메모리 공간에 저장된 요소들의 집합으로, 1차원 배열의 포인터 형은 해당 배열의 요소의 데이터 타입을 가리키는 포인터 입니다.

```c
int arr[5]; // int형 1차원 배열

// arr의 포인터 형은 int* (int 형 포인터)
int *ptr = arr;
```

위 코드에서는 `ptr` 은 `arr` 의 첫 번째 요소를 가리키는 포인터로, `int` 형 데이터를 가리킵니다. 따라서, `ptr` 은 `int*` 로 정의됩니다.

### 2차원 배열

2차원 배열은 행, 열의 구조로 메모리에 저장되는 배열입니다. 2차원 배열의 포인터 형은 해당 배열 요소의 데이터 타입을 가리키는 포인터로, 배열의 각 행을 가리키는 포인터로 정의 됩니다.

```c
int arr2D[3][4];

// arr2D의 포인터 형은 int (*)[4] (int 배열의 포인터)
int (*ptr2D) [4] = arr2D;
```

위 코드에서는 `ptr2D` 는 `arr2D` 의 첫 번째 행을 가리키는 포인터로, `int[4]` 형식의 배열을 가리킵니다. 따라서 `ptr2D` 는 `int (*)[4]` 형식의 포인터로 정의 됩니다.

자세히 설명 드리면, 2차원 배열의 포인터 형은 배열의 각 행을 가리키는 포인터이므로, 열의 크기를 명시하여 포인터 형을 정의해야 합니다. 그 이유는 다음의 예제 코드를 통해 확인 하겠습니다.

```c
int arr[3][2]; // 세로: 3, 가로: 2
printf("%p \n", arr);
printf("%p \n", arr+1); // arr + (sizeof(int) * 가로길이(2))

/**
0x16d0bf0c0 
0x16d0bf0c8 
*/
```

위 코드의 경우 2차원 배열 `arr` 을 +1 연산 했을 때, 주소의 값이 `sizeof(int) * 열의크기(가로길이)` 만큼 증가 한 것을 알 수 있습니다.

따라서, 포인터 형을 정의할 때 열의 크기를 명시해야 하는 이유는, 포인터 연산을 할 때 메모리의 주소 값을 올바르게 계산하기 위해서입니다. 그래서 2차원 배열의 포인터 형은 `타입 (*포인터변수이름)[열의크기]` 로 정의하게 됩니다.

> 포인터 배열과 배열 포인터의 혼동을 주의해야 합니다.
> 
> - `int * arr[4];` 포인터 배열 → 배열 선언
> - `int (*arr)[4];` 배열 포인터 → 포인터 변수 선언

## 배열을 함수의 인자로 전달

배열 포인터형을 알 수 있으면 해당 배열을 인자로 받는 함수를 정의할 때, 인자의 데이터 타입을 지정할 수 있습니다.

### 1차원 배열

1차원 배열을 함수의 인자로 전달할 때에는 배열의 이름(포인터)을 사용하여 전달합니다. 또한, 함수 내에서 배열을 변경하려면 포인터를 사용하여 배열 요소에 접근하여 수정할 수 있습니다.

```c
#include <stdio.h>

// 함수 선언: 1차원 배열을 인자로 받는 함수
void printArray(int arr[], int size) { // int arr[] 대신, int * arr 도 가능
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);  // 배열의 크기 계산

    // 배열을 함수에 전달
    printf("Array in main function: ");
    printArray(arr, size);

    return 0;
}

/*
Array in main function: 1 2 3 4 5
*/
```

위 코드에서 1차원 배열을 인자로 받는 포인터 형을 `int 배열이름[]` 으로 지정 했지만 `int *` 도 가능합니다.

### 2차원 배열

2차원 배열을 함수의 인자로 전달할 때는 1차원 배열과 마찬가지로 배열의 이름(포인터)을 사용하여 전달하지만, 2차원 배열은 각 행을 포인터로 가리키는 배열 포인터 형으로 전달해야 합니다.

```c
#include <stdio.h>

// 함수 선언: 2차원 배열을 인자로 받는 함수
void print2DArray(int arr[][3], int rows, int cols) { // arr[][3] 대신, (*arr)[3]도 가능
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int rows = 2;
    int cols = 3;

    // 2차원 배열을 함수에 전달
    printf("Array in main function:\n");
    print2DArray(arr2D, rows, cols);

    return 0;
}
/*
Array in main function:
1 2 3 
4 5 6 
*/
```

위 코드에서 2차원 배열을 인자로 받는 포인터 형을 `int 배열이름[][3]` 으로 지정 했지만, `int (*배열이름)[3]` 도 가능합니다.

## 2차원 배열 포인터의 연산

2차원 배열에서도 `arr[i]` 는 `*(arr+i)` 와 같습니다.

```c
int arr[3][2] = {{1, 2}, {3, 4}, {5, 6}};
```

위 2차원 배열 `arr` 에서 요소 `6` 이 저장된 위치를 다른 값(`4`)으로 변경하는 방법은 다음과 같습니다.

```c
arr[2][1] = 4;
(*(arr+2))[1] = 4;
*(*(arr+2)+1) = 4;
*((arr[2])+1) = 4;
```

# 예제 출력

```bash
$ gcc -o array_with_pointer.o array_with_pointer.c
$ ./array_with_pointer.o
[*] 배열과 포인터의 관계
arr1의 주소: 0x16b73b060, arr1[0]의 주소: 0x16b73b060
arr1[1]: 2, *(arr1+1): 2
arr1[1]: 2, ptr[1]: 2

[*] 2차원 배열의 포인터 형
1 2 3 
4 5 6 

[*] 2차원 배열 포인터의 연산
int arr[3][2] = {{1, 2}, {3, 4}, {5, 6}};
arr[2][1] = 4; 결과: 4
(*(arr+2))[1] = 5; 결과: 5
*(*(arr+2)+1) = 7; 결과: 7
*((arr[2])+1) = 8; 결과: 8
```