#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char name[30];
    int score;
}Stu;

int main() {
    int* ptr = (int*)malloc(sizeof(int));

    printf("�����Ҵ�� ��ġ : %d\n", ptr);
    printf("ptr ��ġ : %d\n", &ptr);

    printf("�����Ҵ�� ���� �ȿ� ����ִ� �� : %d\n", *ptr);
    *ptr = 49;
    printf("�����Ҵ�� ���� �ȿ� ����ִ� �� : %d\n", *ptr);

    free(ptr); // �����Ҵ�� �ּҸ� ������Ų��.

    // ������ ���Ŀ��� ������� �ʴ´�.
    //*ptr = 555.45;
    //printf("�����Ҵ�� ���� �ȿ� ����ִ� �� : %lf\n", *ptr);

    // calloc(����, ũ��) : �������� �Ҵ�����ָ鼭 ���ÿ� �ʱ�ȭ���� �����Ѵ�.
    ptr = (int*)calloc(1, sizeof(int));
    printf("*ptr : %d\n", *ptr);

    free(ptr);

    // ����ü�� �����Ҵ�
    Stu* sPtr = (Stu*)malloc(sizeof(Stu));
    // �������� �Ҵ���� ������ ��������� �� �����ϱ�
    sPtr->score = 100;
    printf("%d\n", sPtr->score);

    free(sPtr);

    // int Ÿ���� ��Ұ� 5�� ����ִ� �迭
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