#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

typedef struct Stack{
	int ar[MAX];
	int top;//꼭대기의 인덱스의 번호를 알고 있는 변수
}Stack;

void init(Stack* s) {
	s->top = -1; //요소가 없으므로 현재 꼭대기는 -1이 된다.
}
//요소 확인용 함수
void show(Stack* s) {
	if (s->top == -1) {
		printf("!!!스택이 비었습니다!!!\n\n");
	}
	else {
		for (int i = 0; i < s->top + 1; i++) {
			printf(" | [%d]", s->ar[i]);
		}
	}
}

// 책 쌓는 거 처럼 아래로 출력!
void show2(Stack* s) {
	if (s->top == -1) {
		printf("!!!!! 스택이 비었습니다! !!!!!\n\n");
	}
	else {
		for (int i = s->top; i >= 0; i--) {
			printf("[%d]\n", s->ar[i]);
		}
	}
}

//push() : 스택에 요소를 추가하는 함수
void push(Stack* s, int element) {
	if (s->top == MAX -1) {
		printf("!!!!!!!!스택이 가득 찼습니다!!!!!!!\n\n");
		return;
	}
	s->ar[++s->top] = element;
}


// pop() : 스택에서 요소를 삭제해주는 함수. 삭제된 요소를 return 한다. //맨뒤에것을 삭제
int pop(Stack* s) {
	if (s->top == -1) {
		printf("!!!!! 스택이 비었습니다! !!!!!\n\n");
	}
	//int temp = s->ar[s->top];
	//s->top--;
	//return temp;
	return s->ar[s->top--];
}

// peek() : top에 위치한 요소를 엿보는 함수
int peek(Stack* s) {
	if (s->top == -1) {
		printf("!!!!! 스택이 비었습니다! !!!!!\n\n");
	}
	return s->ar[s->top];
}

//clear() : 

int main() {
	Stack s;
	init(&s);

	printf("===========push 테스트=============\n");
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 40);
	push(&s, 50);
	show(&s);
	/*show2(&s);*/

	printf("\n========== pop 테스트 ==========\n");
	printf("pop 된 값 : %d\n", pop(&s));
	printf("pop 된 값 : %d\n", pop(&s));
	printf("pop 된 값 : %d\n", pop(&s));
	show(&s);

	printf("\n========== peek 테스트 ==========\n");
	printf("peek 된 값 : %d\n", peek(&s));
	show(&s);

	printf("\n========== peek 테스트 ==========\n");
	clear(&s);	
	show(&s);

	return 0;
}