# 스트림

## 정의

문자와 문자열 관련 함수에 들어가기 전, 스트림에 대한 이해가 필요합니다.

스트림은 데이터가 흐르는 통로를 의미하며, 이를 통해 데이터의 입출력이 이루어집니다. 스트림은 데이터의 입출력을 담당하며, 이러한 입출력은 문자열 처리에 있어 핵심 요소이기 때문입니다. 따라서, 스트림의 작동 방식을 이해하지 못하면, 문자와 문자열 관련 함수의 동작 원리를 완전히 이해하는 것이 어렵습니다.

스트림은 파일이나 네트워크를 통해 데이터를 전송하는 등의 작업을 수행할 때 사용됩니다. 그 중 대표 적인 예로, 키보드를 통한 사용자 입력이나 화면에 출력하는 것이 스트림을 통해 이루어지는 입출력입니다.

## 생성과 소멸

스트림은 보통 프로그램이 시작할 때 생성되며, 프로그램이 종료될 때 소멸됩니다. 아래는 표준 스트림 종류 입니다.

- `stdin`: 표준 입력 스트림 / 키보드 대상으로 입력
- `stdout`: 표준 출려 스트림 / 모니터 대상으로 출력
- `stderr`: 표준 에러 스트림 / 모니터 대상으로 출력

# 문자 단위 입출력 함수

## 문자 출력 함수: putchar, fputc

```c
#include <stdio.h>
int putchar(int c);
int fputc(int c, FILE * stream); // stream에 stdout을 전달하면, putchar과 동일
// 함수 호출 성공 시 쓰여진 문자정보가, 실패 시 EOF 반환
```

- `putchar`: 인자로 전달된 문자정보를 stdout으로 표현되는 표준 출력 스트림으로 전송하는 함수
- `fputc`: putchar 함수와 동일하지만 fputc함수는 문자를 전송할 스트림을 지정할 수 있습니다.
    
    > `putc` 라는 함수도 `fputc` 와 동일하지만, `putc` 는 매크로 함수이며, `fputc` 는 일반 함수 입니다. 일반적으로 `putc` 는 함수 호출의 오버헤드 없이 코드에 직접 삽입되어 실행 속도가 빠르다는 장점이 있습니다. 반면에, `fputc` 는 스레드에 안전 하다는 장점이 있습니다.
    > 

아래는 예제 코드입니다.

```c
#include <stdio.h>

int main(void) {
    char ch = 'A';
    putchar(ch);
    fputc(ch, stdout);
    return 0;
}
/*
AA
*/
```

## 문자 입력 함수: getchar, fgetc

```c
#include <stdio.h>
int getchar(void);
int fgetc(FILE * stream);
// 파일의 끝에 도달하거나 함수호출 실패 시 EOF 반환
```

- `getchar`: stdin으로 표현되는 표준 입력 스트림으로부터 하나의 문자를 입력 받아서 반환하는 함수
- `fgetc`: getchar 함수와 달리 문자를 입력 받을 스트림을 지정할 수 있습니다.

아래는 예제 코드입니다.

```c
#include <stdio.h>

int main(void) {
    char ch;
    ch = getchar();
    putchar(ch);
    fputc(ch, stdout);
    return 0;
}
/*
입력한 문자가 두 번 출력 됩니다.
*/
```

## 문자 입출력의 EOF

EOF란, End Of File의 약자로, 파일의 끝을 표현하기 위해 정의해 놓은 상수 입니다. 아래는 EOF 발생의 예시 입니다.

- 파일의 경우 파일의 끝에 도달해서 ‘더 이상 읽을 내용이 없다’는 뜻입니다.
- 키보드 입력의 경우 사용자가 Ctrl + Z (Windows) 또는 Ctrl + D (Unix 계열) 키를 눌러 '더 이상 입력할 내용이 없다'는 신호를 보낼 수 있습니다. 또한, 함수 호출의 실패 시에도 발생됩니다.

## 문자 입출력 함수의 반환형

문자 입출력 함수의 반환형이 `int`인 이유는 EOF(End Of File)를 제대로 처리하기 위해서입니다. EOF는 파일의 끝을 나타내는 상수로, 일반적으로 `-1`의 값을 가집니다. 즉, 일반적인 문자값과 구분할 수 있는 별도의 값을 반환할 필요가 있습니다. 그렇기 때문에, 이러한 EOF를 처리하기 위해 문자 입출력 함수의 반환형은 `int`로 설정되어 있습니다. 

만약 반환형이 `char`라면, unsigned char로 처리하는 컴파일러의 경우 `-1`이 양의 정수로 형 변환이 발생할 수 있기 때문에 문제가 됩니다. 따라서 모든 상황에서 EOF를 `-1`로 인식할 수 있게 하기 위해 반환형은 `int`로 설정되어 있습니다.

# 문자열 단위 입출력 함수

## 문자열 출력 함수: puts, fputs

```c
#include <stdio.h>
int puts(const char * s);
int fputs(const char * s, FILE * stream);
// 성공 시 음수가 아닌 값을, 실패 시 EOF 반환
```

- `puts`: 출력의 대상이 stdout으로 설정, 함수 호출 시 문자열 출력 후 자동으로 개행이 이루어집니다.
- `fputs`: 두 번째 인자를 통해 출력의 대상을 결정, 함수 호출 시 자동으로 개행이 이루어지지 않습니다.

아래는 예제 코드입니다.

```c
#include <stdio.h>

int main(void)
{
	puts("Hello1");
	fputs("Hello2", stdout);
	fputs("Hello3", stdout);
	return 0;
}
/*
Hello1
Hello2Hello3
*/
```

위 예제 코드는 "Hello, World!" 라는 문자열을 출력합니다. puts 함수는 문자열 출력 후 자동으로 개행이 이루어지며, fputs 함수는 개행이 이루어지지 않습니다.

## 문자열 입력 함수: gets, fgets

```c
#include <stdio.h>
char * gets(char * s);
char * fgets(char * s, int n, FILE * stream);
```

- `gets`: 입력 받은 문자열을 매개변수에 저장, 입력 받는 문자열의 길이를 체크하지 않기 때문에 배열의 크기를 초과하는 문자열이 입력될 경우 메모리 공간을 침범하여 실행 중에 오류가 발생됩니다.
- `fgets`: stream(stdin)으로 부터 문자열을 입력받아서 매개변수에 저장하고 그 길이를 n만큼 저장
    - 문자열 저장 시 `sizeof(str) -1` 만큼 만을 저장 → NULL 문자를 저장하기 위해
    - `\n` 을 만날 때까지 문자열을 읽어 들이기 때문에 중간에 삽입된 공백 문자도 문자열의 일부로 읽어 들인다.

아래는 예제 코드입니다.

```c
#include <stdio.h>

int main(void)
{
	char str[7];
	printf("문자열 입력: ");
	gets(str);
	printf("입력된 문자열: %s \n", str);

	printf("문자열 입력: ");
	fgets(str, sizeof(str), stdin);
	printf("입력된 문자열: %s \n", str);
	return 0;
}
/*
문자열 입력: ABCDEFGHIJKLMN
입력된 문자열: ABCDEFGHIJKLMN 
문자열 입력: ABCDEFGHIJKLMN
입력된 문자열: ABCDEF 
*/
```

# 표준 입출력과 버퍼

## 버퍼란?

버퍼는 일시적으로 데이터를 저장하는 임시 메모리 영역을 의미합니다. 표준 입출력 함수는 내부적으로 버퍼를 사용하여 데이터를 처리합니다.

## 버퍼링을 하는 이유

데이터를 목적지로 바로 전송하지 않고 버퍼(입력 버퍼, 출력 버퍼)에 일시적으로 저장한 뒤, 전송하는 이유 중 가장 큰 이유는 ‘데이터 전송의 효율성’과 관련이 있습니다.

한 번에 많은 양의 데이터를 전송하는 것이 한 번에 한 개의 데이터를 여러 번 전송하는 것보다 효율적이기 때문입니다.

## 출력버퍼를 비우는 함수: fflush

```c
#include <stdio.h>
int fflush(FILE * stream);

// 성공 시 0을, 실패 시 EOF 반환
```

- `fflush`: stream에 지정된 출력버퍼를 비우는 함수입니다. 일반적으로 출력버퍼는 자동으로 비워지지만, 이 함수를 사용하면 출력버퍼를 강제로 비울 수 있습니다. 이는 출력을 즉시 화면에 반영해야 하는 상황에서 유용합니다.

## 입력버퍼의 비워짐

입력버퍼의 비워짐은 데이터의 소멸을 의미하기 때문에 입력 버퍼에 남아있는 불필요한 데이터의 소멸을 위해 사용 됩니다.

만약에 다음의 문자를 출력하는 프로그램이 있을 경우

```c
Hello
World
```

아래의 코드와 같이 작성한다면 비 정상적으로 동작됩니다.

```c
#include <stdio.h>
int main(void)
{
	char str1[6]; // 'Hello', 'World' 모두 5자 이지만, NULL 문자를 고려하여 6으로 계산
	char str2[6];
	fgets(str1, sizeof(str1), stdin);
	fgets(str2, sizeof(str2), stdin);
	printf("%s\n", str1);
	printf("%s\n", str2);
	return 0;
}
/*
Hello
Hello
*/
```

코드 상으로는 NULL 문자도 고려하여 작성된 것 같지만 문제가 발생된 이유는 첫 번째 `fgets` 함수 호출 시 엔터키를 포함한 `Hello↲` 가 입력되어 총 6문자가 입력 되었기 때문입니다.

`fgets` 함수의 인자로 6이 전달되었으니, 널 문자를 제외한 최대 5문자를 읽어 들입니다. 따라서 `\n` 를 제외한 나머지 5문자(`Hello`)만 읽어지고, `\n`은 입력 버퍼에 남아있게 됩니다.

이어서 다음 fgets 함수가 호출되는데 해당 함수는 `\n` 를 만날 때 까지 읽어 들이는 함수 이므로, 버퍼에 남아 있는 `\n` 만 읽어들입니다.

이 문제를 해결하기 위해선 다음과 같이 코드를 작성하면 됩니다.

```c
#include <stdio.h>
int main(void)
{
	char str1[6]; // 'Hello', 'World' 모두 5자 이지만, NULL 문자를 고려하여 6으로 계산
	char str2[6];
	fgets(str1, sizeof(str1), stdin);
  while(getchar() != '\n'); // 입력 버퍼 비우기
	fgets(str2, sizeof(str2), stdin);
	printf("%s\n", str1);
	printf("%s\n", str2);
	return 0;
}
/*
Hello
World
Hello
World
*/
```

코드 `while(getchar() != '\n');` 를 통해 입력 버퍼에 저장된 문자열(`\n`)을 읽어들여 입력 버퍼에 저장된 문자열을 비웠기 때문에 다음 `fgets` 함수도 정상적으로 호출이 가능해집니다.

# 입출력 이외의 문자열 관련 함수

## 문자열 길이를 반환하는 함수: strlen

```c
#include <string.h>
size_t strlen(const char * s); // size_t 반환형은 unsigned int 를 의미 한다.
// 전달된 문자열의 길이를 반환하되, 널 문자는 길이에 포함하지 않는다.
```

## 문자열을 복사하는 함수들: strcpy, strncpy

```c
#include <string.h>
char * strcpy(char * dest, const char * src);
char * strncpy(char * dest, const char * src, size_t n);
```

- `strncpy`: 함수 호출 시 널 문자를 고려해야 하므로 아래와 같이 호출해야 한다.
    
    ```c
    strncpy(str1, str2, sizeof(str1)-1);
    str1[sizeof(str1)-1] = 0; // 널 문자 삽입
    ```
    

## 문자열을 덧붙이는 함수들: strcat, strncat

```c
#include <string.h>
char * strcat(char * dest, const char * src);
char * strncat(char * dest, const char * src, size_t n);
// 덧붙여진 문자열의 주소 값 반환;
```

- 덧 붙여지는 위치는 대상의 NULL 문자 다음이 아닌 NULL 문자 위치로 부터 붙여진다.
- `strncat`: n 만큼의 문자를 덧붙이라는 의미로 널 문자는 포함되지 않으므로 실제로는 총 n + 1(널 문자 포함) 만큼 덧 붙여진다.

## 문자열을 비교하는 함수들: strcmp, strncmp

```c
#include <string.h>
int strcmp(const char * s1, const char * s2);
int strncmp(const char * s1, const char * s2, size_t n);
// 두 문자열의 내용이 같으면 0, 같지 않으면 0이 아닌 값 반환
```

- `strncmp`: 세 번째 인자로 전달된 수의 크기 만큼만 문자를 비교
    - s1이 더 크면 0보다 큰 값 반환
    - s2가 더 크면 0보다 작은 값 반환
    - s1과 s2 내용이 모두 같으면 0 반환

## 그 외의 변환 함수들

```c
#include <stdlib.h>
int atoi(const char * str); // 문자열의 내용을 int형으로 변환
long atol(const char * str); // 문자열의 내용을 long 형으로 변환
double atof(const char * str); // 문자열의 내용을 double 형으로 변환
```

# 예제 출력

```bash
$ gcc -o string_methods.o string_methods.c
$ ./string_methods.o
[*] 문자 단위 입출력 함수 
문자 출력
putchar(): A
fputc(): A
문자 입력(getchar): B
입력한 문자 B
문자 입력(fgetc): C
입력한 문자 C

[*] 문자열 단위 입출력 함수 
문자열 출력
puts(): Hello
fputs(): Hello
warning: this program uses gets(), which is unsafe.
문자열 입력(gets): ABCDEFGHIJKLMN
입력된 문자열: ABCDEFGHIJKLMN 
문자열 입력(fgets): ABCDEFGHIJKLMN
입력된 문자열: ABCDEF 

[*] 입력 버퍼 비우기 
Hello
while(getchar() != '\n');
World
Hello
World

[*] 문자열 관련 함수 
1) 문자열 길이 반환하는 함수: strlen
문자열: Hello, world!
strlen: 13
2) 문자열을 복사하는 함수: strcpy, strncpy
strcpy 복사 결과: Hello, world!
strncpy 복사 결과: Hello
3) 문자열을 덧붙이는 함수: strcat, strncat
원래 문자열: Hello, 
strcat 덧붙이기 결과: Hello, world!
strncat 덧붙이기 결과: Hello, wor
4) 문자열을 비교하는 함수: strcmp, strncmp
str4: abc, str5: abcd
strcmp 결과: -100
strncmp 결과 (처음 3개 문자 비교): 0
5) 그 외의 변환하는 함수들: atoi, atol, atof
문자열 숫자: 12345
atoi 결과 (int): 12345
atol 결과 (long): 12345
atof 결과 (double): 12345.000000
```