#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct PhysicalCheck {
	int num; // 회원번호
	int age; // 나이
	char name[30]; // 이름
	double height; // 키
	double weight; // 몸무게
}Physic;

typedef struct Node {
	Physic data; // 데이터 부분
	struct Node* prev; // 이전 노드의 주소
	struct Node* next; // 다음 노드의 주소
}Node;

typedef struct DoubleLinkedList {
	Node* head;
	Node* tail;
}Dlist;

void init(Dlist* list) {
	// 헤드와 테일 동적할당.
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));

	// 서로를 연결 시키는 작업.
	list->head->next = list->tail;
	list->head->prev = NULL;

	list->tail->prev = list->head;
	list->tail->next = NULL;
}

void show(Dlist* list) {
	Node* curr = list->head;

	while (curr->next != list->tail) {
		curr = curr->next;
		printf("----- %d번의 정보 -----\n", curr->data.num);
		printf("이름 : %s\n", curr->data.name);
		printf("나이 : %d살\n", curr->data.age);
		printf("키 : %.2lf\n", curr->data.height);
		printf("몸무게 : %.2lf\n", curr->data.weight);
		printf("------------------------\n\n");
	}
}

// 리스트 길이를 return 하는 함수, (요소의 갯수)
int len(Dlist* list) {
	//if (list->head->next == list->tail) {
	//	return 0;
	//}
	// 만약 요소가 0개라면 length에 들어있는 0이 return 되기 때문에
	// 따로 처리해줄 필요는 없을 것 같다.

	int length = 0;
	Node* curr = list->head;
	while (curr->next != list->tail) {
		curr = curr->next;
		length++;
	}
	return length;
}

// 추가
// 맨 앞에 추가하기
void insertFirst(Dlist* list, Physic element) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->prev = list->head;
	newNode->next = list->head->next;

	// 아래의 두 코드의 순서를 바꾸면
	// 맨 앞에 삽입했을 때, 뒤에 있는 노드의 주소를 잃어버릴 수 있다.
	// 항상 주소를 바꿔주는 작업을 할 때, 어떤 순서로 해야 효과적인지를 생각해야한다.
	list->head->next->prev = newNode;
	list->head->next = newNode;
}

// 맨 뒤에 추가하기
void append(Dlist* list, Physic element) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->next = list->tail;
	newNode->prev = list->tail->prev;

	list->tail->prev->next = newNode;
	list->tail->prev = newNode;
}

// 인덱스 번호로 추가하기
void insertByIdx(Dlist* list, int idx, Physic element) {
	int length = len(list);

	if (idx < 0 || idx > length) {
		printf("인덱스를 확인하세요!\n");
		return;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	Node* curr;

	if (idx < length / 2) {
		curr = list->head;
		printf("length : %d\n", length);
		printf("head!!!!!!!!!!!!!!!!!!!!!!\n");
		for (int i = 0; i < idx + 1; i++) {
			curr = curr->next;
		}
	}
	else {
		curr = list->tail;
		printf("length : %d\n", length);
		printf("tail!!!!!!!!!!!!!!!!!!!!!!\n");
		for (int i = length; i > idx; i--) {
			curr = curr->prev;
		}
	}

	// 해당 if문을 탈출하면,
	// 추가하고 싶은 인덱스에 해당하는 노드가 담겨있다.
	// curr 에 앞에 추가하는 코드를 작성하면 된다.
	newNode->next = curr;
	newNode->prev = curr->prev;

	curr->prev->next = newNode;
	curr->prev = newNode;
}

// 삭제
// 맨 앞 요소 삭제
void removeFirst(Dlist* list) {
	// 리스트가 비었을 때
	if (list->head->next == list->tail) {
		printf("리스트가 비었습니다.");
		return;
	}

	Node* removeNode = list->head->next;
	list->head->next = removeNode->next;
	removeNode->next->prev = list->head;
	free(removeNode);
}

// 맨 뒤 요소 삭제
void removeLast(Dlist* list) {
	// 리스트가 비었을 때
	if (list->head->next == list->tail) {
		printf("리스트가 비었습니다.");
		return;
	}

	Node* removeNode = list->tail->prev;
	list->tail->prev = removeNode->prev;
	removeNode->prev->next = list->tail;
	free(removeNode);
}

// 인덱스 번호로 삭제
void removeByIdx(Dlist* list, int idx) {
	int length = len(list);

	if (idx < 0 || idx >= length) {
		printf("인덱스를 확인하세요!\n");
		return;
	}

	Node* removeNode;

	if (idx < length / 2) {
		removeNode = list->head;
		for (int i = 0; i < idx + 1; i++) {
			removeNode = removeNode->next;
		}
	}
	else {
		removeNode = list->tail;
		for (int i = length; i > idx; i--) {
			removeNode = removeNode->prev;
		}
	}

	// if문을 빠져나온다면, removeNode에는 삭제하고픈 노드가 들어있다.
	removeNode->next->prev = removeNode->prev;
	removeNode->prev->next = removeNode->next;
	free(removeNode);
}

// 회원번호로 삭제
void removeByNum(Dlist* list, int num) {
	Node* removeNode = list->head->next;
	while (removeNode != list->tail) {// head나 tail을 삭제x
		if (removeNode->data.num == num) {
			break;
		}
		removeNode = removeNode->next;
	}
	//while문 실행 후 removeNode에는 삭제하고픈 노드가들어있다,.
	//회원번호를 찾지 못했다면, removeNode에는 tial이 담겨있게끔 설계!
	if (removeNode != list->tail) {
		removeNode->next->prev = removeNode->prev;
		removeNode->prev->next = removeNode->next;
		free(removeNode);
	}
	else {
		printf("회원번호가 존재하지 않습니다.");
	}

}
// 검색
int selectByNum(Dlist* list, int num, Physic* res) {
	Node* curr = list->head->next;

	while (curr != list->tail) {
		if (curr->data.num == num) {
			*res = curr->data;
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}





int main() {
	Dlist list;
	init(&list);
	Physic p1 = { 1, 22, "류호근", 175.5, 82.5 };
	Physic p2 = { 2, 44, "홍길동", 183.1, 85.2 };
	Physic p3 = { 3, 18, "임꺽정", 185.9, 94.2 };
	Physic p4 = { 4, 16, "장길산", 177.7, 74.1 };
	Physic p5 = { 5, 35, "김유신", 169.3, 59.7 };

	printf("========== 맨 앞에 추가 테스트 ==========\n");
	insertFirst(&list, p1);
	insertFirst(&list, p2);
	show(&list);

	printf("\n========== 맨 뒤에 추가 테스트 ==========\n");
	append(&list, p3);
	//append(&list, p5);
	show(&list);

	printf("\n========== 인덱스 번호로 추가 테스트 ==========\n");
	insertByIdx(&list, 1, p4);
	show(&list);

	printf("\n========== 맨 앞 요소 삭제 테스트 ==========\n");
	removeFirst(&list);
	show(&list);

	printf("\n========== 맨 뒤 요소 삭제 테스트 ==========\n");
	removeLast(&list);
	show(&list);

	printf("\n========== 테스트를 위해 요소 추가 ==========\n");
	append(&list, p2);
	append(&list, p3);
	append(&list, p5);
	show(&list);

	//printf("\n========== 인덱스 번호로 삭제 테스트 ==========\n");
	//removeByIdx(&list, 1);
	//show(&list);


	printf("\n========== 회원번호로 삭제 테스트 ==========\n");
	removeByNum(&list, 2);
	show(&list);


	printf("\n========== 회원 번호로 검색 테스트 ==========\n");
	Physic res;
	int userNum;

	printf("회원 번호 입력 >> ");
	scanf("%d", &userNum);

	if (selectByNum(&list, userNum, &res)) {
		printf("---------- 검색 결과 ----------\n");
		printf("----- %d번의 정보 -----\n", res.num);
		printf("이름 : %s\n", res.name);
		printf("나이 : %d살\n", res.age);
		printf("키 : %.2lf\n", res.height);
		printf("몸무게 : %.2lf\n", res.weight);
		printf("--------------------------------\n\n");
	}
	else {
		printf("회원 번호를 확인하세요!\n");
	}


	return 0;
}