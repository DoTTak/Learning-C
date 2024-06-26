# 포인터

## 포인터 변수

포인터 변수는 주소를 저장하기 위한 변수입니다. 포인터 변수는 특정 자료형의 변수 주소만을 저장할 수 있으며, 이를 위해 선언 시에 해당 변수가 어떤 자료형의 주소를 저장할 것인지를 명시해야 합니다. 

예를 들어, `int *ptr;`라고 선언하면, `ptr`는 정수형 변수의 주소를 저장하는 포인터 변수가 됩니다.

## 포인터 변수 구조

```c
type * ptr; // type 형 변수의 주소 값을 저장하는 포인터 변수 ptr
```

포인터 변수는 위 구조와 같이 `type` 에 자료형을 명시해야 합니다. 이는 `*` 연산자가 포인터 변수가 가리키는 변수의 메모리 주소에 접근하려 할 때, 해당 주소로부터 얼마만큼 읽어들여야 할지 결정해주기 때문입니다.

즉, 포인터의 형(자료형)이 존재하는 이유는 포인터 기반의 메모리 접근 기준을 마련하기 위함입니다.

## 포인터 관련 연산자 (`&`, `*`)

`&` 연산자는 변수의 주소를 반환하고, `*` 연산자는 포인터가 가리키는 변수의 값을 반환합니다. 

```c
int num = 10; // 정수형 변수 num을 선언하고 10으로 초기화
int * pnum = &num; // 정수형 변수의 주소를 저장하는 포인터 변수 pnum에 
									 // num변수의 메모리 주소 값을 저장
printf("%d", *pnum); // 포인터 변수 pnum이 가리키는 변수의 값을 출력
```

## 포인터 변수의 크기

포인터 변수의 크기는 32비트 시스템에서는 주소 값을 32비트로 표현하기 때문에 4바이트이며, 64비트 시스템에서는 주소 값을 64비트로 표현하기 때문에 8바이트 입니다.

```c
#include <stdio.h>

int main() {
    int num = 20; // 정수형 변수 num을 선언하고 20으로 초기화
    int * pnum; // 정수형 변수의 주소를 저장하는 포인터 변수 pnum을 선언

    pnum = &num; // num 변수의 주소를 pnum에 저장

    printf("변수 num의 값: %d\\n", num);
    printf("변수 num의 주소: %p\\n", &num);
    printf("포인터 변수 pnum이 가리키는 주소: %p\\n", pnum);
    printf("포인터 변수 pnum이 가리키는 주소의 값: %d\\n", *pnum);

    return 0;
}

```

위 코드는 포인터 pnum을 사용해서 정수형 변수 num의 메모리 주소에 접근하고 값을 출력하는 예제입니다.

# 배열과 포인터

## 배열의 이름

```c
int main(void)
{
		int arr[3] = {0, 1, 2};
    printf("배열의 이름: %p \n", arr);
    printf("첫 번째 요소: %p \n", &arr[0]);
    printf("두 번째 요소: %p \n", &arr[1]);
    printf("세 번째 요소: %p \n", &arr[2]);
	return 0;
}

/**
배열의 이름: 0x16eeef108 
첫 번째 요소: 0x16eeef108 
두 번째 요소: 0x16eeef10c 
세 번째 요소: 0x16eeef110 
*/
```

배열의 이름은 해당 배열이 시작되는 메모리의 위치, 즉 배열의 첫 번째 요소의 주소를 나타냅니다. 그래서 이 배열 이름은 상수로 취급되며, 다른 값으로 변경할 수 없습니다. 또한, 배열에서 각 요소의 주소 값은 이전 요소의 주소 값에서 해당 요소의 데이터 타입 크기만큼 증가한 값이 됩니다. 예를 들어, 정수형 배열에서 각 요소의 주소 값은 이전 요소의 주소 값보다 4바이트만큼 증가한 값이 됩니다.

## 포인터 변수와 배열 이름 비교

**비교 1) 정의**

포인터 변수는 메모리 주소를 저장하는 변수입니다. 이는 특정 자료형의 변수 주소만을 저장할 수 있으며, 선언 시에 해당 변수가 어떤 자료형의 주소를 저장할 것인지를 명시해야 합니다. 예를 들어, `int *ptr;`라고 선언하면, `ptr`는 정수형 변수의 주소를 저장하는 포인터 변수가 됩니다. 반면에 배열 이름은 해당 배열이 시작되는 메모리의 위치, 즉 배열의 첫 번째 요소의 주소를 나타냅니다.

그리고 배열의 이름은 주소 값의 변경이 불가능하므로 ‘포인터 상수’라고도 불립니다.

**비교 2) 값 변경 가능**

포인터 변수의 값은 변경 가능합니다. 즉, 포인터 변수는 다른 메모리 주소를 가리킬 수 있습니다. 그러나 배열 이름은 배열의 첫 번째 요소의 주소를 나타내므로, 이는 변경할 수 없습니다.

**비교 3) 인덱싱 가능**

포인터 변수와 배열 이름 모두 인덱싱이 가능합니다. 포인터 변수의 경우, 인덱싱을 통해 포인터가 가리키는 메모리 주소에서 특정 위치의 값을 참조하거나 변경할 수 있습니다. 배열의 경우, 인덱싱을 통해 배열의 특정 요소에 접근할 수 있습니다.

**비교 4) 포인터 연산 가능**

포인터 변수는 포인터 연산이 가능합니다. 이는 포인터가 가리키는 메모리 주소를 증가시키거나 감소시키는 것을 의미합니다. 예를 들어, `ptr++` 연산은 포인터가 가리키는 메모리 주소를 다음 메모리 주소로 이동시킵니다. 그러나 배열 이름은 포인터 연산을 수행할 수 없습니다.

**비교 5) 메모리 할당**

포인터 변수는 동적 메모리 할당을 통해 메모리를 할당받을 수 있습니다. 이는 `malloc`, `calloc` 등의 함수를 사용하여 실행시간 동안 메모리를 할당하는 것을 의미합니다. 반면에 배열은 선언 시점에서 고정된 크기의 메모리를 할당받습니다. 이를 정적 메모리 할당이라고 합니다.

**비교  6) 초기화**

포인터 변수는 초기화하지 않아도 됩니다. 그러나 안전한 프로그래밍을 위해 포인터 변수를 NULL로 초기화하는 것이 좋습니다. 배열은 선언과 동시에 초기화할 수 있으며, 초기화하지 않은 배열 요소는 해당 자료형의 기본값으로 초기화됩니다.

### 정리

|  | 포인터 변수 | 배열 이름 |
| --- | --- | --- |
| 정의 | 주소 저장 변수 | 첫 번째 요소 주소 |
| 값 변경 가능 | Yes | No |
| 인덱싱 가능 | Yes | Yes |
| 포인터 연산 가능 | Yes | No |
| 메모리 할당 | 동적 | 정적 |
| 초기화 | No | Yes |

### 코드 예시

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // 포인터 변수와 배열 이름 비교 예시

    // 포인터 변수 정의
    int var = 20;
    int *ptr = &var;
    printf("포인터 변수 값: %d \\n", *ptr); // 주소 저장 변수 예시

    // 배열 이름 정의
    int arr[3] = {10, 20, 30};
    printf("배열 첫 번째 요소 값: %d \\n", arr[0]); // 첫 번째 요소 주소 예시

    // 값 변경 가능성
    *ptr = 30; // Yes
    // arr = {10, 20, 40}; // No, 에러 발생

    // 인덱싱 가능성
    printf("포인터 변수의 인덱싱: %d \\n", ptr[0]); // Yes
    printf("배열의 인덱싱: %d \\n", arr[1]); // Yes

    // 포인터 연산 가능성
    ptr++; // Yes
    // arr++; // No, 에러 발생

    // 메모리 할당
    int *dynamicPtr = (int *) malloc(sizeof(int) * 3); // 동적
    // 배열은 정적 할당

    // 초기화
    // 포인터 변수는 초기화하지 않아도 된다.
    int arr2[3] = {10, 20, 30}; // 배열은 초기화한다.

    return 0;
}
/*
포인터 변수 값: 20 
배열 첫 번째 요소 값: 10 
포인터 변수의 인덱싱: 30 
배열의 인덱싱: 20 
*/
```

## 포인터와 배열의 관계

```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3}; // 배열 선언
    int *ptr = arr; // 포인터 변수에 배열의 주소 저장
    printf("배열의 첫 번째 요소: %d \n", arr[0]); // 배열 인덱싱
    printf("포인터를 통한 첫 번째 요소 접근: %d \n", *ptr); // 포인터를 통한 값 접근
    
    return 0;
}
/*
배열의 첫 번째 요소: 1 
포인터를 통한 첫 번째 요소 접근: 1 
1 1
2 2
3 3
*/
```

# 포인터 연산

## 포인터 연산 예시

포인터 연산자를 사용하면 포인터가 가리키는 메모리 주소를 직접 조작할 수 있습니다. 포인터 연산의 대표적인 예로는 포인터 증가(`++`)와 감소(`--`)가 있습니다. 이 연산자들은 포인터가 가리키는 메모리 주소를 한 단위 증가시키거나 감소시킵니다. 또한, 포인터 간의 뺄셈도 가능합니다. 이는 두 메모리 주소 간의 거리를 구할 때 사용됩니다.

```c
int numArr[3] = {11, 22, 33};
int *ptr2 = numArr;
printf("%d \n", *ptr2);     // 11: 포인터가 가리키는 메모리 주소의 값 출력
printf("%d \n", *(ptr2 + 1)); // 22: 포인터가 가리키는 메모리 주소에서 한 단위 더한 메모리 주소의 값 출력
printf("%d \n", *(ptr2 + 2)); // 33: 포인터가 가리키는 메모리 주소에서 두 단위 더한 메모리 주소의 값 출력
printf("%ld \n", ptr2 + 2 - ptr2); // 2: 두 메모리 주소의 거리 출력

/*
11 
22 
33 
2 
*/
```

위의 코드에서 `ptr + 1`은 포인터 `ptr`이 가리키는 메모리 주소에서 한 단위 더한 메모리 주소를 나타냅니다. 이 때 한 단위는 `ptr`이 가리키는 자료형, 즉 `int`의 크기와 같습니다. 따라서 `ptr + 1`은 `ptr`이 가리키는 메모리 주소에서 `sizeof(int)`만큼 떨어진 위치를 나타냅니다.

## arr[i] == *(arr+1)

```c
#include <stdio.h>

int main(void)
{
    int arr[3] = {10, 20, 30};
    int * ptr = arr;

    printf("%d %d %d \n", *(ptr+0), *(ptr+1), *(ptr+2));    // *(ptr+0) 은 *ptr과 동일
    printf("%d %d %d \n", ptr[0], ptr[1], ptr[2]);

    printf("%d %d %d \n", *(arr+0), *(arr+1), *(arr+2));    // *(arr+0) 은 *arr과 동일
    printf("%d %d %d \n", arr[0], arr[1], arr[2]);

    return 0;
}
/**
10 20 30 
10 20 30 
10 20 30 
10 20 30 
*/
```

# 상수 형태의 문자열을 가리키는 포인터

문자열을 가리키는 포인터는 문자 배열과 유사합니다. 그러나 문자열을 가리키는 포인터는 문자열의 내용을 변경할 수 없습니다. 이는 문자열이 상수로 처리되기 때문입니다.

## 변수 형태의 문자열(문자 배열)

```c
char str[] = "Hello, Wolrd!";
```

위 코드의 `str`은 문자 배열로 배열을 대상으로 특정 요소의 문자는 변경 가능하나, 가리키는 대상은 변경할 수 없습니다.

- `str1 = "Your String";`  불가능
- `str1[0] = 'X';` 가능

## 상수 형태의 문자열(문자열 포인터)

```c
char *str = "Hello, World!";
```

위의 코드에서 `str`은 "Hello, World!"라는 문자열을 가리키는 포인터입니다. `str`을 통해 문자열의 내용을 읽어올 수 있지만, 문자열의 내용을 변경할 수는 없습니다.

- `str2 = "Your String";`  가능
- `str2[0] = 'X';` 불가능

## 문자열 포인터와 문자 배열의 차이 정리

|  | 문자 배열(변수 형태의 문자열) | 문자열을 가리키는 포인터(상수 형태의 문자열) |
| --- | --- | --- |
| 내용 변경 | 변경 가능 | 변경 불가 (문자열이 상수로 처리) |
| 메모리 저장 | 문자열을 메모리에 직접 저장 | 메모리에 할당된 문자열 위치를 가리킴 |
| 길이 계산 | 선언 시 문자열의 길이를 자동으로 계산하여 메모리 할당 | 자동 계산하지 않음 |
| 메모리 할당 | 정적 메모리 할당을 사용하여 배열 크기 변경 불가 | 동적으로 메모리를 할당하거나 해제 가능 |

# 포인터 배열

## 포인터 배열이란?

포인터 배열은 간단히 말해 포인터들의 배열입니다. 이는 여러 개의 포인터를 한 번에 관리하는데 사용됩니다. 예를 들어, `int *ptr[3];`라고 선언하면, `ptr`은 3개의 정수형 포인터를 저장하는 배열이 됩니다.

```c
int *ptr[3]; // 길이가 3인 int형 포인터 배열 ptr
```

## 선언 방식 및 예제

```c
int num1 = 10, num2 = 20, num3 = 30;
int * arr[3] = {&num1, &num2, &num3};
printf("%d \n", *arr[0]);
printf("%d \n", *arr[1]);
printf("%d \n", *arr[2]);

/*
10 
20 
30
*/
```

## 문자열을 저장하는 포인터 배열

```c
char * strArr[3] = {"Hello", "C Language", "~!"};
printf("%s \n", strArr[0]);
printf("%s \n", strArr[1]);
printf("%s \n", strArr[2]);

/*
Hello 
C Language 
~! 
*/
```

# 포인터 대상의 const 선언

const 선언 위치에 따라 포인터 변수의 의미가 달라집니다.

- `const int * ptr;`
    - 포인터 변수 ptr을 이용해서 ptr이 가리키는 변수의 값 변경을 허용하지 않는다.
- `int * const ptr;`
    - 포인터 변수 ptr에 한번 주소 값이 저장되면 그 값의 변경은 허용하지 않는다.

# 예제 출력

```bash
$ gcc -o pointer.o pointer.c
$ ./pointer.o
[*] 포인터 변수 
변수 num의 값: 20
변수 num의 주소: 0x16bb06fd8
변수 num의 주소: 0x16bb06fd8
포인터 변수 pnum이 가리키는 주소: 0x16bb06fd8
포인터 변수 pnum이 가리키는 주소: 0x16bb06fd8
포인터 변수 pnum이 가리키는 주소의 값: 20

[*] 포인터와 배열의 관계
배열의 첫 번째 요소: 1 
포인터를 통한 첫 번째 요소 접근: 1 
1 1
2 2
3 3

[*] 포인터 연산 1
11 
22 
33 
2 

[*] 포인터 연산 2 (ptr[i] == *(ptr + i))
10 20 30 
10 20 30 

[*] 변수형 문자열과 상수형 문자열
Xello, Wolrd! 
Hi C Language 

[*] 포인터 배열
10 
20 
30 

[*] 문자열을 저장하는 포인터 배열
Hello 
C Language 
~! 
```