#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

typedef struct CircleQueue {
	int ar[MAX];
	int front; // dequeue() 시 큐에서 삭제할 인덱스
	int rear; // enqueue() 시 큐에 추가할 인덱스
	int length; // 큐 요소의 갯수를 저장할 변수
}Que;

// 초기화 함수
void init(Que* q) {
	q->front = 0;
	q->rear = 0;
	q->length = 0;
}

int isFull(Que* q) {
	return q->length == MAX;
}

int isEmpty(Que* q) {
	return q->length == 0;
}

void enqueue(Que* q, int element) {
	if (isFull(q)) {
		printf("현재 Que가 가득 찼습니다!\n\n");
	}
	else {
		q->ar[q->rear] = element;
		q->length++;
		q->rear = (q->rear + 1) % MAX;
	}
}

int dequeue(Que* q, int* res) {
	if (isEmpty(q)) {
		printf("현재 Que는 비어있습니다.\n\n");
		return 0;
	}
	else {
		*res = q->ar[q->front];
		q->length--;
		q->front = (q->front + 1) % MAX;
		return 1;
	}
}

void show(Que* q) {
	if (isEmpty(q)) {
		printf("현재 Que는 비어있습니다.\n\n");
	}
	else {
		int idx = q->front;
		printf("---------- front : %d,  rear : %d ----------\n", q->front, q->rear);
		for (int i = 0; i < q->length; i++) {
			printf("[%d] | ", q->ar[idx]);
			idx = (idx + 1) % MAX;
		}
		printf("\n------------------------------------------\n\n");
	}
}

int peek(Que* q, int* res) {
	if (isEmpty(q)) {
		printf("현재 Que는 비어있습니다.\n\n");
		return 0;
	}
	else {
		*res = q->ar[q->front];
		return 1;
	}
}

// clear()
void clear(Que* q) {
	q->length = 0;
	q->front = q->rear;
}

int main() {
	Que q;
	init(&q);
	int choice;
	int res;

	while (1) {
		printf("(1)enqueue  (2)dequeue  (3)peek  (4)clear  (5)show  (6)exit\n");
		printf("select menu >> ");
		scanf("%d", &choice);

		if (choice == 6) { // exit
			break;
		}

		switch (choice) {
		case 1: // enqueue
			printf("input num >> ");
			scanf("%d", &choice);
			enqueue(&q, choice);
			break;

		case 2: // dequeue
			if (dequeue(&q, &res)) {
				printf("check dequeue value : %d\n\n", res);
			}
			break;
		case 3: // peek
			if (peek(&q, &res)) {
				printf("check peek value : %d\n\n", res);
			}
			break;
		case 4: // clear
			clear(&q);
			printf("complete!\n\n");
			break;

		case 5: // show
			show(&q);
			break;

		default:
			printf("ERROR! check choice number\n\n");
			break;
		}
	}

	printf("\nQue 테스트를 종료합니다.");

	// 큐 테스트
	//Que q;
	//init(&q);
	//int temp;
	//enqueue(&q, 10);
	//enqueue(&q, 20);
	//enqueue(&q, 30);
	//enqueue(&q, 40);
	//enqueue(&q, 50);
	//enqueue(&q, 60);
	//enqueue(&q, 70);
	//enqueue(&q, 80);
	//enqueue(&q, 90);
	//enqueue(&q, 100);
	//show(&q);

	//dequeue(&q, &temp);
	//printf("dequeue된 값 : %d\n", temp);
	//show(&q);

	//peek(&q, &temp);
	//printf("peek 된 값 : %d\n", temp);
	//show(&q);

	//clear(&q);
	//dequeue(&q, &temp);
	//peek(&q, &temp);
	//show(&q);


	return 0;
}