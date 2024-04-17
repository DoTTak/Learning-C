# 선행처리기

선행처리기란 소스 코드를 컴파일하기 전에 특정한 전처리 작업을 수행하는 독립적인 프로그램입니다. 이는 소스코드에서 지정된 명령을 실행하거나 변경하는 것을 의미 합니다.

## 대표적인 선행처리 명령문

### #define: Object-like macro

```c
#define PI 3.14159
```

매크로는 소스코드 내에서 자주 사용되는 값이나 코드 덩어리에 이름을 할당하여 가독성을 높이고 코드를 간결하게 만듭니다.

위 매크로의 경우 `#define` 은 지시자, `PI` 는 매크로, `3.14159` 는 매크로 몸체를 의미 합니다.

### #define: Function-like macro

```c
#define SQUARE(X)   X*X
```

이 함수 형태의 매크로는 `SQUARE(X)`을 `X*X`의 유형으로 변경합니다. 다만 위 매크로의 경우 아래의 코드에서 문제가 발생될 수 있습니다.

```c
int num=20;

/* 정상 결과 출력 */
SQUARE(num); // 400
SQUARE(-5); // 25
/* 비 정상 결과 출력 */
SQUARE(3+2) // 11
```

`SQUARE(3+2)` 는 `3+2`의 결과(`5`)가 제곱(`25`)되는 것을 예상 했지만, `2+3*2+3` 로 치환 되어 `25`가 아닌 `11`이 출력됐습니다.

이를 해결하기 위해선 매크로를 아래와 같이 `X` 에 괄호(`()`)를 추가하여 연산자 우선순위를 지정해야 합니다.

```c
#define SQUARE(X)   (X)*(X)
```

이렇게 매크로를 사용할 때는 항상 주의하여 의도하지 않은 결과를 방지하고, 식의 가독성 및 안전성을 고려해야 합니다.

그 밖에 매크로는 다음과 같이 `\` 문자를 통해 두 줄 정의도 가능합니다.

```c
#define SQUARE(X)   \
        (X)*(X)
```

또한, 아래와 같이 먼저 정의된 매크로를 사용할 수 도 있습니다.

```c
#define PI  3.14
#define PRODUCT(X, Y)   ((X)*(Y))
#define CIRCLE_AREA (PRODUCT((R), (R))*PI))
```

## 매크로 함수의 장단점

매크로 함수의 장점과 단점은 다음과 같습니다.

### 장점

- 코드의 재사용성을 높여줍니다.
- 실행 시간을 단축시켜 성능을 향상시킵니다.
- 코드의 가독성을 높여줍니다.

### 단점

- 매크로 치환이 복잡하면 디버깅이 어렵습니다.
- 매크로 내에서 변수를 사용 할 때, 의도하지 않은 결과를 초래할 수 있습니다.
- 매크로는 타입 검사를 하지 않습니다.

이처럼 올바른 매크로 정의를 위해서는 작은 크기의 함수나 호출의 빈도수가 높은 함수를 대상으로 지정해야 합니다.

# 조건부 컴파일

## #if… #endif: 참이라면

```c
#ifdef DEBUG
    printf("Debugging information\n");
#endif
```

`#ifdef`는 정의된 매크로가 있는지 검사합니다. `DEBUG` 매크로가 정의되어 있으면 `printf("Debugging information\n");`이 포함됩니다. 그렇지 않으면 해당 부분은 컴파일되지 않습니다.

## #ifdef … #endif: 정의되었다면 ↔ #ifndef … #endif: 정의되지 않았다면

```c
#ifndef NDEBUG
    printf("Debugging information\n");
#endif
```

`#ifndef`은 정의되지 않은 매크로를 검사합니다. `NDEBUG` 매크로가 정의되어 있지 않으면 `printf("Debugging information\n");`이 포함됩니다.

## #else의 삽입: #if, #ifdef, #ifndef에 해당

```c
#ifdef DEBUG
    printf("Debugging information\n");
#else
    printf("Release information\n");
#endif
```

`#else`는 `#ifdef` 또는 `#ifndef` 조건문이 거짓일 때 실행될 코드 블록을 지정합니다.

## #elif의 삽입: #if에만 해당

```c
#ifdef DEBUG
    printf("Debugging information\n");
#elif defined(TEST)
    printf("Testing information\n");
#else
    printf("Release information\n");
#endif
```

`#elif`는 여러 조건을 연결하여 검사할 때 사용됩니다.

## #define을 사용한 조건부 컴파일

```c
#define VERSION 2

#if VERSION == 1
    printf("Version 1\n");
#elif VERSION == 2
    printf("Version 2\n");
#else
    printf("Unknown version\n");
#endif
```

`#if`와 `#elif` 지시문을 사용하여 매크로의 값에 따라 다른 코드를 컴파일할 수 있습니다.

# 매크로의 연산자

## # 연산자

`#` 연산자는 매크로 인자를 문자열 리터럴로 변환합니다. 매크로 함수에서 사용되며, 매크로 인자의 값을 문자열로 만들어줍니다. 이 연산자는 매크로 정의 내에서만 사용할 수 있습니다.

예를 들어, 다음과 같은 매크로의 경우 이 매크로를 사용하면 매크로의 인자를 문자열로 변환할 수 있습니다

```c
#define STRINGIFY(x) #x
```

```c
int num = 10;
printf("%s\n", STRINGIFY(num)); // 이 코드는 printf("%s\n", "num"); 으로 치환됩니다.
```

## ## 연산자

`##` 연산자는 두 개의 토큰을 결합하여 새로운 토큰을 생성합니다. 이 연산자를 사용하면 매크로 정의 내에서 여러 토큰을 합칠 수 있습니다. 이 연산자 또한 매크로 정의 내에서만 사용할 수 있습니다.

예를 들어, 다음과 같은 매크로의 경우 이 매크로를 사용하면 인자로 전달된 두 개의 토큰을 결합할 수 있습니다.

```c
#define CONCAT(x, y) x ## y
```

```c
int foo = 10;
printf("%d\n", CONCAT(foo, bar)); // 이 코드는 printf("%d\n", foobar); 으로 치환됩니다.
```

# 예제 출력

```bash
$ gcc -o macro.o macro.c
$ ./macro.o
PI: 3.14159
Square of 20: 400
Square of -5: 25
Square of 5: 25
Debugging information
```