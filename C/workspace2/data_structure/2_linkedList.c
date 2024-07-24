#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; // �������� ����Ʈ�� ��Ұ� ����� ����
	struct Node* link; // ���� typedef Node �� ���ǵ��� �ʾұ⿡ ���� ��� X
}Node;

typedef struct LinkedList {
	Node* head; // ��ũ�帮��Ʈ�� ���� ó�� �ּ�
}List;

// �ʱ�ȭ �Լ�
void init(List* list) {
	list->head = NULL;
};

// ��� Ȯ�ο� �Լ�
void show(List* list) {
	Node* curr = list->head;
	while (curr != NULL) {
		printf("[%d] -> ", curr->data);
		curr = curr->link;
	}
	printf("\n");
}

// ����Ʈ ����� ������ �˷��ִ� �Լ�
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

// �߰�
// �� �տ� �߰��ϱ�
void insertFirst(List* list, int element) {
	// �����Ҵ��� ����
	// ���Ӱ� �߰��� ���� �� �Լ� ȣ���� �������� �޸𸮿� �����־���Ѵ�.
	// ���� �����Ҵ��� ���ش�.
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->link = list->head;
	list->head = newNode;
}

// �� �ڿ� �߰��ϱ�
void append(List* list, int element) {
	// ����Ʈ�� ��Ұ� �ϳ��� ���ٸ�
	if (list->head == NULL) {
		insertFirst(list, element); // �� ó���� ��Ҹ� �߰�,
		return; // �Լ� ����.
	}

	Node* curr = list->head;
	while (curr->link != NULL) {
		curr = curr->link;
	}
	// �ݺ����� �� ���� ���� curr���� ������ ��尡 ����ִ�.
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->link = NULL;
	curr->link = newNode;
}

// ������ �߰��� �߰��ϱ�
// �ε��� ��ȣ�� Ȱ���Ͽ� �߰��ϱ�
void insert(List* list, int idx, int element) {
	// �ε��� ��ȣ ����, ���̺��� Ŭ ��
	int length = len(list);
	if (idx < 0 || idx > length) {
		printf("�ε��� ����\n");
	}
	else if (idx == 0) { // idx �� 0 �� ���Դٸ�.
		insertFirst(list, element);
	}
	else if (idx == length) { // ���� �ڿ� �߰��ϸ� ��
		append(list, element);
	}
	else { // ������ ����
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

// ����
// �� �տ� ��� ����
void removeFirst(List* list) {
	// ����Ʈ�� ����ִٸ�
	if (list->head == NULL) {
		printf("�����Ͱ� �ƹ��͵� �����ϴ�.\n");
		return;
	}
	Node* removeNode = list->head;
	list->head = removeNode->link;
	free(removeNode);
}

// �� �� ��� ����
void removeLast(List* list) {
	// ����Ʈ�� ����ִٸ�
	if (list->head == NULL) {
		printf("�����Ͱ� �ƹ��͵� �����ϴ�.\n");
	}
	else if (len(list) == 1) {
		removeFirst(list);
	}
	// ����Ʈ ��Ұ� �� �� ����ִ� ���
	// curr->link �� NULL�̱� ������
	// curr->link->link�� ��ǻ� NULL->link�� ������� �Ͱ� ���� �ȴ�.
	// ���� ������ �߻��Ѵ�.

	else { // ������ ���� �ڿ� ����
		Node* curr = list->head;
		while (curr->link->link != NULL) {
			curr = curr->link;
		}
		// �ݺ��� �����, �����ϰ��� ����� �� ��尡 curr
		free(curr->link);
		curr->link = NULL;
	}
}

// �ε��� ��ȣ�� �����ϱ�
void removeByIdx(List* list, int idx) {
	// �ε��� ��ȣ ����, ���̺��� Ŭ ��
	int length = len(list);
	if (idx < 0 || idx > length) {
		printf("�ε��� ����\n");
	}
	else if (idx == 0) { // idx �� 0 �� ���Դٸ�.
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

// ����
// �ε��� ��ȣ�� ��� �����ϱ�
void updateByIdx(List* list, int idx, int element) {
	int length = len(list);
	if (idx < 0 || idx >= length) {
		printf("�ε��� ����\n");
	}
	else {
		Node* curr = list->head;
		for (int i = 0; i < idx; i++) {
			curr = curr->link;
		}
		curr->data = element;
	}
}

// �˻�
// �ش� �ε��� ��ȣ�� �����͸� �����ϴ� �� �ƴ϶�
// �Ű������� �Ѿ�� �ּҿ� �����͸� �������ش�.
int select(List* list, int idx, int* res) {
	// �ε��� ��ȣ�� �����̰ų� ���̺��� Ŭ ���
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

	printf("---------- �� �� ��� �߰� �׽�Ʈ ----------\n");
	insertFirst(&list, 10);
	insertFirst(&list, 20);
	insertFirst(&list, 30);
	show(&list);

	printf("\n---------- �� �� ��� �߰� �׽�Ʈ ----------\n");
	append(&list, 40);
	append(&list, 50);
	append(&list, 60);
	show(&list);

	printf("\n---------- ��� ���� �׽�Ʈ ----------\n");
	insert(&list, 4, 111);
	show(&list);
	insert(&list, 2, 222);
	show(&list);
	insert(&list, 0, 777);
	show(&list);
	insert(&list, 9, 486);
	show(&list);

	printf("\n---------- �� �� ��� ���� �׽�Ʈ ----------\n");
	removeFirst(&list);
	show(&list);

	printf("\n---------- �� �� ��� ���� �׽�Ʈ ----------\n");
	removeLast(&list);
	removeLast(&list);
	show(&list);

	printf("\n---------- ���ϴ� ��� ���� �׽�Ʈ ----------\n");
	removeByIdx(&list, 2);
	show(&list);
	removeByIdx(&list, 5);
	show(&list);

	printf("\n---------- ��� ���� �׽�Ʈ ----------\n");
	updateByIdx(&list, 4, 49);
	updateByIdx(&list, 0, 49);
	show(&list);

	printf("\n---------- ��� �˻� �׽�Ʈ ----------\n");
	int result;
	int choice;
	printf("�˻� �ε��� >> ");
	scanf("%d", &choice);
	if (select(&list, choice, &result)) {
		printf("%d���� ��� : %d\n", choice, result);
	}
	else {
		printf("�Է��� �ε��� ��ȣ�� Ȯ���ϼ���!");
	}


	return 0;
}