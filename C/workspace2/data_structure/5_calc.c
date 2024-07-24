#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 사용자 정의 헤더파일 추가 방법
# include "cstack.h"

// 연산자의 우선 순위를 알려주는 함수
int checkOper(char op) {
    switch (op) {
    case '+':
    case '-':
        return 0;
    case '*':
    case '/':
        return 1;
    }
    return -1;
}

// 중위 표현식을 후위표현식으로 바꿔주는 함수
char* inToPost(char exp[]) {
    // res : 후위표현식으로 바꾼 결과를 저장할 배열
    char* res = (char*)malloc(sizeof(char) * 100);
    int idx = 0; // rres의 인덱스 번호
    char op; // 스택의 top에 들어있는 요소를 담아줄 변수
    Stack s; // 연산자를 담아줄 스택
    init(&s);

    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i]; // ch : 중위표현식에서 하나씩 꺼내오는 문자.
        if (ch >= '0' && ch <= '9') {
            res[idx++] = ch;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') { // 연산자라면
            peek(&s, &op); // 엿보기해서 제일 위에 연산자를 확인!
            // 스택이 비어있지 않고
            // 지금 넣고자 하는 연산자가 스택에 존재하는 연산자보다
            // 우선 순위가 높거나 같다면
            while (!isEmpty(&s) && checkOper(ch) <= checkOper(op)) {
                pop(&s, &op); // 스택에 있는 연산자를 꺼내서
                res[idx++] = op; // res에 담아주고
                peek(&s, &op); // 다음거를 엿본 다음에 op에 저장!
                // 다음 while문 실행!
            }
            // 스택이 비었거나, 나보다 우선순위가 낮은 친구가 남아있거나
            push(&s, ch);
        }
        else {
            printf("오류 발생! 프로그램을 종료합니다.");
            return;
        }
    }
    // for문 탈출 후, 연산자를 담아놓은 스택에
    // 아직 처리하지 못한 연산자들이 남아있다.
    // 차례차례 꺼내서 res 뒤로 붙여주자.
    while (!isEmpty(&s)) {
        pop(&s, &op);
        res[idx++] = op;
    }
    // 널문자를 넣어줘서 사용하기 편하도록 만들자.
    res[idx] = '\0';
    return res;
}

int main() {

    char exp[100];
    char* res;

    printf("후위 표현식으로 바꾸고 싶은 수식 : ");
    scanf("%s", exp);
    res = inToPost(exp);
    printf("후위표현식으로 바뀐 식 : %s\n", res);



    // 헤더파일 테스트
    //Stack s;
    //init(&s);
    //push(&s, 10);
    //push(&s, 20);
    //push(&s, 30);
    //push(&s, 40);
    //show(&s);
}