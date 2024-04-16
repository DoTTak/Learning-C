# 파일 입출력 예제

아래의 코드는 `example.txt` 라는 파일에 `Hello, Wolrd!\n` 을 작성하고 작성된 텍스트를 다시 읽어서 출력하는 파일 입출력 예제 코드입니다. 

```c
#include <stdio.h>

int main() {
    FILE *file; // 파일 포인터 선언
    char buffer[256]; // 버퍼 선언

    // 파일 출력 스트림
    file = fopen("example.txt", "w"); // "example.txt"라는 이름의 파일을 쓰기 모드(w)로 열기
    if (file == NULL) { // 파일 열기에 실패한 경우
        printf("파일 열기에 실패했습니다.\n");
        return 1;
    }
    fputs("Hello, World!\n", file); // 파일에 "Hello, World!\n"라는 문자열 쓰기
    fflush(file); // 출력 버퍼를 비워 파일에 쓰기
    fclose(file); // 파일 닫기

    // 파일 입력 스트림
    file = fopen("example.txt", "r"); // "example.txt"라는 이름의 파일을 읽기 모드(r)로 열기
    if (file == NULL) { // 파일 열기에 실패한 경우
        printf("파일 열기에 실패했습니다.\n");
        return 1;
    }
    while(fgets(buffer, 256, file) != NULL) { // 파일에서 문자열 읽기
        printf("%s", buffer); // 읽은 문자열 출력
    }
    fclose(file); // 파일 닫기

    return 0;
}
```

# 파일 관련 함수

위 파일 입출력 예제 코드에서 사용된 파일 관련 함수는 다음과 같습니다.

## fopen 함수

`fopen` 함수가 호출되면 FILE 구조체 변수가 생성됩니다. 생성된 FILE 구조체는 파일 포인터로, 파일 입출력 연산에 사용 됩니다. 즉, 파일의 입출력은 이 파일 포인터를 통해 수행합니다.

아래는 `fopen` 함수의 선언 형태 입니다.

```c
#include <stdio.h>
FILE * fopen(const char * filename, const char * mode);
```

`filename`은 파일의 이름을, mode는 파일을 어떤 방식으로 열 것인지를 나타내는 문자열입니다. `mode`에는 여러 가지 옵션들이 있으며, 대표적인 것들은 `r`(읽기 모드), `w`(쓰기 모드), `a`(추가 모드) 등이 있습니다.

예를 들어, 파일을 대상으로 입력과 출력을 하려면 `fopen` 함수를 통해 파일을 지정하고, mode를 통해 입력 또는 출력 모드를 지정하면 됩니다.

> **파일의 개방 모드(Mode)**
> 
> 
> 
> | 모드 | 스트림의 성격 | 파일이 없으면? |
> | --- | --- | --- |
> | r | 읽기 가능 | 에러 |
> | w | 쓰기 가능 | 생성 |
> | a | 파일의 끝에 덧붙여 쓰기 가능 | 생성 |
> | r+ | 읽기/쓰기 가능 | 에러 |
> | w+ | 읽기/쓰기 가능 | 생성 |
> | a+ | 읽기/덧붙여 쓰기 가능 | 생성 |
> 
> **파일의 유형**
> 
> > C 프로그램은 파일을 텍스트 형식으로 읽거나 쓸 경우 개행 처리가 달라집니다.(ex. Windwos: `\r\n`)
> > 
> - 텍스트 파일: `t`
> - 바이너리 파일: `b`
> 
> **운영체제별 개행 처리 방식**
> 
> - MS-DOS: `\r\n`
> - MacOS: `\r`
> - Unix: `\n`
> - C: `\n`

## fclose 함수

`fclose` 함수는 열린 파일을 닫고 관련된 파일 포인터를 해제하는 역할을 합니다. 파일 포인터는 메모리 효율성을 위해 더이상 필요 없을 때 반드시 해제해야 합니다. 이렇게 하면 시스템 자원을 절약하며, 다른 프로세스가 파일에 접근 가능합니다.

```c
#include <stdio.h>
int fclose(FILE * stream);
// 성공 시 0, 실패 시 EOF를 반환
```

## fflush 함수

`fflush` 함수는 출력 스트림의 버퍼를 비워 파일에 쓰는 역할을 합니다. 다시 말해, 출력 버퍼에 저장된 데이터를 목적지(파일)로 전송한다는 의미 입니다. 이는 프로그램이 비정상적으로 종료될 경우 데이터 손실을 방지하는 데 중요합니다.

> fflush 함수는 입력 버퍼를 대상으로 호출할 수 없습니다.
> 

```c
#include <stdio.h>
int fflush(FILE * stream);
// 성공 시 0, 실패 시 EOF 반환
```

# 파일 입출력 함수

파일 구조체 변수에 데이터를 작성하거나 읽으려면 입출력 관련 함수가 필요합니다. 위 예제 코드는 문자열의 입출력을 위해 `fputs`, `fgets` 함수를 사용 했습니다. 이 함수들 외에도 `fputc`, `fgetc` 함수도 파일의 입출력을 수행할 수 있습니다. 해당 함수들을 이용한 예제는 다음과 같습니다.

## 파일 쓰기(fputc, fputs)

```c
#include <stdio.h>

int main() {
    FILE *file;
    char str1[] = "fputc\n"; // 파일에 작성할 문자열
    char str2[] = "fgets\n"; // 파일에 작성할 문자열

    // 파일 쓰기 스트림
    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("파일 열기에 실패했습니다.\n");
        return 1;
    }

    // fputc 사용
    for (int i = 0; str1[i]; i++) {
        fputc(str1[i], file); // 문자 하나씩 파일에 쓰기
    }
    
    // fputs 사용
    fputs(str2, file); // 문자 하나씩 파일에 쓰기

    // 파일 닫기
    fclose(file);

    return 0;
}
```

## 파일 읽기(fgetc, fgets)

> `fgets` 함수를 사용하여 읽어 들일 문자열의 끝에는 반드시 `\n` 문자가 들어가야 합니다.
> 

```c
#include <stdio.h>

int main() {
    FILE *file;
    char str[30];

    // 파일 읽기 스트림
    file = fopen("example.txt", "rt");
    if (file == NULL) {
        printf("파일 열기에 실패했습니다.\n");
        return 1;
    }

    // fgetc 사용
    str[0] = fgetc(file); // f
    printf("%c", str[0]);
    str[0] = fgetc(file); // p
    printf("%c", str[0]);
    str[0] = fgetc(file); // u
    printf("%c", str[0]);
    str[0] = fgetc(file); // t
    printf("%c", str[0]);
    str[0] = fgetc(file); // c
    printf("%c", str[0]);
    str[0] = fgetc(file); // \n
    printf("%c", str[0]);
 
    // fgets 사용
    fgets(str, sizeof(str), file);
    printf("%s", str); // fputs

    // 파일 닫기
    fclose(file);

    return 0;
}

```

# 바이너리 데이터의 입출력(fread, fwrite)

`fread` 함수와 `fwrite` 함수는 각각 바이너리 데이터를 읽고 쓸 때 사용됩니다. 이 함수들은 파일에서 지정된 크기와 개수의 데이터를 읽거나 쓸 수 있습니다.

`fread` 함수는 파일에서 지정된 크기의 데이터를 지정된 개수 만큼 읽어서 메모리에 저장합니다.

```c
#include <stdio.h>
size_t fread(void * ptr, size_t size, size_t count, FILE * stream);

```

`ptr`은 데이터를 저장할 메모리의 주소, `size`는 읽을 데이터의 크기, `count`는 읽을 데이터의 개수, `stream`은 파일 포인터입니다. 성공적으로 읽은 데이터의 개수를 반환합니다.

`fwrite` 함수는 메모리에서 지정된 크기의 데이터를 지정된 개수 만큼 읽어서 파일에 씁니다.

```c
#include <stdio.h>
size_t fwrite(const void * ptr, size_t size, size_t count, FILE * stream);

```

`ptr`은 데이터의 주소, `size`는 쓸 데이터의 크기, `count`는 쓸 데이터의 개수, `stream`은 파일 포인터입니다. 성공적으로 쓴 데이터의 개수를 반환합니다.

## 예제코드

다음은 `fread`와 `fwrite`를 사용하여 바이너리 데이터를 파일에 쓰고 읽는 예제 코드입니다. 이 코드는 구조체 배열을 파일에 쓰고, 다시 읽어와서 출력합니다.

```c
#include <stdio.h>

typedef struct {
    char name[20];
    int age;
} Person;

int main() {
    FILE *file;
    Person people[3] = {
        {"Kim", 20},
        {"Dowon", 30},
        {"DoTTak", 40}
    };
    Person buffer[3];

    // 파일 쓰기 스트림
    file = fopen("people.bin", "wb");
    if (file == NULL) {
        printf("파일 열기에 실패했습니다.\n");
        return 1;
    }

    // fwrite 사용
    fwrite(people, sizeof(Person), 3, file);
    fclose(file);

    // 파일 읽기 스트림
    file = fopen("people.bin", "rb");
    if (file == NULL) {
        printf("파일 열기에 실패했습니다.\n");
        return 1;
    }

    // fread 사용
    fread(buffer, sizeof(Person), 3, file);
    fclose(file);

    // 출력
    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d\n", buffer[i].name, buffer[i].age);
    }

    return 0;
}
```

# 텍스트와 바이너리 데이터의 동시 입출력(fprintf, fscanf)

`fprintf` 함수와 `fscanf` 함수는 각각 파일에 서식을 지정하여 데이터를 쓰거나 읽을 때 사용됩니다. 이 함수들은 파일에서 지정된 서식에 따라 데이터를 쓰거나 읽을 수 있습니다.

`fprintf` 함수는 지정된 파일에 서식에 따라 데이터를 씁니다. `printf` 함수와 비슷하나, 첫 번째 인자로 파일 포인터를 받습니다.

```c
#include <stdio.h>
int fprintf(FILE * stream, const char * format, ...);

```

`fscanf` 함수는 지정된 파일에서 서식에 따라 데이터를 읽습니다. `scanf` 함수와 비슷하나, 첫 번째 인자로 파일 포인터를 받습니다.

```c
#include <stdio.h>
int fscanf(FILE * stream, const char * format, ...);

```

## 예제코드

다음은 `fprintf`와 `fscanf`를 사용하여 파일에 데이터를 쓰고 읽는 예제 코드입니다. 이 코드는 구조체를 파일에 쓰고, 다시 읽어와서 출력합니다.

```c
#include <stdio.h>

typedef struct {
    char name[20];
    int age;
} Person;

int main() {
    FILE *file;
    Person person1 = {"DoTTak", 20};
    Person person2;

    // 파일 쓰기 스트림
    file = fopen("person.txt", "w");
    if (file == NULL) {
        printf("파일 열기에 실패했습니다.\n");
        return 1;
    }

    // fprintf 사용
    fprintf(file, "%s %d\n", person1.name, person1.age);
    fclose(file);

    // 파일 읽기 스트림
    file = fopen("person.txt", "r");
    if (file == NULL) {
        printf("파일 열기에 실패했습니다.\n");
        return 1;
    }

    // fscanf 사용
    fscanf(file, "%s %d", person2.name, &person2.age);
    fclose(file);

    // 출력
    printf("Name: %s, Age: %d\n", person2.name, person2.age);

    return 0;
}

```

# feof와 파일 위치 지시자

`feof` 함수는 파일의 끝(EOF, End Of File)에 도달했는지를 확인하는 함수입니다. 이는 파일에서 데이터를 읽거나 쓰는 동안, 파일의 끝에 도달하면 `feof` 함수가 참(True)을 반환함으로써 확인할 수 있습니다.

이 때, 파일의 끝을 알게 되는 기준은 '파일 위치 지시자'라는 것이 있기 때문입니다. ‘파일 위치 지시자’란, 파일 내에서 현재 위치를 가리키는 지시자입니다. 파일에서 데이터를 읽거나 쓸 때, 파일 위치 지시자는 자동으로 이동합니다. 이 ‘파일 위치 지시자’를 이용하면 데이터가 어느 위치에 쓰였는지 또는 어디서부터 읽혀야 하는지를 알 수 있습니다. 파일 위치 지시자의 위치는 `fseek`, `ftell` 함수를 사용하여 조작할 수 있습니다.

## feof 함수

`feof` 함수는 파일의 끝(EOF)에 도달했는지 확인하는 데 사용됩니다. 파일에서 데이터를 읽거나 쓰는 동안 파일의 끝에 도달하면 `feof` 함수는 참을 반환합니다. 이 함수를 사용하여 파일에서 더 이상 읽을 데이터가 없음을 확인할 수 있습니다.

```c
#include <stdio.h>
int feof(FILE * stream);
// 파일의 끝에 도달한 경우 0이 아닌 값 반환
```

## fseek 함수

`fseek` 함수는 파일 위치 지시자의 위치를 변경하는 데 사용됩니다. 이 함수는 파일 내에서 임의로 접근할 수 있게 해줍니다. 파일을 읽거나 쓸 때 필요한 위치로 파일 위치 지시자를 이동시킬 수 있습니다.

```c
#include <stdio.h>
int fseek(FILE * stream, long offset, int wherefrom);
// 성공 시 0, 실패 시 0이 아닌 값을 반환
```

- stream으로 전달된 파일 위치 지시자를 wherefrom에서부터 offset 바이트 만큼 이동 됩니다.
- wherefrom에 전달될 수 있는 상수와 그 의미
    
    
    | 매개변수 werefrom 이… | 파일 위치 지시자는… |  |
    | --- | --- | --- |
    | SEEK_SET(0) 이라면… | 파일 맨 앞에서부터 이동을 시작 | 첫 번째 바이트에서 부터 |
    | SEEK_CUR(1) 이라면 | 현재 위치에서부터 이동을 시작 | EOF에서부터 |
    | SEEK_END(2) 이라면 | 파일 맨 끝에서부터 이동을 시작 | 음수로 전달되면 왼쪽(앞 부분)으로 이동 |

## ftell 함수

`ftell` 함수는 파일 위치 지시자의 현재 위치를 반환합니다. 이 함수는 파일의 시작부터 파일 위치 지시자의 위치까지의 오프셋을 바이트 단위로 반환합니다.

```c
#include <stdio.h>
long ftell(FILE * stream);
// 파일 위치 지시자의 위치 정보 반환
```

## 예제 코드

아래는 파일을 생성하고, `feof`, `fseek`, `ftell` 함수를 사용하는 예제 코드입니다. 이 코드는 먼저 `example.txt` 파일을 생성하고 문자열을 작성한 후, 파일에서 문자를 하나씩 읽어서 출력하고, 파일의 끝에 도달하면 종료합니다.

```c
#include <stdio.h>

int main() {
    FILE *file;
    char ch;

    // 파일 쓰기 스트림
    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("파일 생성에 실패했습니다.\n");
        return 1;
    }

    // 파일에 문자열 쓰기
    fputs("Hello, World!\n", file);
    fclose(file);

    // 파일 읽기 스트림
    file = fopen("example.txt", "r+");
    if (file == NULL) {
        printf("파일 열기에 실패했습니다.\n");
        return 1;
    }

    // 파일에서 문자를 하나씩 읽어서 출력
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    // 파일의 끝에 도달했는지 확인
    if (feof(file)) {
        printf("\n파일의 끝에 도달했습니다.\n");
    } else {
        printf("\n파일 읽기 중 오류가 발생했습니다.\n");
    }

    // 파일의 현재 위치 확인
    long pos = ftell(file);
    printf("파일 위치 지시자의 현재 위치: %ld\n", pos);

    // 파일 위치 지시자의 위치를 파일의 시작으로 이동
    fseek(file, 0, SEEK_SET);
    pos = ftell(file);
    printf("파일 위치 지시자의 현재 위치: %ld\n", pos);

    // 특정 위치에 문자열 쓰기
    fseek(file, 12, SEEK_SET); // 파일의 12번째 위치로 이동 ('!' 위치에 ' C programming' 작성하기)
    fputs(" C programming", file); // 지정된 위치에 문자열 쓰기

    // 파일 닫기
    fclose(file);

    return 0;
}
```

# 예제 출력

```bash
$ gcc -o file.o file.c
$ ./file.o
[*] 파일 입출력 예제 코드
Hello, World!

[*] 파일 입출력 함수 - 파일 쓰기(fputc, fputs)

[*] 파일 입출력 함수 - 파일 읽기(fgetc, fgets)
fputc
fgets

[*] 바이너리 데이터의 입출력
Name: Kim, Age: 20
Name: Dowon, Age: 30
Name: DoTTak, Age: 40

[*] 텍스트와 바이너리 데이터의 동시 입출력
Name: DoTTak, Age: 20

[*] feof와 파일 위치 지시자
Hello, World!

파일의 끝에 도달했습니다.
파일 위치 지시자의 현재 위치: 14
파일 위치 지시자의 현재 위치: 0

```