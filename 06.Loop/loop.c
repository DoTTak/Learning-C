#include <stdio.h>

int main(void)
{
    int while_num=3;
    int do_while_num=3;
    int for_num=3;

    while(while_num){
        printf("while문 동작: %d\n", while_num);
        while_num--;
    }
    
    printf("\n");
    
    do{
        printf("do~while문 동작: %d\n", do_while_num);
        do_while_num--;
    } while(do_while_num);

    printf("\n");

    for(int i=0;i<for_num;i++){
        printf("for문 동작: %d\n", i);
    }

    printf("\n");
    printf("[*] continue문 예제(홀수출력)\n");
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        printf("%d ", i);
    }

    printf("\n");
    printf("[*] break문 예제(i를 10회 반복할 때, i가 5회 때 종료)\n");
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break;
        }
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}