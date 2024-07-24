#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; // 실질적인 리스트의 요소가 저장될 공간
	struct Node* link; // 아직 typedef Node 가 정의되지 않았기에 별명 사용 X
}Node;

typedef struct LinkedList {
	Node* head; // 링크드리스트의 제일 처음 주소
}List;

// 초기화 함수
void init(List* list) {
	list->head = NULL;
};

// 요소 확인용 함수
void show(List* list) {
	Node* curr = list->head;
	while (curr != NULL) {
		printf("[%d] -> ", curr->data);
		curr = curr->link;
	}
	printf("\n");
}

// 리스트 요소의 갯수를 알려주는 함수
int len(List* list) {
	if (list->head == NULL) {
		return 0;
	}
	Node* curr = list->head;
	int length = 0;
	while (curr != NULL) {
		length++;
		curr = curr->link;
	}
	return length;
}

// 추가
// 맨 앞에 추가하기
void insertFirst(List* list, int element) {
	// 동적할당한 이유
	// 새롭게 추가할 노드는 이 함수 호출이 끝나더라도 메모리에 남아있어야한다.
	// 따라서 동적할당을 해준다.
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->link = list->head;
	list->head = newNode;
}

// 맨 뒤에 추가하기
void append(List* list, int element) {
	// 리스트에 요소가 하나도 없다면
	if (list->head == NULL) {
		insertFirst(list, element); // 맨 처음에 요소를 추가,
		return; // 함수 종료.
	}

	Node* curr = list->head;
	while (curr->link != NULL) {
		curr = curr->link;
	}
	// 반복문을 다 돌고 나면 curr에는 마지막 노드가 담겨있다.
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->link = NULL;
	curr->link = newNode;
}

// 데이터 중간에 추가하기
// 인덱스 번호를 활용하여 추가하기
void insert(List* list, int idx, int element) {
	// 인덱스 번호 음수, 길이보다 클 때
	int length = len(list);
	if (idx < 0 || idx > length) {
		printf("인덱스 오류\n");
	}
	else if (idx == 0) { // idx 에 0 이 들어왔다면.
		insertFirst(list, element);
	}
	else if (idx == length) { // 제일 뒤에 추가하면 됨
		append(list, element);
	}
	else { // 찐으로 삽입
		Node* curr = list->head;
		for (int i = 0; i < idx - 1; i++) {
			curr = curr->link;
		}

		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = element;
		newNode->link = curr->link;
		curr->link = newNode;
	}
}

// 삭제
// 맨 앞에 요소 삭제
void removeFirst(List* list) {
	// 리스트가 비어있다면
	if (list->head == NULL) {
		printf("데이터가 아무것도 없습니다.\n");
		return;
	}
	Node* removeNode = list->head;
	list->head = removeNode->link;
	free(removeNode);
}

// 맨 뒤 요소 삭제
void removeLast(List* list) {
	// 리스트가 비어있다면
	if (list->head == NULL) {
		printf("데이터가 아무것도 없습니다.\n");
	}
	else if (len(list) == 1) {
		removeFirst(list);
	}
	// 리스트 요소가 한 개 들어있는 경우
	// curr->link 가 NULL이기 때문에
	// curr->link->link는 사실상 NULL->link를 써버리는 것과 같게 된다.
	// 따라서 오류가 발생한다.

	else { // 찐으로 제일 뒤에 삭제
		Node* curr = list->head;
		while (curr->link->link != NULL) {
			curr = curr->link;
		}
		// 반복문 종료시, 삭제하고픈 노드의 전 노드가 curr
		free(curr->link);
		curr->link = NULL;
	}
}

// 인덱스 번호로 삭제하기
void removeByIdx(List* list, int idx) {
	// 인덱스 번호 음수, 길이보다 클 때
	int length = len(list);
	if (idx < 0 || idx > length) {
		printf("인덱스 오류\n");
	}
	else if (idx == 0) { // idx 에 0 이 들어왔다면.
		removeFirst(list);
	}
	else {
		Node* curr = list->head;
		for (int i = 0; i < idx - 1; i++) {
			curr = curr->link;
		}

		Node* removeNode = curr->link;
		curr->link = removeNode->link;
		free(removeNode);
	}
}

// 수정
// 인덱스 번호로 요소 수정하기
void updateByIdx(List* list, int idx, int element) {
	int length = len(list);
	if (idx < 0 || idx >= length) {
		printf("인덱스 오류\n");
	}
	else {
		Node* curr = list->head;
		for (int i = 0; i < idx; i++) {
			curr = curr->link;
		}
		curr->data = element;
	}
}

// 검색
// 해당 인덱스 번호의 데이터를 리턴하는 게 아니라
// 매개변수로 넘어온 주소에 데이터를 대입해준다.
int select(List* list, int idx, int* res) {
	// 인덱스 번호가 음수이거나 길이보다 클 경우
	if (idx < 0 || idx >= len(list)) {
		return 0;
	}

	Node* curr = list->head;
	for (int i = 0; i < idx; i++) {
		curr = curr->link;
	}
	*res = curr->data;
	return 1;
}

int main() {
	List list;
	init(&list);

	printf("---------- 맨 앞 요소 추가 테스트 ----------\n");
	insertFirst(&list, 10);
	insertFirst(&list, 20);
	insertFirst(&list, 30);
	show(&list);

	printf("\n---------- 맨 뒤 요소 추가 테스트 ----------\n");
	append(&list, 40);
	append(&list, 50);
	append(&list, 60);
	show(&list);

	printf("\n---------- 요소 삽입 테스트 ----------\n");
	insert(&list, 4, 111);
	show(&list);
	insert(&list, 2, 222);
	show(&list);
	insert(&list, 0, 777);
	show(&list);
	insert(&list, 9, 486);
	show(&list);

	printf("\n---------- 맨 앞 요소 삭제 테스트 ----------\n");
	removeFirst(&list);
	show(&list);

	printf("\n---------- 맨 뒤 요소 삭제 테스트 ----------\n");
	removeLast(&list);
	removeLast(&list);
	show(&list);

	printf("\n---------- 원하는 요소 삭제 테스트 ----------\n");
	removeByIdx(&list, 2);
	show(&list);
	removeByIdx(&list, 5);
	show(&list);

	printf("\n---------- 요소 수정 테스트 ----------\n");
	updateByIdx(&list, 4, 49);
	updateByIdx(&list, 0, 49);
	show(&list);

	printf("\n---------- 요소 검색 테스트 ----------\n");
	int result;
	int choice;
	printf("검색 인덱스 >> ");
	scanf("%d", &choice);
	if (select(&list, choice, &result)) {
		printf("%d번의 요소 : %d\n", choice, result);
	}
	else {
		printf("입력한 인덱스 번호를 확인하세요!");
	}


	return 0;
}