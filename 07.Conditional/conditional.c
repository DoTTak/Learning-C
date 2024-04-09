#include <stdio.h>

int main() {
    int num;

    printf("숫자를 입력하세요: ");
    scanf("%d", &num);

    // if 문
    printf("[*] if문\n");
    printf("    if(num > 5){...}\n");
    if (num > 5) {
        printf(">> 입력하신 숫자는 5보다 큽니다\n");
    }

    printf("\n");

    // if-else 문
    printf("[*] if~else문\n");
    printf("    if(num > 15){...}\n");
    printf("    else{...}\n");
    if (num > 15) {
        printf(">> 입력하신 숫자는 15보다 큽니다\n");
    } else {
        printf(">> 입력하신 숫자는 15보다 크지 않습니다\n");
    }

    printf("\n");

    // if-else if-else 문
    printf("[*] if~else문\n");
    printf("    if(num > 20){...}\n");
    printf("    else if(num > 10){...}\n");
    printf("    else{...}\n");
    if (num > 20) {
        printf(">> 입력하신 숫자는 20보다 큽니다\n");
    } else if (num > 10) {
        printf(">> 입력하신 숫자는 10보다 크지만 20보다 크지는 않습니다\n");
    } else {
        printf(">> 입력하신 숫자는 10보다 크지 않습니다\n");
    }

    printf("\n");

    // 3항 연산자
    printf("[*] 3항 연산자\n");
    printf("    (num > 5) ? ... : ...\n");
    char *str = (num > 5) ? ">> 입력하신 숫자는 5보다 큽니다" : ">> 입력하신 숫자는 5보다 크지 않습니다";
    printf("%s\n", str);

    printf("\n");
    // switch 문
    printf("[*] switch문\n");
    printf("    switch (num)\n");
    printf("        case 5: ... break;\n");
    printf("        case 10: ... break;\n");
    printf("        default: ... break;\n");
    switch (num) {
        case 5:
            printf(">> 입력하신 숫자는 5입니다\n");
            break;
        case 10:
            printf(">> 입력하신 숫자는 10입니다\n");
            break;
        default:
            printf(">> 입력하신 숫자는 5도 10도 아닙니다\n");
            break;
    }

    printf("\n");

    // goto 문
    printf("[*] goto\n");
    printf("    goto skip;\n");
    printf("  skip:\n");
    printf("        ...\n");
    goto skip;
    printf("이 줄은 건너뜁니다\n");
skip:
    printf(">> 여기로 건너뛰었습니다\n");

    return 0;
}
