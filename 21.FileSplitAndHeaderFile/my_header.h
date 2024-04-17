#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <stdio.h>

// 함수 선언
void greet(const char *name);

// 구조체 선언
typedef struct {
    int x;
    int y;
} Point;

// 구조체 관련 함수 선언
void initializePoint(Point *p, int x, int y);
void movePoint(Point *p, int dx, int dy);


// 외부 변수 선언
extern int globalCounter;

#endif  // MY_HEADER_H