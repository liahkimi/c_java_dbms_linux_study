#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cstack.h"

//�켱���� �Լ�
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


// ���� ���� �˻�
int findError(char exp[]) {
    int errCode = 0;
    int length = strlen(exp);

    // 0���� ������ ����
    for (int i = 0; i < length; i++) {
        if (i + 1 < length && exp[i] == '/' && exp[i + 1] == '0') {
            errCode = 2000;
            printf("%d err �߻�\n", errCode);
            printf(">>>0���� ������ �Ұ���\n\n");
            return errCode;
        }
    }

    // ���ڸ��� �̻� ���� �Է½� ����
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
        printf("%d err �߻�\n", errCode);
        printf(">>>���ڸ��� �̻� ���� ��� �Ұ���\n\n");
        return errCode;
    }

    // ���ڿ� ������ ������ ���� �Է½� ����
    for (int i = 0; i < length; i++) {
        if (exp[i] == '(' || exp[i] == ')' || exp[i] == '-' || exp[i] == '+' || exp[i] == '/' || exp[i] == '*') {
            continue;
        }
        else if (exp[i] >= '0' && exp[i] <= '9') {
            continue;
        }
        else {
            errCode = 4000;
            printf("%d err �߻�\n", errCode);
            printf(">>>��� �Ұ��� ���� ���Ե�\n\n");
            return errCode;
        }
    }

    // ��ȣ�� ¦�� ���� �ʴٸ� ����
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
            printf("%d err �߻�\n", errCode);
            printf(">>>�ݴ� �Ұ�ȣ ���� �Էµ�\n\n");
            return errCode;
        }
    }
    if (cnt != 0) {
        errCode = 5002;
        printf("%d err �߻�\n", errCode);
        printf(">>>��ȣ ¦�� ���� ����\n\n");
        return errCode;
    }

    return errCode;
}

// ���� ��ȯ �Լ�
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
        // 1. ���ڶ�� �ٷ� res�� ����ش�
        if (ch >= '0' && ch <= '9') {
            res[idx++] = ch;
        }
        // 2. ���� �����ڶ��
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            peek(&s, &top);
            // 2-2. ������ ���ÿ� �ִ� �����ں��� �켱������ ���ų� ����, Ȥ�� ������ ������� �ʴٸ�
            while (!isEmpty(&s) && prec(ch) <= prec(top)) {
                pop(&s, &top);
                // ���κ��� ���ų� ���� �����ڸ� ��� pop()�Ͽ� res�� ����ش�
                res[idx++] = top;
                peek(&s, &top);
            }
            // �׸��� ������ push()�Ѵ�.    // 2-1����ְų� ������ �켱������ �� ���ٸ� push()�Ѵ�
            push(&s, ch);
        }
        else if (ch == '(') {
            // 3-1. ���� ( ��� ������ push()
            push(&s, ch);
        }
        else if (ch == ')') {
            // 3-2. ���� ) ��� 
            pop(&s, &top);
            // top�� (�� �ɶ�����
            while (top != '(') {
                // �� ���� ��Ҹ� �̾� res�� ����ش�
                res[idx++] = top;
                pop(&s, &top);
            }
        }
    }
    // 4. ��ȸ�� �����µ��� ������ ������� �ʴٸ�
    while (!isEmpty(&s)) {
        // ��� ��Ҹ� �̾�
        pop(&s, &top);
        // res�� ����ش�
        res[idx++] = top;
    }
    // ���ڿ����� �˷��ֱ�����(%s ��� ����) �ι��ڸ� �������� �߰����ش�.
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
    printf("���� �Է� : ");
    scanf("%s", exp);

    printf("���� �ڵ� : %d\n", findError(exp));
    printf("��ȯ ��� : %s\n", inToPost(exp));
    printf("��� ��� : %d\n", calc(inToPost(exp)));
    //���� �Է� : 5+7*2/2+9-3
    //���� �ڵ� : 0
    //��ȯ ��� : 572 * 2 / +9 + 3 -
    //��� ��� : 18
}