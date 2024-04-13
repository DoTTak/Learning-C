# 포인터의 포인터

## 이중 포인터(더블 포인터)

이중 포인터(double pointer)는 포인터를 가리키는 포인터를 의미합니다. 포인터는 메모리 주소를 가리키는 변수이고, 이중 포인터는 다른 포인터 변수의 주소를 저장하는 변수입니다.

아래의 코드는 이중 포인터에 대한 예제 코드입니다.

```c
#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;
    int **dptr = &ptr;

    printf("num 주소: %9p, num 값: %d\n", &num, num);
    printf("ptr 주소: %9p, ptr의 값: %9p\n", &ptr, ptr);
    printf("dptr 주소: %9p, dptr의 값: %9p\n", &dptr, dptr);

    printf("ptr이 가리키는 변수 num의 값: %d\n", *ptr);
    printf("dptr이 가리키는 포인터 변수 ptr이 가리키는 변수 num의 값: %d\n", **dptr);
    return 0;
}
/*
num 주소: 0x16d11b028, num 값: 10
ptr 주소: 0x16d11b020, ptr의 값: 0x16d11b028
dptr 주소: 0x16d11b018, dptr의 값: 0x16d11b020
ptr이 가리키는 변수 num의 값: 10
dptr이 가리키는 포인터 변수 ptr이 가리키는 변수 num의 값: 10
*/
```

## 포인터 변수의 Call-By-Reference

Call-By-Reference는 참조에 의한 호출로, 함수에 인자로 변수의 주소(참조)를 전달하여, 해당 변수를 직접 참조하여 변경할 수 있습니다.

따라서, 포인터 변수를 함수의 인자로 전달할 경우 인자로 전달된 변수를 호출된 함수에서 직접 조작이 가능하므로 함수 호출 이후에 변경된 값이 인자로 전달한 원본 변수에 영향이 미치게 됩니다.

아래는 포인터 변수(이중 포인터 사용)의 Call-By-Reference 예제 코드입니다.

```c
#include <stdio.h>

void Increment(int **dptr)
{
	(**dptr)++;
}

int main(void)
{
	int num2=10;
  int * ptr2 = &num2;
  int ** dptr2 = &ptr2;
  printf("num2의 값: %d\n", num2);
  Increment(dptr2);
  printf("num2의 값: %d\n", num2);
	return 0;
}
/*
num2의 값: 10
num2의 값: 11
*/
```

## 포인터 배열과 포인터 배열의 포인터 형

앞서 설명드린 이중 포인터는 결국 포인터 변수의 주소를 저장하기 위한 또 다른 포인터 변수(이중 포인터) 입니다.

그럼, 포인터 배열(요소가 포인터로 이루어진 배열)의 포인터 형(데이터 타입이 포인터인 형식)도 아래와 같이 설명할 수 있습니다.

포인터 배열이 다음과 같이 선언되어 있을 경우 포인터 배열 `arr` 의 첫 번째 요소는 int 형 포인터 입니다.

```c
int * arr[10]; // 길이가 10인 int형 포인터 배열 arr
```

또한, 배열의 이름은 첫 번째 요소의 주소를 의미 하므로 포인터 배열 `arr` 은 int형 이중 포인터 입니다.

위 내용에 대한 예제 코드입니다.

```c
#include <stdio.h>
int main(void)
{
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
	return 0;
}

/*
n1(0x16b326fdc): 10
n2(0x16b326fd8): 20
n3(0x16b326fd4): 30
ptrArr의 주소: 0x16b327010
ptrArr[0]의 주소: 0x16b327010, 저장된 값: 0x16b326fdc, 저장된 값이 가리키는 값: 10
ptrArr[1]의 주소: 0x16b327018, 저장된 값: 0x16b326fd8, 저장된 값이 가리키는 값: 20
ptrArr[2]의 주소: 0x16b327020, 저장된 값: 0x16b326fd4, 저장된 값이 가리키는 값: 30
*/
```

변수 `n1`, `n2`, `n3`의 주소는 각각 포인터 변수 `nptr1`, `nptr2`, `nptr3`에 저장되고 이를 포인터 배열의 요소로 	`int * ptrArr[3] = {nptr1, nptr2, nptr3};` 와 같이 초기화 되었습니다.

포인터 배열 `ptrArr` 의 주소는 `ptrArr[0]` 의 주소와 동일하고 각 요소의 크기는 포인터의 크기(8 byte) 만큼 늘어나고 있습니다.

또한, 포인터 배열의 각 요소에 저장된 값은 변수 `n1`, `n2`, `n3`의 주소가 저장되어 있고 실제 값을 확인하기 위해서는 `*(ptrArr[i])` 를 통해 조회하고 있습니다.

# 다중 포인터

## 삼중 포인터

삼중 포인터(triple pointer)는 이중 포인터를 가리키는 포인터를 의미합니다. 즉, 삼중 포인터는 포인터의 포인터의 포인터라고 할 수 있습니다. 이는 다른 이중 포인터 변수의 주소를 저장하는 변수입니다.

아래의 코드는 삼중 포인터에 대한 예제 코드입니다.

```c
#include <stdio.h>

int main() {
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
/*
num3 주소: 0x16f45afa0, num3 값: 10
ptr3 주소: 0x16f45af98, ptr3의 값: 0x16f45afa0
dptr3 주소: 0x16f45af90, dptr3의 값: 0x16f45af98
tptr3 주소: 0x16f45af88, tptr3의 값: 0x16f45af90
ptr3이 가리키는 변수 num3의 값: 10
dptr3이 가리키는 포인터 변수 ptr3이 가리키는 변수 num3의 값: 10
*/
```

# 예제 출력

```bash
$ gcc -o multiple_pointer.o multiple_pointer.c
$ ./multiple_pointer.o
[*] 이중 포인터(더블 포인터)
num 주소: 0x16d7d7058, num 값: 10
ptr 주소: 0x16d7d7050, ptr의 값: 0x16d7d7058
dptr 주소: 0x16d7d7048, dptr의 값: 0x16d7d7050
ptr이 가리키는 변수 num의 값: 10
dptr이 가리키는 포인터 변수 ptr이 가리키는 변수 num의 값: 10

[*] 포인터 변수의 Call-By-Reference
num2의 값: 10
num2의 값: 11

[*] 포인터 배열의 포인터 형
n1(0x16d7d702c): 10
n2(0x16d7d7028): 20
n3(0x16d7d7024): 30
ptrArr의 주소: 0x16d7d7060
ptrArr[0]의 주소: 0x16d7d7060, 저장된 값: 0x16d7d702c, 저장된 값이 가리키는 값: 10
ptrArr[1]의 주소: 0x16d7d7068, 저장된 값: 0x16d7d7028, 저장된 값이 가리키는 값: 20
ptrArr[2]의 주소: 0x16d7d7070, 저장된 값: 0x16d7d7024, 저장된 값이 가리키는 값: 30

[*] 삼중 포인터
num3 주소: 0x16d7d7000, num3 값: 10
ptr3 주소: 0x16d7d6ff8, ptr3의 값: 0x16d7d7000
dptr3 주소: 0x16d7d6ff0, dptr3의 값: 0x16d7d6ff8
tptr3 주소: 0x16d7d6fe8, tptr3의 값: 0x16d7d6ff0
ptr3이 가리키는 변수 num3의 값: 10
dptr3이 가리키는 포인터 변수 ptr3이 가리키는 변수 num3의 값: 10
tptr3이 가리키는 이중 포인터 변수 dptr3이 가리키는 포인터 변수 ptr3이 가리키는 변수 num3의 값: 10
```