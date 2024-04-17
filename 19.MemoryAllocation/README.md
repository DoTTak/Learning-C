# 메모리의 구성

## 코드 영역

코드 영역은 프로그램의 실행 코드가 저장되는 영역입니다. 실행 파일을 로드할 때 생성되며, CPU는 코드 영역에 저장된 명령어를 하나씩 가져가서 실행합니다.

이 영역의 크기는 프로그램 시작 전에 결정되며, 실행 중에는 변경되지 않습니다. 이곳에는 프로그램의 소스 코드에서 작성된 함수와 메소드 등의 실행 코드가 저장됩니다.

## 데이터 영역

데이터 영역은 전역 변수와 정적 변수가 저장되는 영역입니다. 이 영역에 할당되는 변수는 프로그램의 시작과 동시에 할당되며, 프로그램이 종료되면 소멸합니다.

## 힙 영역

힙 영역은 사용자의 동적 메모리 할당이 이루어지는 영역입니다. 이 영역은 개발자에 의해 직접 관리되며 프로그램이 실행 도중에 필요한 만큼 메모리를 할당하고, 사용이 끝난 메모리는 해제해야 합니다.

## 스택 영역

스택 영역은 함수의 호출과 관련된 정보를 저장하는 영역입니다. 이 영역에는 지역 변수, 매개 변수, 리턴 주소 등이 저장되며, 함수의 호출과 함께 할당되고, 함수의 작업이 끝나면 해제됩니다.

# 메모리 동적 할당

## 전역변수와 지역변수의 문제점

특정 함수에 메모리 번지를 가리키는 지역 변수(ex. 문자열)에 사용자로부터 입력 값을 받아 이를 다시 반환하는 프로그램을 만들기 위해 아래의 코드를 작성했습니다.

```c
#include <stdio.h>

char * inputString(void)
{
    char str[20];
    printf(">> ");
    fgets(str, sizeof(str), stdin);
    return str;
}

int main(void)
{
    char * str;
    str = inputString();
    printf("<< %s \n", str); // inputString 함수로부터 정상적인 데이터를 반환받지 못함
    return 0;
}
/*
>> HelloWorld
<<
*/
```

이때, 함수 내에 선언된 변수 `str` 은 지역 변수로, 함수가 호출될 때 스택 메모리에 할당되며, 함수가 종료되면 해당 메모리가 해제됩니다. 그렇기에 반환된 `str` 의 주소는 함수가 종료된 후에는 더 이상 유효하지 않아 호출된 곳에서 이 주소에 접근할 경우 정상적인 데이터를 조회할 수 없습니다.

지역변수는 함수 호출이 종료되면 소멸 되므로 전역변수를 생각해 볼 수 있습니다. 전역변수는 프로그램 종료 시 까지 메모리가 소멸되지 않고, 어느 함수든 접근도 가능하기 때문에 위 문제를 해결할 수 있는지 아래의 코드를 확인해 보겠습니다.

```c
#include <stdio.h>

char str[20];

char * inputString(void)
{
    printf(">> ");
    fgets(str, sizeof(str), stdin);
    return str;
}

int main(void)
{
    char * str;
    str = inputString();
    printf("<< %s \n", str);
    return 0;
}
/*
>> HelloWorld
<< HelloWorld
*/
```

위 코드는 정상적으로 동작되는 것으로 보입니다. 다만, 여기서 문제가 있는데 만약 `main` 함수에 `inputString` 함수의 결과를 여러 변수(`str1`, `str2`) 에 저장한 뒤, 이 변수들을 다시 출력하는 프로그램으로 변경한다면 어떻게 되는지 보겠습니다.

```c
#include <stdio.h>

char str[20];

char * inputString(void)
{
    printf(">> ");
    fgets(str, sizeof(str), stdin);
    return str;
}

int main(void)
{
    char * str1;
    char * str2;
    str1 = inputString(); // Hello 입력
    printf("<< %s \n", str1); // Hello 출력
    str2 = inputString(); // World 입력
    printf("<< %s \n", str2); // World 출력

    printf("<< %s \n", str1); // World 출력
    printf("<< %s \n", str2); // World 출력
    return 0;
}
/*
>> Hello
<< Hello
 
>> World
<< World
 
<< World
 
<< World
*/
```

변수 `str1`, `str2`에 각기 다른 문자열 `Hello`, `World`를 입력 했는데 출력된 문자열은 마지막으로 입력한 문자열 `World` 만 출력되고 있습니다.

이러한 이유는 `inputString` 함수에서 전역 변수인 `str`을 사용하여 입력 받고, 반환을 하기 때문에 결국 `main` 함수의 변수 `str1`, `str2`는 모두 전역 변수 `str` 을 가리키게 되므로 마지막으로 입력한 문자열 `World`만을 출력하게 되는 것입니다.

위와 같이 지역변수를 사용할 경우 매번 할당이 이루어지지만 함수가 종료될 경우 소멸되는 문제가 있고, 전역변수를 사용할 경우 소멸 되지는 않지만, 여러 곳에서 접근할 경우 의도치 않게 데이터가 변경될 수 있는 문제가 있습니다. 

이러한 문제를 해결하기 위해 동적 메모리 할당을 사용합니다. 즉, 지역변수와 같이 함수가 호출될 때마다 매번 할당이 이뤄지지만, 할당이 되면 전역변수와 마찬가지로 함수가 종료되어도 소멸되지 않는 성격의 변수가 필요합니다.

## 힙 영역의 메모리 공간 할당과 해제: malloc, free

`malloc`, `free`함수의 선언 형태는 다음과 같습니다.

```c
#include <stdlib.h>
void * malloc(size_t size); // 힙 영역으로의 메모리 공간 할당
void free(void * ptr); // 힙 영역에 할당된 메모리 공간 해제
// malloc 함수는 성공 시 할당된 메모리의 주소 값, 실패 시 NULL 반환 
```

여기서 `malloc` 의 반환형이 ‘void형 포인터’인 이유는 동적으로 할당된 메모리 공간은 그 형에 상관없이 누구든지 사용이 가능하게 하기 위해서 입니다. 따라서 'void형 포인터'로 반환된 메모리 공간을 적절한 형으로 형 변환하여 사용합니다.

```c
// 4byte 크기(int 크기)의 메모리를 할당하고 int형 포인터로 형 변환
int * ptr1 = (int *)malloc(sizeof(int);
```

또한, `malloc` 함수로 할당한 메모리는 프로그램이 종료되어도 자동으로 해제되지 않습니다. 이로 인해 메모리 누수가 발생할 수 있으므로, 더 이상 필요하지 않은 메모리는 `free` 함수를 사용하여 반드시 해제해야 합니다.

그럼, 문제가 됐던 예제 코드를 `malloc`, `free` 함수를 통해 개선한다면 다음과 같습니다.

```c
#include <stdio.h>
#include <stdlib.h>

char * inputString(void)
{
    char * str = (char *)malloc(sizeof(char) * 20);
    printf(">> ");
    fgets(str, 20, stdin);
    return str;
}

int main(void)
{
    char * str1;
    char * str2;
    str1 = inputString(); // Hello 입력
    printf("<< %s \\n", str1); // Hello 출력
    str2 = inputString(); // World 입력
    printf("<< %s \\n", str2); // World 출력

    printf("<< %s \\n", str1); // Hello 출력
    printf("<< %s \\n", str2); // World 출력

    free(str1);
    free(str2);
    return 0;
}

```

## calloc 함수

`calloc` 함수는 `malloc` 함수와 유사하게 동적 메모리 할당을 수행하지만, 초기화 과정이 추가됩니다. `calloc` 함수는 할당된 메모리 공간을 모두 0으로 초기화하며, 이는 `malloc` 함수가 제공하지 않는 기능입니다.

```c
void * calloc(size_t nmenb, size_t size);
```

`calloc` 함수는 첫 번째 인자로 요소의 개수, 두 번째 인자로 각 요소의 크기를 받습니다. 이 두 값을 곱한 결과가 실제로 할당되는 메모리의 크기가 됩니다. 따라서 `malloc` 함수와 달리, `calloc` 함수는 여러 개의 동일한 크기의 메모리를 한 번에 할당할 수 있습니다.

## realloc 함수

`realloc` 함수는 이미 할당된 메모리의 크기를 변경합니다. 이 함수는 메모리를 새로운 크기에 맞게 재할당하고, 새로운 메모리의 첫 번째 바이트 주소를 반환합니다. 즉, 이 함수는 메모리의 크기를 늘리거나 줄일 수 있습니다.

```c
void * realloc(void * ptr, size_t size);

```

`realloc` 함수는 첫 번째 인자로 재할당할 메모리의 주소를, 두 번째 인자로 새로운 크기를 받습니다. 만약 새로운 크기가 원래 메모리의 크기보다 크다면, 남은 공간은 초기화되지 않습니다. 반대로 새로운 크기가 원래의 메모리 크기보다 작다면, 끝 부분의 메모리는 잘립니다. `realloc` 함수는 메모리의 재할당이 실패하면 NULL을 반환합니다.

`realloc` 함수는 `malloc` 함수나 `calloc` 함수로 할당한 메모리의 크기를 변경할 때 사용됩니다. 따라서, 이 함수를 사용하면 동적으로 할당된 메모리의 크기를 유연하게 관리할 수 있습니다.

# 예제 출력

```bash
$ gcc -o memory_allocation.o memory_allocation.c
$ ./memory_allocation.o
Enter a string: Hello
First string: Hello
Enter another string: Enter a string: World
Second string: World
Enter a new string for the first string: C Programming
Updated first string: C Programming
```