#include <stdio.h>

typedef struct {
    char name[20];
    int age;
} Person;

int main() {
    printf("[*] 파일 입출력 예제 코드\n");
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
    printf("\n");

    printf("[*] 파일 입출력 함수 - 파일 쓰기(fputc, fputs)\n");
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

    printf("\n");

    printf("[*] 파일 입출력 함수 - 파일 읽기(fgetc, fgets)\n");

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

    printf("\n");

    printf("[*] 바이너리 데이터의 입출력\n");
    Person people[3] = {
        {"Kim", 20},
        {"Dowon", 30},
        {"DoTTak", 40}
    };
    Person person_buffer[3];
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
    fread(person_buffer, sizeof(Person), 3, file);
    fclose(file);
    // 출력
    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d\n", person_buffer[i].name, person_buffer[i].age);
    }

    printf("\n");

    printf("[*] 텍스트와 바이너리 데이터의 동시 입출력\n");
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

    printf("\n");

    printf("[*] feof와 파일 위치 지시자\n");
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