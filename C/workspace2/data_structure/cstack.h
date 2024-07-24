#pragma once // 중복되는 요소를 한 번만 include 해주는 명령어
#include <stdio.h>
#define MAX 10

typedef struct Stack {
    int ar[MAX];
    int top; // 꼭데기의 인덱스 번호를 알고있는 변수
}Stack;

void init(Stack* s) {
    s->top = -1; // 요소가 없으므로 현재 꼭대기는 -1이 된다.
}

// push() : 스택에 요소를 추가하는 함수
void push(Stack* s, int element) {
    if (s->top == MAX - 1) return 0;
    s->ar[++s->top] = element;
    return 1;
}

// pop()
// 값을 리턴하는 게 아니라
// 매개변수로 받아온 주소에 해당 연산자를 저장하는 식으로 구현
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

// clear() : 스택에 있는 모든 요소를 삭제해주는 함수
void clear(Stack* s) {
    s->top = -1;
}

// 스택이 비어있는지 검사하는 함수
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 요소 확인용 함수
void show(Stack* s) {
    if (s->top == -1) {
        printf("!!!!! 스택이 비었습니다! !!!!!\n\n");
    }
    else {
        for (int i = 0; i < s->top + 1; i++) {
            printf(" | [%d]", s->ar[i]);
        }
    }
}