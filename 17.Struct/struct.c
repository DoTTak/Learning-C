#include <stdio.h>
#include <string.h>

/* 구조체 정의 1 */
struct Student {
    char name[50]; // 이름
    int age; // 나이
    float gpa; // 평균 성적
};

/* 구조체 정의 2 - 구조체 정의와 구조체 변수의 선언 동시 사용 */
// struct Student {
//     char name[50]; // 이름
//     int age; // 나이
//     float gpa; // 평균 성적
// };

/* 구조체 멤버로 포인터 변수 추가 */
struct Address {
    char street[100]; // 도로명 주소
    char postalCode[20]; // 우편 번호
};
struct StudentWithPtr {
    char name[50]; // 이름
    int age; // 나이
    float gpa; // 평균 성적
    struct Address * addr;
};
struct StudentWithStruct {
    char name[50]; // 이름
    int age; // 나이
    float gpa; // 평균 성적
    struct Address addr;
};

// Call-By-Value 함수: 학생 정보를 출력
void printStudentByValue(struct Student std) {
    printf("Call-By-Value로 학생 정보 출력\n");
    printf("이름: %s\n", std.name);
    printf("나이: %d\n", std.age);
    printf("평균 성적: %.2f \n", std.gpa);
}

// Call-By-Value 함수: 학생 정보를 새로운 구조체로 복사하여 반환
struct Student copyStudentByValue(struct Student std) {
    struct Student copy;
    strcpy(copy.name, std.name);
    copy.age = std.age;
    copy.gpa = std.gpa;
    return copy;
}

// Call-By-Reference 함수: 학생 정보를 출력
void printStudentByReference(const struct Student *std) {
    printf("Call-By-Reference로 학생 정보 출력\n");
    printf("이름: %s\n", std->name);
    printf("나이: %d\n", std->age);
    printf("평균 성적: %.2f \n", std->gpa);
}

// Call-By-Reference 함수: 학생 정보의 나이를 증가시킴
void increaseAgeByReference(struct Student *std) {
    std->age++;
}

int main(void)
{
    printf("[*] 구조체 변수의 선언과 접근\n");
    struct Student student0;
    // 구조체 변수 초기화
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

    printf("\n");

    printf("[*] 구조체 배열의 선언과 접근\n");
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
        printf("%d번 학생\n", i);
        printf("학생 이름: %s\n", students[i].name);
        printf("나이: %d\n", students[i].age);
        printf("평균 성적: %.2f\n", students[i].gpa);
    }

    printf("\n");

    printf("[*] 구조체 포인터\n"); 
    // 구조체 포인터 선언
    struct Student student2;
    struct Student *ptrStudent;

    // 구조체 포인터에 구조체 변수의 주소 할당
    ptrStudent = &student2;

    // 구조체 포인터를 통해 구조체 멤버에 접근하여 값 할당
    strcpy((*ptrStudent).name, "DoTTak"); // ptrStudent이 가리키는 구조체 변수의 멤버 name 접근
    ptrStudent->age = 20; // ptrStudent이 가리키는 구조체 변수의 멤버 age 접근
    ptrStudent->gpa = 3.8;

    // 구조체 멤버 값 출력
    printf("이름: %s\n", ptrStudent->name);
    printf("나이: %d\n", ptrStudent->age);
    printf("평균 성적: %.2f\n", ptrStudent->gpa);

    printf("\n");

    printf("[*] 포인터 변수를 구조체 멤버로 선언\n");
    // 선언 및 초기화
    struct Address addr = {"이것은 도로명로", "333-3333"};
    struct StudentWithPtr student3 = {"DoTTak", 20, 3.5, &addr};
    // 접근
    printf("%s \n", student3.addr->street); // 도로명 주소 출력
    printf("%s \n", student3.addr->postalCode); // 우편 번호 출력

    printf("\n");

    printf("[*] 구조체 변수의 주소 값\n");
    struct Student student4;
    strcpy(student4.name, "DoTTak");
    student4.age = 21;
    student4.gpa = 3.5;

    printf("구조체 변수의 주소: %p \n", &student4);
    printf("구조체 변수 첫 번째 멤버의 주소 %p \n", &student4.name);

    printf("\n");

    printf("[*] 함수와 구조체 변수\n");
    // 구조체 변수 선언 및 초기화
    struct Student student5 = {"DoTTak", 20, 3.8};
    // Call-By-Value 함수 호출: 학생 정보 출력
    printStudentByValue(student5);
    // Call-By-Value 함수 호출: 학생 정보를 복사하여 반환받아 새로운 구조체 변수에 저장
    struct Student copiedStudent = copyStudentByValue(student5);
    // 반환된 구조체 변수의 정보 출력
    printf("Call-By-Value로 복사된 학생 정보\n");
    printStudentByValue(copiedStudent);
    // Call-By-Reference 함수 호출: 학생 정보 출력
    printStudentByReference(&student5);
    // Call-By-Reference 함수 호출: 학생 정보의 나이를 증가시킴
    increaseAgeByReference(&student5);
    // 변경된 학생 정보 출력
    printf("Call-By-Reference로 나이가 증가된 학생 정보\n");
    printStudentByReference(&student5);

    printf("\n");

    printf("[*] 구조체 변수를 대상으로하는 연산\n");
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

    printf("\n");
    
    printf("[*] 중첩된 구조체의 정의 및 변수 선언\n");
    // 초기화
    struct StudentWithStruct student = {"DoTTak", 28, 3.4, {"이것은 도로명로", "333-3333"}};

    // 접근
    printf("%s \n", student.addr.street); // 도로명 주소 출력
    printf("%s \n", student.addr.postalCode); // 우편 번호 출력

    return 0;
}