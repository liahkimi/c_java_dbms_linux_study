#pragma once // �ߺ��Ǵ� ��Ҹ� �� ���� include ���ִ� ��ɾ�
#include <stdio.h>
#define MAX 10

typedef struct Stack {
    int ar[MAX];
    int top; // �������� �ε��� ��ȣ�� �˰��ִ� ����
}Stack;

void init(Stack* s) {
    s->top = -1; // ��Ұ� �����Ƿ� ���� ������ -1�� �ȴ�.
}

// push() : ���ÿ� ��Ҹ� �߰��ϴ� �Լ�
void push(Stack* s, int element) {
    if (s->top == MAX - 1) return 0;
    s->ar[++s->top] = element;
    return 1;
}

// pop()
// ���� �����ϴ� �� �ƴ϶�
// �Ű������� �޾ƿ� �ּҿ� �ش� �����ڸ� �����ϴ� ������ ����
int pop(Stack* s, char* res) {
    if (s->top == -1) return 0;
    *res = s->ar[s->top--];
    return 1;
}

// peek()
int peek(Stack* s, char* res) {
    if (s->top == -1) return 0;
    *res = s->ar[s->top];
    return 1;
}

// clear() : ���ÿ� �ִ� ��� ��Ҹ� �������ִ� �Լ�
void clear(Stack* s) {
    s->top = -1;
}

// ������ ����ִ��� �˻��ϴ� �Լ�
int isEmpty(Stack* s) {
    return s->top == -1;
}

// ��� Ȯ�ο� �Լ�
void show(Stack* s) {
    if (s->top == -1) {
        printf("!!!!! ������ ������ϴ�! !!!!!\n\n");
    }
    else {
        for (int i = 0; i < s->top + 1; i++) {
            printf(" | [%d]", s->ar[i]);
        }
    }
}