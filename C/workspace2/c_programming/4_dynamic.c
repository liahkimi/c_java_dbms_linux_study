#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char name[30];
    int score;
}Stu;

int main() {
    int* ptr = (int*)malloc(sizeof(int));

    printf("동적할당된 위치 : %d\n", ptr);
    printf("ptr 위치 : %d\n", &ptr);

    printf("동적할당된 공간 안에 들어있는 값 : %d\n", *ptr);
    *ptr = 49;
    printf("동적할당된 공간 안에 들어있는 값 : %d\n", *ptr);

    free(ptr); // 동적할당된 주소를 해제시킨다.

    // 해제된 이후에는 사용하지 않는다.
    //*ptr = 555.45;
    //printf("동적할당된 공간 안에 들어있는 값 : %lf\n", *ptr);

    // calloc(갯수, 크기) : 동적으로 할당시켜주면서 동시에 초기화까지 진행한다.
    ptr = (int*)calloc(1, sizeof(int));
    printf("*ptr : %d\n", *ptr);

    free(ptr);

    // 구조체의 동적할당
    Stu* sPtr = (Stu*)malloc(sizeof(Stu));
    // 동적으로 할당받은 공간의 멤버변수에 값 대입하기
    sPtr->score = 100;
    printf("%d\n", sPtr->score);

    free(sPtr);

    // int 타입의 요소가 5개 들어있는 배열
    int* ar = (int*)malloc(sizeof(int) * 5);

    ar[0] = 10;

    for (int i = 0; i < 5; i++) {
        printf("ar[%d] : %d\n", i, ar[i]);
    }

    int* ar2 = (int*)calloc(5, sizeof(int));

    for (int i = 0; i < 5; i++) {
        printf("ar2[%d] : %d\n", i, ar2[i]);
    }

    free(ar);
    free(ar2);

    return 0;
}