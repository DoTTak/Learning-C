#include "my_header.h"

// 함수 정의
void greet(const char *name) {
    printf("Hello, %s!\n", name);
}

// 구조체를 초기화하는 함수 정의
void initializePoint(Point *p, int x, int y) {
    p->x = x;
    p->y = y;
}

// 구조체를 이동시키는 함수 정의
void movePoint(Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

// 외부 변수 정의
int globalCounter = 0;