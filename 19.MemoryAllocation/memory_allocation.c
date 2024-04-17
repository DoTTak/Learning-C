#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(void) {
    char *str = NULL;
    char buffer[100]; // 임시 버퍼
    size_t length = 0;
    
    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);
    length = strlen(buffer); // 입력받은 문자열의 길이 계산
    
    // 개행 문자 제거
    if (buffer[length - 1] == '\n')
        buffer[length - 1] = '\0';
    else
        while (getchar() != '\n'); // 입력 버퍼 비우기
    
    // 동적 메모리 할당 (malloc 사용)
    str = (char *)malloc(length + 1); // 문자열 길이 + 널 문자 공간 할당
    if (str == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // // 동적 메모리 할당 (calloc 사용)
    // str = (char *)calloc(length + 1, sizeof(char)); // 문자열 길이 + 널 문자 공간 할당
    // if (str == NULL) {
    //     printf("Memory allocation failed\n");
    //     exit(1);
    // }
    
    // 입력받은 문자열 복사
    strcpy(str, buffer);
    
    return str;
}

int main(void) {
    char *str1 = NULL;
    char *str2 = NULL;
    
    // 첫 번째 문자열 입력 받기
    str1 = inputString();
    printf("First string: %s\n", str1);
    
    // 두 번째 문자열 입력 받기 (realloc 사용)
    printf("Enter another string: ");
    str2 = inputString();
    printf("Second string: %s\n", str2);
    
    // 첫 번째 문자열 재할당 (realloc 사용)
    printf("Enter a new string for the first string: ");
    str1 = (char *)realloc(str1, 100 * sizeof(char)); // 새로운 크기로 재할당
    if (str1 == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
    fgets(str1, 100, stdin); // 새로운 문자열 입력 받기
    
    printf("Updated first string: %s\n", str1);
    
    // 메모리 해제
    free(str1);
    free(str2);
    
    return 0;
}
