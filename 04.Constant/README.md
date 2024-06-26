# 상수의 정의

상수란 프로그램 실행 중에 그 값을 변경할 수 없는 데이터를 의미합니다.

C언어에서는 숫자 혹은 문자, 문자열 등 다양한 데이터를 상수로 사용할 수 있으며, 상수는 그 값이 변하지 않는 특성 때문에 프로그램 내에서 반복적으로 사용되는 고정 값을 표현할 때 유용 합니다. 예를 들어, 원의 둘레를 계산할 때 사용하는 원주율 3.14는 상수로 표현할 수 있습니다.

# 상수의 형태

상수는 이름을 지니지 않는 리터럴 상수와 이름이 존재하는 심볼릭 상수(const 상수)가 있습니다.

## 리터럴 상수

```c
int num = 30 + 40; // 30과 40은 상수
```

위 코드에서 리터럴 상수는 정수 30과 40입니다. 변수와 달리 이름이 없는 상수를 가리켜 ‘리터럴 상수’ 또는 ‘리터럴’ 이라 합니다.

### 단계별 설명

1. 프로그램 실행 시 30과 40은 메모리 공간에 상수의 형태로 저장됩니다. 
2. 이후에는 두 상수를 참조하여 덧셈이 진행됩니다.
3. 덧셈의 결과는 변수 num으로 저장됩니다.

### 리터럴 상수의 자료형

- 리터럴 상수도 자료형이 존재합니다. 앞서 본 코드는 `int`형으로 표현된 정수이므로 `int`형으로 메모리 공간에 저장됩니다. 그리고 `double`형으로 표현된 정수는 `double`형으로 저장됩니다.
- 그럼 char형은 무슨 자료형으로 저장이 될까요?
    - 정답은 `int`형 메모리 공간에 저장됩니다. 그 이유는, C언어에서는 `‘A’`라는 문자 리터럴이 내부적으로 ASCII 값, 즉 정수로 저장되기 때문입니다.
        
        ```c
        // 리터럴 상수
        printf("%lu \n", sizeof('A')); // 4
        printf("%lu \n", sizeof('A' + 15)); // 4

        // 심볼릭 상수
        char ch1='A';
        printf("%lu \n", sizeof(ch1)); // 1
        printf("%lu \n", sizeof(ch1+15)); // 4
        ```
        
    - 또한, C언어에서는 `char`형과 다른 자료형을 계산을 할 때, 그 결과는 int형으로 처리됩니다. 이는 산술 연산을 통해 자동 형 변환이 일어나기 때문입니다.

## 심볼릭 상수(const 상수)

심볼릭 상수는 변수와 마찬가지로 이름을 지니는 상수 입니다. 아래는 상수를 표현하기 위한 방법 입니다.

```c
const int MAX=100; // MAX는 상수! 따라서 값 변경 불가
const double PI=3.1415; // PI는 상수! 따라서 값 변경 불가
```

위 코드와 같이 `const` 라는 키워드를 이용하여 상수를 선언할 수 있습니다. 그리고 심볼릭 상수는 값을 변경할 수 없습니다.

> 매크로를 이용해서도 상수를 표현할 수 있지만 해당 내용은 ‘매크로’에서 다시 설명하겠습니다.
> 

## 접미사를 이용한 상수의 표현

정수형 자료형인 `int`와 실수형 자료형인 `double` 외 다른 자료형을 기반으로 상수를 표현하려면 접미사를 붙이면 됩니다.

| 접미사 | 자료형 | 사용의 예 |
| --- | --- | --- |
| U | unsigned int | 15U |
| L | long | 123456789L |
| UL | unsgiend long | 100000UL |
| LL | long long | 123456789012345LL |
| F | float | 1.23F |
| L | long double | 1.23L |

표에서 보듯이, `100000UL`은 `unsigned long`형 상수를 나타냅니다.

표에서 알 수 있듯이, 각 접미사는 해당 자료형의 상수를 표현하는데 사용됩니다. 예를 들어, `15U`는 `unsigned int`형 상수를, `123456789L`는 `long`형 상수를, `123456789012345LL`는 `long long`형 상수를, `1.23F`는 `float`형 상수를, 그리고 `1.23L`는 `long double`형 상수를 나타냅니다.

# 예제 출력

```bash
$ gcc -o constant.o constant.c
$ ./constant.o
[*] 리터럴 상수
상수 30과 40를 더한 결과를 int형 변수 num에 저장 후 num의 값은? 70

[*] 리터럴 상수의 크기
int형 리터럴 상수의 크기 4
double형 리터럴 상수의 크기 8
char형 리터럴 상수의 크기 4

[*] char형 리터럴 상수의 크기와 char형 변수의 크기
char형 리터럴 상수의 크기: 4, char형 변수의 크기: 1
char형 리터럴 상수 'A'와 int형 리터럴 상수 10을 덧셈할 때의 크기는? 4 
char형 변수 ch1과 int형 리터럴 상수 10을 덧셈할 때의 크기는? 4 

[*] 접미사를 이용한 상수의 표현
15U (unsigned int)의 크기 4 
123456789L (long)의 크기 8 
123456789012345LL (long long)의 크기 8 
1.23F (float)의 크기 4 
1.23L (long double)의 크기 8 
```