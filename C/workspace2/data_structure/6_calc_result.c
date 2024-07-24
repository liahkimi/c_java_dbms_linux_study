#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cstack.h"

//우선순위 함수
int prec(char op) {
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


// 가능 에러 검사
int findError(char exp[]) {
    int errCode = 0;
    int length = strlen(exp);

    // 0으로 나눌때 오류
    for (int i = 0; i < length; i++) {
        if (i + 1 < length && exp[i] == '/' && exp[i + 1] == '0') {
            errCode = 2000;
            printf("%d err 발생\n", errCode);
            printf(">>>0으로 나눗셈 불가능\n\n");
            return errCode;
        }
    }

    // 두자릿수 이상 숫자 입력시 오류
    int cnt_len = 0;
    int max_len = 0;
    for (int i = 0; i < length; i++) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            cnt_len++;
            if (cnt_len >= max_len) {
                max_len = cnt_len;
            }
        }
        else {
            cnt_len = 0;
        }
    }
    if (max_len >= 2) {
        errCode = 3000;
        printf("%d err 발생\n", errCode);
        printf(">>>두자릿수 이상 숫자 계산 불가능\n\n");
        return errCode;
    }

    // 숫자와 수식을 제외한 문자 입력시 오류
    for (int i = 0; i < length; i++) {
        if (exp[i] == '(' || exp[i] == ')' || exp[i] == '-' || exp[i] == '+' || exp[i] == '/' || exp[i] == '*') {
            continue;
        }
        else if (exp[i] >= '0' && exp[i] <= '9') {
            continue;
        }
        else {
            errCode = 4000;
            printf("%d err 발생\n", errCode);
            printf(">>>계산 불가능 문자 포함됨\n\n");
            return errCode;
        }
    }

    // 괄호가 짝이 맞지 않다면 오류
    int cnt = 0;
    for (int i = 0; i < length; i++) {
        if (exp[i] == '(') {
            cnt++;
        }
        else if (exp[i] == ')') {
            cnt--;
        }
        if (cnt < 0) {
            errCode = 5001;
            printf("%d err 발생\n", errCode);
            printf(">>>닫는 소괄호 먼저 입력됨\n\n");
            return errCode;
        }
    }
    if (cnt != 0) {
        errCode = 5002;
        printf("%d err 발생\n", errCode);
        printf(">>>괄호 짝이 맞지 않음\n\n");
        return errCode;
    }

    return errCode;
}

// 수식 변환 함수
char* inToPost(char exp[]) {

    if (findError(exp) != 0) {
        return NULL;
    }

    char top;
    char ch;
    char* res = (char*)malloc(sizeof(char) * 100);
    int idx = 0;
    int length = strlen(exp);
    Stack s;
    init(&s);
    for (int i = 0; i < length; i++) {
        ch = exp[i];
        // 1. 숫자라면 바로 res에 담아준다
        if (ch >= '0' && ch <= '9') {
            res[idx++] = ch;
        }
        // 2. 만약 연산자라면
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            peek(&s, &top);
            // 2-2. 본인이 스택에 있는 연산자보다 우선순위가 낮거나 같고, 혹은 스택이 비어있지 않다면
            while (!isEmpty(&s) && prec(ch) <= prec(top)) {
                pop(&s, &top);
                // 본인보다 높거나 같은 연산자를 모두 pop()하여 res에 담아준다
                res[idx++] = top;
                peek(&s, &top);
            }
            // 그리고 본인은 push()한다.    // 2-1비어있거나 본인이 우선순위가 더 높다면 push()한다
            push(&s, ch);
        }
        else if (ch == '(') {
            // 3-1. 만약 ( 라면 무조건 push()
            push(&s, ch);
        }
        else if (ch == ')') {
            // 3-2. 만약 ) 라면 
            pop(&s, &top);
            // top이 (이 될때까지
            while (top != '(') {
                // 맨 위의 요소를 뽑아 res에 담아준다
                res[idx++] = top;
                pop(&s, &top);
            }
        }
    }
    // 4. 순회를 끝났는데도 스택이 비어있지 않다면
    while (!isEmpty(&s)) {
        // 모든 요소를 뽑아
        pop(&s, &top);
        // res에 담아준다
        res[idx++] = top;
    }
    // 문자열임을 알려주기위해(%s 사용 위해) 널문자를 마지막에 추가해준다.
    res[idx] = '\0';
    return res;
}

int calc(char exp[]) {
    int length = strlen(exp);
    Stack s;
    init(&s);
    char last;

    for (int i = 0; i < length; i++) {
        char ch = exp[i];
        if (ch >= '0' && ch <= '9') {
            push(&s, ch);
        }
        else {
            char num1;
            char num2;
            char res;
            pop(&s, &num2);
            pop(&s, &num1);
            num1 -= '0';
            num2 -= '0';
            switch (ch) {
            case '-':
                res = num1 - num2;
                break;
            case '+':
                res = num1 + num2;
                break;
            case '*':
                res = num1 * num2;
                break;
            case '/':
                res = num1 / num2;
                break;
            }
            res += '0';
            push(&s, res);

        }
    }

    pop(&s, &last);
    return last - '0';
}


void main() {
    char exp[100];
    printf("계산식 입력 : ");
    scanf("%s", exp);

    printf("오류 코드 : %d\n", findError(exp));
    printf("변환 결과 : %s\n", inToPost(exp));
    printf("계산 결과 : %d\n", calc(inToPost(exp)));
    //계산식 입력 : 5+7*2/2+9-3
    //오류 코드 : 0
    //변환 결과 : 572 * 2 / +9 + 3 -
    //계산 결과 : 18
}