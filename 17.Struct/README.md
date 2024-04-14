# 구조체

## 구조체란?

구조체는 다양한 데이터 타입을 하나로 묶어서 다루는 방식입니다.

```c
struct 구조체이름 {
    자료형 멤버이름1;
    자료형 멤버이름2;
    // 추가 멤버들...
};
```

여기서 `struct`는 구조체를 정의할 때 사용하는 키워드이며, `구조체이름`은 사용자가 지정하는 구조체의 이름입니다. 이어지는 중괄호 `{}` 내부에는 멤버들의 선언이 들어갑니다. 각 멤버는 자료형과 멤버이름으로 구성됩니다.

다음은 학생의 이름, 나이, 평균 성적을 구조체로 정의한 예시 입니다.

```c
struct Student {
    char name[50]; // 이름
    int age; // 나이
    float gpa; // 평균 성적
};
```

## 구조체 변수의 선언과 접근

위에서 정의한 학생 구조체를 이용하여 구조체 변수의 선언과 접근에 대해 알아보겠습니다.

```c
struct Student student0; // 구조체 변수 선언

// 구조체 변수 초기화
strcpy(student0.name, "Dowon"); // 문자열 배열은 배열 요소에 직접 값을 대입할 수 없으므로 strcpy를 사용
student0.age = 21;
student0.gpa = 3.5;

struct Student student1 = {"DoTTak", 20, 3.8}; // 구조체 변수 선언 및 초기화

// 구조체 멤버 접근 및 출력
printf("이름: %s\n", student1.name);
printf("나이: %d\n", student1.age);
printf("평균 성적: %.2f\n", student1.gpa);

// 구조체 멤버 수정
student1.age = 21;
student1.gpa = 3.9;

// 수정된 구조체 멤버 출력
printf("수정된 나이: %d\n", student1.age);
printf("수정된 평균 성적: %.2f\n", student1.gpa);
```

코드 설명은 다음과 같습니다.

1. `struct Student student0;` 을 통해 구조체 변수를 선언합니다.
    1. 선언된 구조체 변수를 `strcpy(student0.name, "dowon");` 과 같이 초기화 할 수 있습니다.
2. `struct Student student1 = {"John", 20, 3.8};`을 통해 `Student` 구조체 타입의 `student1` 변수를 선언하고 초기화합니다.
3. `student1.name`, `student1.age`, `student1.gpa`와 같이 구조체 멤버에 접근하여 값을 출력합니다.
4. 구조체 멤버인 `age`와 `gpa`를 수정하고, 수정된 값을 다시 출력합니다.

이렇게 구조체 멤버에 접근할 때는 구조체 변수 이름 뒤에 점(`.`)을 붙이고 멤버 이름을 사용 합니다.

또한, 구조체 정의와 변수의 선언을 다음과 같이 동시에 가능합니다.

```c
struct Student {
    char name[50];
    int age;
    float gpa;
} student1, student2 = {"Kim", 20, 3.8}; // 구조체 정의와 구조체 변수의 선언을 동시에도 가능

// 또는
struct Student student3;
```

## 구조체 배열의 선언과 접근

구조체도 새로운 자료형으로 배열의 선언과 접근이 가능합니다.

```c
struct Student students[3]; // 크기가 3인 구조체 배열 선언

// 각 구조체 배열 요소에 접근하여 값 할당
strcpy(students[0].name, "Kim");
students[0].age = 20;
students[0].gpa = 3.7;

strcpy(students[1].name, "Dowon");
students[1].age = 21;
students[1].gpa = 3.9;

strcpy(students[2].name, "DoTTak");
students[2].age = 19;
students[2].gpa = 3.5;

// 구조체 배열 요소의 값 출력
for (int i = 0; i < 3; i++) {
    printf("학생 이름: %s\n", students[i].name);
    printf("나이: %d\n", students[i].age);
    printf("평균 성적: %.2f\n", students[i].gpa);
    printf("\n");
}
```

## 구조체 포인터

구조체 포인터를 사용하면 구조체 변수의 주소를 저장하고 해당 주소를 이용하여 구조체 멤버에 접근할 수 있습니다.

```c
// 구조체 포인터 선언
struct Student student1;
struct Student *ptrStudent;

// 구조체 포인터에 구조체 변수의 주소 할당
ptrStudent = &student1;

// 구조체 포인터를 통해 구조체 멤버에 접근하여 값 할당
strcpy((*ptrStudent).name, "DoTTak"); // ptrStudent이 가리키는 구조체 변수의 멤버 name 접근
ptrStudent->age = 20; // ptrStudent이 가리키는 구조체 변수의 멤버 age 접근
ptrStudent->gpa = 3.8;

// 구조체 멤버 값 출력
printf("이름: %s\n", ptrStudent->name);
printf("나이: %d\n", ptrStudent->age);
printf("평균 성적: %.2f\n", ptrStudent->gpa);
```

구조체 포인터 변수가 가리키는 구조체 변수의 멤버에 접근은 아래 두 가지 방식을 사용할 수 있습니다.

- `(*구조체 포인터 변수).구조체 멤버` → `(*ptrStudent).name`
- `구조체 포인터변수->구조체 멤버` → `ptrStudent->age`

## 포인터 변수를 구조체  멤버로 선언

포인터 변수는 일반 변수와 마찬가지로 구조체 멤버로 사용될 수 있습니다. 포인터 변수를 구조체 내부에 선언할 때는 해당 포인터가 가리키는 자료형에 대한 정보가 필요합니다.

```c
// 주소 정보를 담는 구조체 정의
struct Address {
    char street[100]; // 도로명 주소
    char postalCode[20]; // 우편 번호
};

struct Student {
    char name[50]; // 이름
    int age; // 나이
    float gpa; // 평균 성적
    struct Address * addr; // 포인터 변수를 멤버로 선언
};
```

위 코드의 경우 Student 구조체 변수의 주소 정보에 접근은 다음과 같이 할 수 있습니다.

```c
// 선언 및 초기화
struct Address addr = {"이것은 도로명로", "333-3333"};
struct Student student = {"DoTTak", 20, 3.5, &addr};

// 접근
printf("%s \n", student.addr->street); // 도로명 주소 출력
printf("%s \n", student.addr->postalCode); // 우편 번호 출력
```

## 구조체 변수의 주소 값

구조체 변수의 주소 값은 구조체 변수의 첫 번째 멤버의 주소와 동일 합니다.

```c
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50]; // 이름
    int age; // 나이
    float gpa; // 평균 성적
};

int main(void)
{
    struct Student student0;
    strcpy(student0.name, "DoTTak");
    student0.age = 21;
    student0.gpa = 3.5;

    printf("구조체 변수의 주소: %p \n", &student0);
    printf("구조체 변수 첫 번째 멤버의 주소 %p \n", &student0.name);
    return 0;
}

/*
구조체 변수의 주소: 0x16b24b03c 
구조체 변수 첫 번째 멤버의 주소 0x16b24b03c 
*/
```

## 함수와 구조체 변수

구조체를 함수의 인자로 받아 처리하거나 함수의 결과 값으로 반환할 수 있습니다. 이 경우, 함수는 구조체의 복사본을 생성하므로(Call-By-Value) 원본 구조체에 영향을 미치지 않습니다. 만약 원본 구조체를 수정하려는 경우, 구조체 포인터를 사용해야 합니다.

### Call-By-Value

```c
#include <stdio.h>
#include <string.h>

// 학생 구조체 정의
struct Student {
    char name[50];
    int age;
    float gpa;
};

// Call-By-Value 함수: 학생 정보를 출력
void printStudentByValue(struct Student std) {
    printf("Call-By-Value로 학생 정보 출력:\n");
    printf("이름: %s\n", std.name);
    printf("나이: %d\n", std.age);
    printf("평균 성적: %.2f\n", std.gpa);
}

// Call-By-Value 함수: 학생 정보를 새로운 구조체로 복사하여 반환
struct Student copyStudentByValue(struct Student std) {
    struct Student copy;
    strcpy(copy.name, std.name);
    copy.age = std.age;
    copy.gpa = std.gpa;
    return copy;
}

int main() {
    // 구조체 변수 선언 및 초기화
    struct Student student = {"DoTTak", 20, 3.8};

    // Call-By-Value 함수 호출: 학생 정보 출력
    printStudentByValue(student);

    // Call-By-Value 함수 호출: 학생 정보를 복사하여 반환받아 새로운 구조체 변수에 저장
    struct Student copiedStudent = copyStudentByValue(student);

    // 반환된 구조체 변수의 정보 출력
    printf("\nCall-By-Value로 복사된 학생 정보:\n");
    printStudentByValue(copiedStudent);

    return 0;
}
```

- `printStudentByValue` 함수는 `struct Student std`를 값으로 전달받습니다.
- `copyStudentByValue` 함수는 `struct Student std`를 값으로 전달받아 복사본을 만들어 반환합니다.

### Call-By-Reference

```c
#include <stdio.h>
#include <string.h>

// 학생 구조체 정의
struct Student {
    char name[50];
    int age;
    float gpa;
};

// Call-By-Reference 함수: 학생 정보를 출력
void printStudentByReference(const struct Student *std) {
    printf("Call-By-Reference로 학생 정보 출력:\n");
    printf("이름: %s\n", std->name);
    printf("나이: %d\n", std->age);
    printf("평균 성적: %.2f\n", std->gpa);
}

// Call-By-Reference 함수: 학생 정보의 나이를 증가시킴
void increaseAgeByReference(struct Student *std) {
    std->age++;
}

int main() {
    // 구조체 변수 선언 및 초기화
    struct Student student = {"DoTTak", 22, 4.0};

    // Call-By-Reference 함수 호출: 학생 정보 출력
    printStudentByReference(&student);

    // Call-By-Reference 함수 호출: 학생 정보의 나이를 증가시킴
    increaseAgeByReference(&student);

    // 변경된 학생 정보 출력
    printf("\nCall-By-Reference로 나이가 증가된 학생 정보:\n");
    printStudentByReference(&student);

    return 0;
}

```

- `printStudentByReference` 함수는 `const struct Student *std`를 포인터로 전달받습니다. 이는 구조체를 변경하지 않고 출력만 하는 함수에 사용됩니다.
- `increaseAgeByReference` 함수는 `struct Student *std`를 포인터로 전달받아 구조체의 나이를 변경합니다.

## 구조체 변수를 대상으로 연산

구조체 변수를 대상으로 연산을 할 경우에는 ‘대입연산’, ‘주소 반환’, 변수의 크기를 계산하는 ‘sizeof’ 정도의 연산만 가능합니다. 그 이유는 구조체는 여러 개의 다른 타입의 변수를 하나로 묶은 데이터 타입이기에 구조체 전체에 대한 연산은 제한되어 있기 때문입니다.

가능한 연산에 대한 설명은 다음과 같습니다.

- 대입연산: 구조체 변수 전체를 다른 구조체 변수에 대입할 수 있습니다. 이는 각 멤버를 개별적으로 복사하는 것과 같습니다.
- 주소 반환: 구조체 변수의 주소를 가져오는 것이 가능합니다. 이 주소는 구조체의 첫 번째 멤버의 주소와 같습니다.
- sizeof 연산: 구조체의 전체 크기를 계산하는 것이 가능합니다. 이는 구조체의 모든 멤버 크기의 합 입니다.

다른 연산자들, 예를 들어 덧셈, 뺄셈, 곱셈 등은 구조체 전체에 대해 적용할 수 없습니다. 이는 구조체의 멤버들이 서로 다른 데이터 타입을 가질 수 있기 때문입니다. 따라서 이런 연산들은 개별 멤버에 대해 수행해야 합니다. 이에 대한 예제는 다음과 같습니다.

```c
#include <stdio.h>
#include <string.h>

// 학생 구조체 정의
struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    // 3명의 학생 정보를 저장할 구조체 배열 선언
    struct Student students[3];

    // 학생 정보 입력
    strcpy(students[0].name, "Kim");
    students[0].age = 20;
    students[0].gpa = 3.7;

    strcpy(students[1].name, "Dowon");
    students[1].age = 21;
    students[1].gpa = 3.9;

    strcpy(students[2].name, "DoTTak");
    students[2].age = 19;
    students[2].gpa = 4.0;

    // 전체 학생의 평균 성적 계산
    float totalGPA = 0.0;
    int numStudents = 3;

    for (int i = 0; i < numStudents; i++) {
        totalGPA += students[i].gpa;
    }

    float averageGPA = totalGPA / numStudents;

    // 학생 정보 및 평균 성적 출력
    printf("학생 정보 및 평균 성적:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("이름: %s, 나이: %d, 평균 성적: %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }

    printf("전체 학생의 평균 성적: %.2f\n", averageGPA);

    return 0;
}

```

## 중첩된 구조체의 정의 및 변수 선언

구조체를 정의할 때 멤버의 자료형을 다른 구조체를 선언할 수 있습니다. 이를 통해 복잡한 데이터 구조를 만들 수 있습니다.

```c
// 주소 정보를 담는 구조체 정의
struct Address {
    char street[100];
    char postalCode[20];
};

struct Student {
    char name[50]; // 이름
    int age; // 나이
    float gpa; // 평균 성적
    struct Address addr; // Address 구조체를 중첩
};

```

위 코드의 경우 Student 구조체 변수의 주소 정보에 접근은 다음과 같이 할 수 있습니다.

```c
// 초기화
struct Student student = {"DoTTak", 28, 3.4, {"이것은 도로명로", "333-3333"}};

// 접근
printf("%s \n", student.addr.street); // 도로명 주소 출력
printf("%s \n", student.addr.postalCode); // 우편 번호 출력

```

# typedef

## typedef란

`typedef`는 자료형에 별칭을 붙이는 기능을 합니다.

```c
typdef int INT; // int 자료형에 INT 라는 새로운 이름을 부여
INT num; // int num;과 동일
```

## 구조체의 typedef 선언

구조체를 `typedef`로 선언하면, 구조체를 선언할 때마다 `struct` 키워드를 사용하지 않아도 됩니다.

```c
typedef struct Student {
    char name[50]; // 이름
    int age; // 나이
    float gpa; // 평균 성적
} STUDENT;

// 또는

// 구조체 이름을 생략할 수도 있습니다.
typedef struct {
    char name[50]; // 이름
    int age; // 나이
    float gpa; // 평균 성적
} STUDENT;

```

위의 예제에서 `STUDENT`는 `struct Student`의 별칭입니다. 아래의 코드처럼 `STUDENT`를 사용하여 구조체 변수를 선언할 수 있습니다.

```c
STUDENT student1; // struct 키워드 없이 구조체 변수 선언 가능

```

# 공용체(Union Type)의 정의와 의미

## 구조체 vs 공용체

공용체와 구조체는 많은 면에서 유사하지만, 주요한 차이점이 있습니다. 구조체는 여러 멤버들이 모두 독립적인 메모리 공간을 갖지만, 공용체는 모든 멤버들이 동일한 메모리 공간을 공유합니다. 이 때문에 공용체의 크기는 가장 큰 멤버의 크기와 같습니다. 다시 말해, 공용체 내에서는 한 번에 하나의 멤버만 사용할 수 있습니다.

## 공용체의 정의와 선언

공용체는 `union` 키워드를 사용하여 정의하며, 다음과 같이 선언합니다.

```c
typedef union ubox
{
    int mem1;
    int mem2;
    double mem3;
} UBox;
```

위 예제에서는 세 개의 멤버로 구성된 공용체를 정의합니다. 그리고 각 멤버는 같은 메모리 공간을 공유하게 됩니다.

예를 들어, 위 공용체는 `mem1` 가 4바이트, `mem2` 가 4바이트, `mem3` 가 8바이트로 구성되므로 공용체의 크기는 8 바이트가 됩니다.

```
| <-------mem1------->| // 4byte
| <-------mem2------->| // 4byte
| <-------mem3---------------------------->| // 8byte
```

## 중첩된 형태의 공용체

```c
typedef struct dbshort
{
    unsigned short upper;
    unsigned short lower;
} DBshort;

typedef union rdbuf
{
    int iBuf;
    char bBuf[4];
    DBshort sBuf;
} RDBuf;
```

이 경우 공용체 변수 `rdbuf` 는 메모리 공간에 다음의 형태로 할당되고 공유 됩니다.

```
|  <-1byte->  |  <-1byte->  |  <-1byte->  |  <-1byte->  |
| <-bBuf[0]-> | <-bBuf[1]-> | <-bBuf[2]-> | <-bBuf[3]-> |
| <-------sBuf.upper------->|<-------sBuf.lower-------> |
| <------------------------iBuf-----------------------> | 4 byte
```

# 열거형(Enumerated Type)의 정의와 의미

## 열거형

열거형은 서로 관련 있는 값들을 묶어 놓기 위한 사용자 정의 데이터 타입입니다. `enum` 키워드를 사용하여 열거형을 정의하며, 열거형의 각 요소는 특정한 정수값을 가집니다. 기본적으로 첫 번째 요소는 0, 다음 요소는 1, 그리고 이어서 1씩 증가합니다. 하지만 이 값들은 사용자가 임의로 변경할 수 있습니다.

## 열거형의 정의 및 선언

열거형은 다음과 같이 정의 및 선언할 수 있습니다.

```c
enum DAY {SUN, MON, TUE, WED, THU, FRI, SAT}; // 열거형 정의

enum DAY today; // 열거형 변수 선언

```

이 경우, `SUN`은 0, `MON`은 1, `TUE`은 2와 같이 값이 할당됩니다.

사용자는 필요에 따라 각각의 열거형 값에 다른 정수값을 할당할 수도 있습니다.

```c
enum DAY {SUN = 7, MON = 1, TUE, WED, THU, FRI, SAT}; // 열거형 정의

```

이 경우, `SUN`은 7, `MON`은 1, 그리고 `TUE`은 `MON`의 다음 값인 2가 할당됩니다. 이런 방식으로, 열거형을 사용하면 코드의 가독성을 높이고 오류 가능성을 줄일 수 있습니다.

또한, 열거형은 switch 문과 같이 사용되기도 합니다. 예를 들어, 다음과 같은 코드를 작성할 수 있습니다.

```c
enum DAY day;

// ...

switch (day) {
    case SUN:
        printf("Sunday");
        break;
    case MON:
        printf("Monday");
        break;
    // ...
}

```

이런 경우, 열거형을 사용하면 각 case에서 문자열이 아닌 열거형 값을 사용하여 코드를 더욱 명확하게 만들 수 있습니다.

# 예제 출력

```bash
$ gcc -o struct.o struct.c
$ ./struct.o
[*] 구조체 변수의 선언과 접근
이름: DoTTak
나이: 20
평균 성적: 3.80
수정된 나이: 21
수정된 평균 성적: 3.90

[*] 구조체 배열의 선언과 접근
0번 학생
학생 이름: Kim
나이: 20
평균 성적: 3.70
1번 학생
학생 이름: Dowon
나이: 21
평균 성적: 3.90
2번 학생
학생 이름: DoTTak
나이: 19
평균 성적: 3.50

[*] 구조체 포인터
이름: DoTTak
나이: 20
평균 성적: 3.80

[*] 포인터 변수를 구조체 멤버로 선언
이것은 도로명로 
333-3333 

[*] 구조체 변수의 주소 값
구조체 변수의 주소: 0x16f452e44 
구조체 변수 첫 번째 멤버의 주소 0x16f452e44 

[*] 함수와 구조체 변수
Call-By-Value로 학생 정보 출력
이름: DoTTak
나이: 20
평균 성적: 3.80 
Call-By-Value로 복사된 학생 정보
Call-By-Value로 학생 정보 출력
이름: DoTTak
나이: 20
평균 성적: 3.80 
Call-By-Reference로 학생 정보 출력
이름: DoTTak
나이: 20
평균 성적: 3.80 
Call-By-Reference로 나이가 증가된 학생 정보
Call-By-Reference로 학생 정보 출력
이름: DoTTak
나이: 21
평균 성적: 3.80 

[*] 구조체 변수를 대상으로하는 연산
학생 정보 및 평균 성적:
이름: Kim, 나이: 20, 평균 성적: 3.70
이름: Dowon, 나이: 21, 평균 성적: 3.90
이름: DoTTak, 나이: 19, 평균 성적: 3.50
전체 학생의 평균 성적: 3.70

[*] 중첩된 구조체의 정의 및 변수 선언
이것은 도로명로 
333-3333 
```