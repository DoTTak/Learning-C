#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{   
    printf("[*] 문자 단위 입출력 함수 \n");
    // 문자 출력
    printf("문자 출력\n");
    printf("putchar(): ");
    putchar('A'); putchar('\n');
    printf("fputc(): ");
    fputc('A', stdout); putchar('\n');
    // 문자 입력
    char ch1;
    printf("문자 입력(getchar): ");
    ch1 = getchar();
    printf("입력한 문자 %c\n", ch1); getchar(); // 버퍼에 있는 개행을 제거하기 위한 용도
    printf("문자 입력(fgetc): ");
    ch1 = fgetc(stdin);
    printf("입력한 문자 %c\n", ch1); getchar(); // 버퍼에 있는 개행을 제거하기 위한 용도
    
    printf("\n");

    printf("[*] 문자열 단위 입출력 함수 \n");
    // 문자열 출력
    printf("문자열 출력\n");
    printf("puts(): ");
    puts("Hello");
    printf("fputs(): ");
    fputs("Hello\n", stdout);
    // 문자열 입력
    char str[7];
	printf("문자열 입력(gets): ");
	gets(str);
	printf("입력된 문자열: %s \n", str);
	printf("문자열 입력(fgets): ");
	fgets(str, sizeof(str), stdin);
	printf("입력된 문자열: %s \n", str);
    while(getchar() != '\n'); // 입력 버퍼 비우기

    printf("\n");
    printf("[*] 입력 버퍼 비우기 \n");
    char str1[6]; // 'Hello', 'World' 모두 5자 이지만, NULL 문자를 고려하여 6으로 계산
	char str2[6];
	fgets(str1, sizeof(str1), stdin);
    printf("while(getchar() != '\\n');\n");
    while(getchar() != '\n'); // 입력 버퍼 비우기
	fgets(str2, sizeof(str2), stdin);
	printf("%s\n", str1);
	printf("%s\n", str2);

    printf("\n");
    printf("[*] 문자열 관련 함수 \n");
    printf("1) 문자열 길이 반환하는 함수: strlen\n");
    char str3[] = "Hello, world!";
    printf("문자열: %s\n", str3);
    printf("strlen: %lu\n", strlen(str3));

    printf("2) 문자열을 복사하는 함수: strcpy, strncpy\n");
    char dest[20];
    strcpy(dest, str3);
    printf("strcpy 복사 결과: %s\n", dest);

    char dest2[10];
    strncpy(dest2, str3, 5);  // 첫 5개 문자만 복사
    dest2[5] = '\0';  // 문자열 끝을 표시
    printf("strncpy 복사 결과: %s\n", dest2);

    printf("3) 문자열을 덧붙이는 함수: strcat, strncat\n");
    char dest3[30] = "Hello, ";
    char src[] = "world!";
    printf("원래 문자열: %s\n", dest3);
    strcat(dest3, src);
    printf("strcat 덧붙이기 결과: %s\n", dest3);

    char dest4[30] = "Hello, ";
    strncat(dest4, src, 3);  // src의 처음 3개 문자만 덧붙이기
    printf("strncat 덧붙이기 결과: %s\n", dest4);

    printf("4) 문자열을 비교하는 함수: strcmp, strncmp\n");
    char str4[] = "abc";
    char str5[] = "abcd";
    printf("str4: %s, str5: %s\n", str4, str5);
    printf("strcmp 결과: %d\n", strcmp(str4, str5));
    printf("strncmp 결과 (처음 3개 문자 비교): %d\n", strncmp(str4, str5, 3));

    printf("5) 그 외의 변환하는 함수들: atoi, atol, atof\n");
    char numStr[] = "12345";
    printf("문자열 숫자: %s\n", numStr);
    int numInt = atoi(numStr);
    long numLong = atol(numStr);
    double numDouble = atof(numStr);
    printf("atoi 결과 (int): %d\n", numInt);
    printf("atol 결과 (long): %ld\n", numLong);
    printf("atof 결과 (double): %f\n", numDouble);

    return 0;
}
