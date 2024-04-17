#include <stdio.h>

// #define을 사용한 Object-like macro
#define PI 3.14159

// #define을 사용한 Function-like macro
#define SQUARE(X) ((X)*(X))

// #if... #endif를 사용한 조건부 컴파일
#define DEBUG  // 주석 처리하면 디버깅 정보가 출력되지 않음

int main() {
    int radius = 5;
    int num = 20;

    // Object-like macro 사용 예제
    printf("PI: %.5f\n", PI);

    // Function-like macro 사용 예제
    printf("Square of %d: %d\n", num, SQUARE(num)); // num의 제곱 출력
    printf("Square of %d: %d\n", -5, SQUARE(-5));    // -5의 제곱 출력

    // 문제가 있는 Function-like macro 사용 예제
    printf("Square of %d: %d\n", 3 + 2, SQUARE(3 + 2)); // 실제로는 (3 + 2) * (3 + 2) = 11이 출력될 수 있음

#ifdef DEBUG
    printf("Debugging information\n"); // DEBUG 매크로가 정의되어 있을 때만 실행
#endif

    return 0;
}
