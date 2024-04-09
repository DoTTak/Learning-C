# 함수

## 함수의 정의 및 구조

함수를 정의할 때에는 다음과 같은 형식을 사용합니다.

```c
int main(void)
{
	// 함수의 몸체
	/* 함수가 수행할 작업을 정의 */
	
	// 반환형태가 int이므로, 정수 0을 반환
	return 0;
}
```

여기서 `int` 는 반환 형태를 의미하고 `void` 는 입력 형태를 의미합니다. 그리고 함수의 몸체에는 함수가 수행할 작업을 정의하고 반환 형태가 `int` 이므로 `return 0;` 을 통해 정수를 반환합니다.

## 반환 값의 유무 및 전달 인자의 유무에 따른 함수의 형태

함수는 방금과 같이 반환 형태와 입력 형태 즉, 반환 값의 유무 및 전달 인자의 유무에 따라 형태가 달라지게 됩니다.

### 반환 값 O, 전달 인자 O

```c
int add(int num1, int num2)
{
	return num1+num2;
}
```

### 반환 값 O, 전달 인자 X

```c
int inputNum(void)
{
	int num;
	printf("숫자를 입력하세요: ");
	scanf("%d", &num);
	return num;
}
```

### 반환 값 X, 전달 인자 O

```c
void showNum(int num)
{
	printf("num: %d", num);
}
```

### 반환 값 X, 전달 인자 X

```c
void init(void)
{
	printf("두 개의 정수를 입력하시면 덧셈결과가 출력됩니다. \n");
}
```

## 함수 정의 시 주의사항

함수를 정의할 때에는 호출되기 전에 미리 정의되어야 합니다.

### 함수를 먼저 정의한 경우

```c
#include <stdio.h>

int foo(void) // 함수를 먼저 정의
{
	printf("Call foo()\n");
	return 0;
}

int main(void)
{
	foo() // foo() 함수는 호출 이전에 미리 정의되어 있다.
	return 0;
}
```

### 함수 선언을 먼저 하고, 이후에 정의한 경우

```c
#include <stdio.h>

int foo(void); // 함수 선언

int main(void)
{
	foo() // foo() 함수는 상단의 선언을 통해 호출할 수 있으며 해당 함수는 하단에 정의되어있다.
	return 0;
}

int foo(void) // 함수 정의
{
	printf("Call foo()\n");
	return 0;
}
```

# 지역 변수와 전역 변수

## 지역 변수

지역 변수는 함수 내에서 선언되고, 이 함수 내에서만 사용할 수 있습니다. 함수가 호출될 때 생성되고, 함수가 종료되면 메모리에서 제거됩니다. 따라서, 함수가 종료된 후에는 해당 변수에 접근할 수 없습니다.

```c
void function() {
	int local_var = 5; // 지역 변수
}
```

## 전역 변수

전역 변수는 함수 외부에서 선언되며, 프로그램의 어떤 부분에서든 사용할 수 있습니다. 전역 변수는 프로그램이 시작할 때 생성되고, 프로그램이 종료될 때까지 메모리에 남아있습니다. 따라서, 프로그램의 실행 도중 언제든지 해당 변수에 접근하거나 값을 변경할 수 있습니다.

```c
int global_var = 10; // 전역 변수

void function() {
	global_var = 5; // 전역 변수를 사용
}
```

지역 변수와 전역 변수는 서로 다른 메모리 영역에 저장되므로, 동일한 이름을 가진 지역 변수와 전역 변수가 존재할 수 있습니다. 이 경우, 함수 내에서는 해당 이름의 지역 변수를 우선적으로 참조합니다.

# static 변수와 register 변수

## static 변수

static 선언은 지역변수, 전역변수 모두 선언이 가능합니다.

static 변수는 프로그램 시작 시 메모리에 할당되고 프로그램 종료 시 메모리에 해제됩니다. 즉 static 변수는 프로그램 실행 동안 계속 값을 유지합니다.

### 지역변수 static

- 특징
    - 선언된 함수 내에서만 접근 가능합니다.(지역변수 특성)
    - 딱 1번 초기화 되고 프로그램 종료 시 까지 메모리 공간에 존재합니다.(전역변수 특성)
    - 접근할 수 있는 범위를 함수로 제한하고자 할 때 사용됩니다.
- 예제 코드
    
    ```c
    #include <stdio.h>
    
    void staticFunc(void)
    {
        static int static_num = 0;
        int local_num=0;
        static_num++, local_num++;
        printf("static_num: %d, local_num: %d \n", static_num, local_num);
    }
    
    int main(void)
    {
        staticFunc();
        staticFunc();
        staticFunc();
        return 0;
    }
    
    /*
    static_num: 1, local_num: 1 
    static_num: 2, local_num: 1 
    static_num: 3, local_num: 1 
    */
    ```
    

### 전역변수 static

- 특징
    - 해당 파일 내에서만 접근을 할 수 있습니다. 다시 말해 선언된 소스 파일 내에서만 사용 가능합니다.
    - 소스 파일 간 변수 이름 충돌을 방지하고, 변수의 접근 범위를 제한하는데 사용됩니다.
- 예제코드
    
    ```c
    #include <stdio.h>
    
    static int global_num; // 전역변수 static 선언
    
    void staticFunc(void)
    {
        static int static_num = 0;
        int local_num=0;
    
        static_num++, local_num++;
        global_num++;
    
        printf("static_num: %d, local_num: %d \n", static_num, local_num);
    }
    
    void showGlobalNum(void)
    {
        printf("global_num: %d\n", global_num);
    }
    
    int main(void)
    {   
        global_num++;
        staticFunc();
        staticFunc();
        staticFunc();
        showGlobalNum();
        return 0;
    }
    /*
    static_num: 1, local_num: 1 
    static_num: 2, local_num: 1 
    static_num: 3, local_num: 1 
    global_num: 4
    */
    ```
    

## register 변수

register 변수는 메모리가 아닌 CPU의 레지스터에 저장됩니다. 그렇기에 메모리에 접근 시간이 줄어들어 프로그램 실행 속도가 빨라지게 됩니다.

```c
#include <stdio.h>

int main() {
    register int i;  // register 변수 선언
    for(i=0; i<10000; i++) {
        printf("%d\\n", i);
    }
    return 0;
}
```

이 경우, `i`라는 이름의 변수가 CPU의 레지스터에 저장됩니다. register 변수는 자주 사용되는 변수에 대해 사용되며, 이로 인해 그 변수에 대한 연산이 빠르게 수행될 수 있습니다.

그 밖에 특징은 다음과 같습니다.

- register는 한정된 자원이므로 모든 변수를 register 변수로 선언할 수는 없다.
- register 변수는 주소 연산자(&)를 사용할 수 없습니다.
    - 메모리 상에 위치하지 않고 CPU 레지스터에 저장되기 때문입니다.

# 재귀 함수

재귀 함수란 함수가 자기 자신을 다시 호출하는 것을 의미합니다.

즉, 함수가 결과를 반환하기 전에 다시 같은 함수를 호출하는 형태이며, 재귀함수에는 종료 조건이 반드시 필요합니다.

```c
#include <stdio.h>

// 팩토리얼 함수 정의
int factorial(int n)
{
    if (n == 0)  // 종료 조건
        return 1;
    else
        return n * factorial(n - 1);  // 재귀 호출
}

int main(void)
{
    int num = 5;
    printf("%d! = %d\\n", num, factorial(num));
    return 0;
}
```

# 예제 출력

```bash
$ gcc -o function.o function.c
$ ./function.o
[*] 반환 값, 전달 인자에 따른 함수 형태 
두 개의 정수를 입력하시면 덧셈결과가 출력됩니다. 
숫자를 입력하세요: 10
num: 10 
숫자를 입력하세요: 5
num: 5 
합계 결과
num: 15 

[*] 지역변수와 전역변수 
함수 외부 - 전역변수: 10
함수 내부 - 전역변수: 10, 지역변수: 20 

[*] static 변수 
Count: 1
Count: 2
Count: 3

[*] 재귀 함수 
5 팩토리얼은? 120
```