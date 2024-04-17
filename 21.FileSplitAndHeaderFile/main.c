#include "my_header.h"

int main() {
    greet("Dowon");
    greet("DoTTak");

    // 구조체 선언 및 초기화
    Point p1;
    initializePoint(&p1, 10, 20);

    // 구조체 정보 출력
    printf("Initial Point: (%d, %d)\n", p1.x, p1.y);

    // 구조체 이동
    movePoint(&p1, 5, -5);

    // 이동 후 정보 출력
    printf("Moved Point: (%d, %d)\n", p1.x, p1.y);


    // 외부 변수 사용
    printf("Global Counter: %d\n", globalCounter);
    globalCounter++;
    printf("Global Counter: %d\n", globalCounter);

    return 0;
}