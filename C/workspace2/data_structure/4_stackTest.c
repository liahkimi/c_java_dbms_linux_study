#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

typedef struct Stack{
	int ar[MAX];
	int top;//������� �ε����� ��ȣ�� �˰� �ִ� ����
}Stack;

void init(Stack* s) {
	s->top = -1; //��Ұ� �����Ƿ� ���� ������ -1�� �ȴ�.
}
//��� Ȯ�ο� �Լ�
void show(Stack* s) {
	if (s->top == -1) {
		printf("!!!������ ������ϴ�!!!\n\n");
	}
	else {
		for (int i = 0; i < s->top + 1; i++) {
			printf(" | [%d]", s->ar[i]);
		}
	}
}

// å �״� �� ó�� �Ʒ��� ���!
void show2(Stack* s) {
	if (s->top == -1) {
		printf("!!!!! ������ ������ϴ�! !!!!!\n\n");
	}
	else {
		for (int i = s->top; i >= 0; i--) {
			printf("[%d]\n", s->ar[i]);
		}
	}
}

//push() : ���ÿ� ��Ҹ� �߰��ϴ� �Լ�
void push(Stack* s, int element) {
	if (s->top == MAX -1) {
		printf("!!!!!!!!������ ���� á���ϴ�!!!!!!!\n\n");
		return;
	}
	s->ar[++s->top] = element;
}


// pop() : ���ÿ��� ��Ҹ� �������ִ� �Լ�. ������ ��Ҹ� return �Ѵ�. //�ǵڿ����� ����
int pop(Stack* s) {
	if (s->top == -1) {
		printf("!!!!! ������ ������ϴ�! !!!!!\n\n");
	}
	//int temp = s->ar[s->top];
	//s->top--;
	//return temp;
	return s->ar[s->top--];
}

// peek() : top�� ��ġ�� ��Ҹ� ������ �Լ�
int peek(Stack* s) {
	if (s->top == -1) {
		printf("!!!!! ������ ������ϴ�! !!!!!\n\n");
	}
	return s->ar[s->top];
}

//clear() : 

int main() {
	Stack s;
	init(&s);

	printf("===========push �׽�Ʈ=============\n");
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 40);
	push(&s, 50);
	show(&s);
	/*show2(&s);*/

	printf("\n========== pop �׽�Ʈ ==========\n");
	printf("pop �� �� : %d\n", pop(&s));
	printf("pop �� �� : %d\n", pop(&s));
	printf("pop �� �� : %d\n", pop(&s));
	show(&s);

	printf("\n========== peek �׽�Ʈ ==========\n");
	printf("peek �� �� : %d\n", peek(&s));
	show(&s);

	printf("\n========== peek �׽�Ʈ ==========\n");
	clear(&s);	
	show(&s);

	return 0;
}