# 파일의 분할

C언어에서 파일의 분할을 위해서는 변수나 함수가 다른 파일에 정의되어 있다는 것을 컴파일러에게 알려줘야 합니다. 이때 사용되는 키워드는 `extern` 입니다.

## extern 키워드

### 전역변수의 선언

다른 소스 파일에서 정의된 전역 변수를 현재 파일에서 사용하고자 할때 `extern`을 사용합니다. 예를 들어, 다른 파일에서 정의된 전역변수 `int num;` 이 있을 때, 다른 파일에서 `extern int num;` 과 같이 선언하면 현재 파일에서 이 변수를 사용할 수 있습니다.

### 함수의 선언

마찬가지로, 다른 소스 파일에서 정의된 함수를 현재 파일에서 사용할 때도 `extern`을 사용합니다. 예를 들어, 다른 파일에서 정의된 함수 `void Increment(void);` 가 있을 때, `extern void Increment(void);` 와 같이 선언하면 현재 파일에서 이 함수를 사용할 수 있습니다.

또한, 함수가 외부에 정의되어 있는 경우, `extern` 을 생략할 수 있으며 `void Increment(void);` 로 선언해도 됩니다.

## static 키워드

이전에 `static` 키워드에 대해 다룬적이 있습니다. [static 변수](https://www.notion.so/static-129da3c644314d3aa3f920361f885c95?pvs=21) 

파일의 분할에서 다시 `static` 키워드를 언급한 이유는 `static` 키워드를 사용하면, 프로젝트의 다른 파일들이 해당 변수나 함수를 참조할 수 없게 됩니다. 이는 특정 파일 내에서만 사용되는 변수나 함수를 숨기고, 프로젝트의 다른 부분에서 접근을 방지하려는 경우에 유용합니다.

다시 정리하는 취지로`static` 키워드의 특징을 정리 하면 다음과 같습니다.

### 정적 전역 변수

- 전역 변수에 `static` 키워드를 사용하면 해당 변수의 범위가 파일 내부로 제한됩니다. 즉, 다른 파일에서 해당 변수에 접근할 수 없습니다.
- 정적 전역 변수는 프로그램이 실행될 때 메모리에 할당되며, 프로그램 종료 시 까지 유지됩니다.

### 정적 함수

- 함수에 `static` 키워드를 사용하면 해당 함수의 범위가 파일 내부로 제한됩니다. 즉, 다른 파일에서는 이 함수를 호출할 수 없습니다.
- 정적 함수는 다른 파일에서는 보이지 않고, 현재 파일 내부에서만 사용할 수 있습니다.
- 정적 함수의 사용은 함수를 은닉하고 다른 파일에서의 ㅈ버근을 제한하여 코드의 모듈성을 높이는 데 도움이 됩니다.

# 헤더파일의 디자인

## #include 지시자

`#include` 지시자는 다른 파일의 내용을 포함하도록 하는 선행처리기 지시자 입니다. 보통 헤더 파일을 포함할 때 사용됩니다.

```c
#include <header_file_name.h> // 시스템 헤더 파일을 나타내며, 시스템 경로에서 헤더파일을 찾는다.
#include "header_file_name.h" // 소스 파일이 있는 디렉터리 또는 사용자가 정의한 헤더파일이 있는 디렉터리에서 찾는다.
```

위와 같이 시스템 헤더 파일은 `<`와`>` 사이에 특정 헤더 파일의 이름을 작성하며, 사용자 헤더 파일은 `"` 와 `"` 사이에 헤더 파일의 이름을 작성합니다.

# 헤더 파일 작성 가이드

## 헤더 파일 가드

헤더 파일이 한 번만 포함되도록 헤더 파일에 가드를 사용합니다. 이를 위해 선행처리기 지시자인 `#ifndef`, `#define`, `#endif` 를 사용합니다.

> 만일 헤더 파일이 중복 삽입된 경우 발생되는 문제로 구조체가 두 번 정의된 형태의 경우 컴파일 에러가 발생 됩니다.
> 

```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

// 여기에 헤더 파일 내용 작성

#endif // MY_HEADER_H
```

## 함수 선언

헤더 파일에는 함수의 선언만을 포함시키고, 정의는 별도의 소스 파일에 구현합니다.

📄 **my_header.h (함수 선언)**

```c
// 함수 선언
void greet(const char *name);
```

📄 **my_header.c (함수 정의)**

```c
#include "my_header.h"

// 함수 정의
void greet(const char *name) {
    printf("Hello, %s!\n", name);
}
```

## 외부 변수 선언

전역 변수를 선언할 때는 `extern` 키워드를 사용하여 선언하고, 정의는 하나의 소스 파일에서만 해야 합니다.

📄 **my_header.h (전역 변수 선언)**

```c
// 외부 변수 선언
extern int globalCounter;
```

📄 **my_header.c (함수 정의)**

```c
// 외부 변수 정의
int globalCounter = 0;
```

# 구조체의 선언(typedef) 및 정의(작성) 가이드

컴파일러는 파일 단위로 컴파일을 진행 하므로 헤더 파일을 작성한 뒤 구조체를 사용하는 파일에 헤더파일을 추가합니다.

이때, 다음과 같이 헤더 파일에 구조체의 선언과 해당 구조체를 다루는 함수의 선언만을 포함시키는 것이 더 좋습니다. 그리고, 구조체의 정의는 

별도의 소스 파일에 구현합니다. 이렇게 하면, 구조체의 세부 구현이 변경되더라도 헤더 파일을 사용하는 다른 파일들은 영향을 받지 않게 됩니다.

📄 **my_header.h (구조체 관련 선언)**

```c
// 구조체 선언
typedef struct {
    int x;
    int y;
} Point;

// 구조체 관련 함수 선언
void initializePoint(Point *p, int x, int y);
void movePoint(Point *p, int dx, int dy);
```

📄 **my_header.c (구조체 관련 정의)**

```c
#include "my_header.h"

// 구조체를 초기화하는 함수 정의
void initializePoint(Point *p, int x, int y) {
    p->x = x;
    p->y = y;
}

// 구조체를 이동시키는 함수 정의
void movePoint(Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}
```

# Main 파일과 헤더파일 및 소스파일로 구성된 C 프로젝트 컴파일

## 예제 코드

### 📄 **my_header.h**

```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <stdio.h>

// 함수 선언
void greet(const char *name);

// 구조체 선언
typedef struct {
    int x;
    int y;
} Point;

// 구조체 관련 함수 선언
void initializePoint(Point *p, int x, int y);
void movePoint(Point *p, int dx, int dy);

// 외부 변수 선언
extern int globalCounter;

#endif  // MY_HEADER_H
```

### 📄 **my_header.c**

```c
#include "my_header.h"

// 함수 정의
void greet(const char *name) {
    printf("Hello, %s!\n", name);
}

// 구조체를 초기화하는 함수 정의
void initializePoint(Point *p, int x, int y) {
    p->x = x;
    p->y = y;
}

// 구조체를 이동시키는 함수 정의
void movePoint(Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

// 외부 변수 정의
int globalCounter = 0;
```

### 📄 **main.c**

```c
#include "my_header.h"

int main() {
    greet("Dowon");
    greet("DoTTak");

    // 구조체 선언 및 초기화
    Point p1;
    initializePoint(&p1, 10, 20);

    // 구조체 정보 출력
    printf("Initial Point: (%d, %d)\n", p1.x, p1.y);

    // 구조체 이동
    movePoint(&p1, 5, -5);

    // 이동 후 정보 출력
    printf("Moved Point: (%d, %d)\n", p1.x, p1.y);

    // 외부 변수 사용
    printf("Global Counter: %d\n", globalCounter);
    globalCounter++;
    printf("Global Counter: %d\n", globalCounter);

    return 0;
}
```

위 예제 코드를 아래의 과정을 통해 컴파일을 수행하면 됩니다.

### 💿 컴파일 과정

1. 함수 정의 파일 컴파일
    
    ```bash
    $ gcc -c my_header.c -o my_header.o
    ```
    
2. 메인 프로그램 컴파일
    
    ```bash
    $ gcc -c main.c -o main.o
    ```
    
3. 객체 파일을 링킹하여 실행 파일 생성
    
    ```bash
    $ gcc my_header.o main.o -o ./main
    ```
    
4. 프로그램 실행
    
    ```bash
    $ ./main
    Hello, Dowon!
    Hello, DoTTak!
    Initial Point: (10, 20)
    Moved Point: (15, 15)
    Global Counter: 0
    Global Counter: 1
    ```
    

# 예제 출력

```bash
$ gcc -c my_header.c -o my_header.o
$ gcc -c main.c -o main.o
$ gcc my_header.o main.o -o ./main
$ ./main
Hello, Dowon!
Hello, DoTTak!
Initial Point: (10, 20)
Moved Point: (15, 15)
Global Counter: 0
Global Counter: 1
```