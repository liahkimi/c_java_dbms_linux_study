#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����� ���� ������� �߰� ���
# include "cstack.h"

// �������� �켱 ������ �˷��ִ� �Լ�
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

// ���� ǥ������ ����ǥ�������� �ٲ��ִ� �Լ�
char* inToPost(char exp[]) {
    // res : ����ǥ�������� �ٲ� ����� ������ �迭
    char* res = (char*)malloc(sizeof(char) * 100);
    int idx = 0; // rres�� �ε��� ��ȣ
    char op; // ������ top�� ����ִ� ��Ҹ� ����� ����
    Stack s; // �����ڸ� ����� ����
    init(&s);

    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i]; // ch : ����ǥ���Ŀ��� �ϳ��� �������� ����.
        if (ch >= '0' && ch <= '9') {
            res[idx++] = ch;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') { // �����ڶ��
            peek(&s, &op); // �������ؼ� ���� ���� �����ڸ� Ȯ��!
            // ������ ������� �ʰ�
            // ���� �ְ��� �ϴ� �����ڰ� ���ÿ� �����ϴ� �����ں���
            // �켱 ������ ���ų� ���ٸ�
            while (!isEmpty(&s) && checkOper(ch) <= checkOper(op)) {
                pop(&s, &op); // ���ÿ� �ִ� �����ڸ� ������
                res[idx++] = op; // res�� ����ְ�
                peek(&s, &op); // �����Ÿ� ���� ������ op�� ����!
                // ���� while�� ����!
            }
            // ������ ����ų�, ������ �켱������ ���� ģ���� �����ְų�
            push(&s, ch);
        }
        else {
            printf("���� �߻�! ���α׷��� �����մϴ�.");
            return;
        }
    }
    // for�� Ż�� ��, �����ڸ� ��Ƴ��� ���ÿ�
    // ���� ó������ ���� �����ڵ��� �����ִ�.
    // �������� ������ res �ڷ� �ٿ�����.
    while (!isEmpty(&s)) {
        pop(&s, &op);
        res[idx++] = op;
    }
    // �ι��ڸ� �־��༭ ����ϱ� ���ϵ��� ������.
    res[idx] = '\0';
    return res;
}

int main() {

    char exp[100];
    char* res;

    printf("���� ǥ�������� �ٲٰ� ���� ���� : ");
    scanf("%s", exp);
    res = inToPost(exp);
    printf("����ǥ�������� �ٲ� �� : %s\n", res);



    // ������� �׽�Ʈ
    //Stack s;
    //init(&s);
    //push(&s, 10);
    //push(&s, 20);
    //push(&s, 30);
    //push(&s, 40);
    //show(&s);
}