# 함수 포인터

## 정의

함수 포인터는 함수를 가리키는 포인터를 의미 합니다. 다른 데이터 타입의 포인터와 마찬가지로, 함수의 주소를 저장하고 호출할 수 있는 변수 입니다.

## 함수 포인터의 선언

```c
반환타입 (*함수포인터 변수명)(인자타입1, 인자타입2)
```

`반환타입`은 함수의 반환형을, `인자타입1`, `인자타입2` 에는 함수의 인자 타입들을 나타냅니다.

## 함수 포인터의 사용

함수 포인터 변수에 함수 주소를 할당하고, 그 함수 포인터 변수를 사용하여 해당 함수를 호출할 수 있습니다.

예를 들어, 아래의 함수(두 개의 정수를 더한 결과를 반환하는 함수)가 있을 때,

```c
int Add(int num1, int num2)
{
	return num1+num2;
}
```

함수 포인터는 다음과 같이 작성할 수 있습니다.

```c
int (*fptr_add)(int, int) = &Add // 함수 포인터의 선언 및 초기화
int result = fptr_add(3,4); // 함수 포인터 fptr_add를 이용한 함수 호출
printf("%d\n", result);
```

전체 코드는 다음과 같습니다.

```c
#include <stdio.h>

int Add(int num1, int num2)
{
    return num1+num2;
}

int main(void)
{
    int (*fptr_add)(int, int) = Add;
    int result = fptr_add(3,4);
    printf("%d\n", result);

    return 0;
}
/*
7
*/
```

# void 포인터

## 정의

void 포인터(`void *`)는 어떠한 변수의 주소 값이든 담을 수 있는 범용 포인터 입니다. 일반적으로 메모리 주소만을 다루고 데이터 타입에 대한 정보는 포함하지 않습니다.

## 특징

- 범용 ****포인터: 어떤 데이터 타입의 주소를 저장할 수 있는 포인터입니다.
- 데이터 타입 정보 미포함: 포인터 자체에는 어떤 데이터 타입에 대한 정보가 포함되지 않습니다.
- 명시적 형 변환 필요: `void *` 포인터를 사용할 때는 명시적인 형 변환(casting)을 통해 원래 데이터 타입으로 되돌려야 합니다.
- 메모리 주소만 다룸: 주소를 저장하고 참조하기 위한 용도로 사용되며, 저장된 주소에 접근할 때는 형 변환을 통해 적절한 데이터 타입으로 해석합니다.

# main 함수의 인자

```c
int main(int argc, char * argv[]){ ... }
```

- `int argc`
    - 이 변수는 프로그램이 시작될 때 명령줄 인자의 수를 나타냅니다.
- `char * argv[]`
    - 이 변수는 프로그램이 시작될 때 전달된 명령줄 인자를 가리킵니다.
    - 각 인자는 문자열로, argv[0]은 프로그램의 이름, argv[1]부터 argv[argc-1]까지는 프로그램에 전달된 인자가 전달됩니다.
    - char형 더블 포인터 변수

# 예제 출력

```bash
$ gcc -o function_pointer_and_void_pointer.o function_pointer_and_void_pointer.c
$ ./function_pointer_and_void_pointer.o arg1 arg2 arg3
[*] 함수형 포인터 
7

[*] void 포인터
vptr: 0x16ae6afe0
vptr: 0x16ae6afdf
vptr: 0x16ae6afd0

[*] main 함수의 인자 값
인자 총 갯수: 4
[0]: ./function_pointer_and_void_pointer.o
[1]: arg1
[2]: arg2
[3]: arg3
```