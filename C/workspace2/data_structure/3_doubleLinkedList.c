#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct PhysicalCheck {
	int num; // ȸ����ȣ
	int age; // ����
	char name[30]; // �̸�
	double height; // Ű
	double weight; // ������
}Physic;

typedef struct Node {
	Physic data; // ������ �κ�
	struct Node* prev; // ���� ����� �ּ�
	struct Node* next; // ���� ����� �ּ�
}Node;

typedef struct DoubleLinkedList {
	Node* head;
	Node* tail;
}Dlist;

void init(Dlist* list) {
	// ���� ���� �����Ҵ�.
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));

	// ���θ� ���� ��Ű�� �۾�.
	list->head->next = list->tail;
	list->head->prev = NULL;

	list->tail->prev = list->head;
	list->tail->next = NULL;
}

void show(Dlist* list) {
	Node* curr = list->head;

	while (curr->next != list->tail) {
		curr = curr->next;
		printf("----- %d���� ���� -----\n", curr->data.num);
		printf("�̸� : %s\n", curr->data.name);
		printf("���� : %d��\n", curr->data.age);
		printf("Ű : %.2lf\n", curr->data.height);
		printf("������ : %.2lf\n", curr->data.weight);
		printf("------------------------\n\n");
	}
}

// ����Ʈ ���̸� return �ϴ� �Լ�, (����� ����)
int len(Dlist* list) {
	//if (list->head->next == list->tail) {
	//	return 0;
	//}
	// ���� ��Ұ� 0����� length�� ����ִ� 0�� return �Ǳ� ������
	// ���� ó������ �ʿ�� ���� �� ����.

	int length = 0;
	Node* curr = list->head;
	while (curr->next != list->tail) {
		curr = curr->next;
		length++;
	}
	return length;
}

// �߰�
// �� �տ� �߰��ϱ�
void insertFirst(Dlist* list, Physic element) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->prev = list->head;
	newNode->next = list->head->next;

	// �Ʒ��� �� �ڵ��� ������ �ٲٸ�
	// �� �տ� �������� ��, �ڿ� �ִ� ����� �ּҸ� �Ҿ���� �� �ִ�.
	// �׻� �ּҸ� �ٲ��ִ� �۾��� �� ��, � ������ �ؾ� ȿ���������� �����ؾ��Ѵ�.
	list->head->next->prev = newNode;
	list->head->next = newNode;
}

// �� �ڿ� �߰��ϱ�
void append(Dlist* list, Physic element) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->next = list->tail;
	newNode->prev = list->tail->prev;

	list->tail->prev->next = newNode;
	list->tail->prev = newNode;
}

// �ε��� ��ȣ�� �߰��ϱ�
void insertByIdx(Dlist* list, int idx, Physic element) {
	int length = len(list);

	if (idx < 0 || idx > length) {
		printf("�ε����� Ȯ���ϼ���!\n");
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

	// �ش� if���� Ż���ϸ�,
	// �߰��ϰ� ���� �ε����� �ش��ϴ� ��尡 ����ִ�.
	// curr �� �տ� �߰��ϴ� �ڵ带 �ۼ��ϸ� �ȴ�.
	newNode->next = curr;
	newNode->prev = curr->prev;

	curr->prev->next = newNode;
	curr->prev = newNode;
}

// ����
// �� �� ��� ����
void removeFirst(Dlist* list) {
	// ����Ʈ�� ����� ��
	if (list->head->next == list->tail) {
		printf("����Ʈ�� ������ϴ�.");
		return;
	}

	Node* removeNode = list->head->next;
	list->head->next = removeNode->next;
	removeNode->next->prev = list->head;
	free(removeNode);
}

// �� �� ��� ����
void removeLast(Dlist* list) {
	// ����Ʈ�� ����� ��
	if (list->head->next == list->tail) {
		printf("����Ʈ�� ������ϴ�.");
		return;
	}

	Node* removeNode = list->tail->prev;
	list->tail->prev = removeNode->prev;
	removeNode->prev->next = list->tail;
	free(removeNode);
}

// �ε��� ��ȣ�� ����
void removeByIdx(Dlist* list, int idx) {
	int length = len(list);

	if (idx < 0 || idx >= length) {
		printf("�ε����� Ȯ���ϼ���!\n");
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

	// if���� �������´ٸ�, removeNode���� �����ϰ��� ��尡 ����ִ�.
	removeNode->next->prev = removeNode->prev;
	removeNode->prev->next = removeNode->next;
	free(removeNode);
}

// ȸ����ȣ�� ����
void removeByNum(Dlist* list, int num) {
	Node* removeNode = list->head->next;
	while (removeNode != list->tail) {// head�� tail�� ����x
		if (removeNode->data.num == num) {
			break;
		}
		removeNode = removeNode->next;
	}
	//while�� ���� �� removeNode���� �����ϰ��� ��尡����ִ�,.
	//ȸ����ȣ�� ã�� ���ߴٸ�, removeNode���� tial�� ����ְԲ� ����!
	if (removeNode != list->tail) {
		removeNode->next->prev = removeNode->prev;
		removeNode->prev->next = removeNode->next;
		free(removeNode);
	}
	else {
		printf("ȸ����ȣ�� �������� �ʽ��ϴ�.");
	}

}
// �˻�
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
	Physic p1 = { 1, 22, "��ȣ��", 175.5, 82.5 };
	Physic p2 = { 2, 44, "ȫ�浿", 183.1, 85.2 };
	Physic p3 = { 3, 18, "�Ӳ���", 185.9, 94.2 };
	Physic p4 = { 4, 16, "����", 177.7, 74.1 };
	Physic p5 = { 5, 35, "������", 169.3, 59.7 };

	printf("========== �� �տ� �߰� �׽�Ʈ ==========\n");
	insertFirst(&list, p1);
	insertFirst(&list, p2);
	show(&list);

	printf("\n========== �� �ڿ� �߰� �׽�Ʈ ==========\n");
	append(&list, p3);
	//append(&list, p5);
	show(&list);

	printf("\n========== �ε��� ��ȣ�� �߰� �׽�Ʈ ==========\n");
	insertByIdx(&list, 1, p4);
	show(&list);

	printf("\n========== �� �� ��� ���� �׽�Ʈ ==========\n");
	removeFirst(&list);
	show(&list);

	printf("\n========== �� �� ��� ���� �׽�Ʈ ==========\n");
	removeLast(&list);
	show(&list);

	printf("\n========== �׽�Ʈ�� ���� ��� �߰� ==========\n");
	append(&list, p2);
	append(&list, p3);
	append(&list, p5);
	show(&list);

	//printf("\n========== �ε��� ��ȣ�� ���� �׽�Ʈ ==========\n");
	//removeByIdx(&list, 1);
	//show(&list);


	printf("\n========== ȸ����ȣ�� ���� �׽�Ʈ ==========\n");
	removeByNum(&list, 2);
	show(&list);


	printf("\n========== ȸ�� ��ȣ�� �˻� �׽�Ʈ ==========\n");
	Physic res;
	int userNum;

	printf("ȸ�� ��ȣ �Է� >> ");
	scanf("%d", &userNum);

	if (selectByNum(&list, userNum, &res)) {
		printf("---------- �˻� ��� ----------\n");
		printf("----- %d���� ���� -----\n", res.num);
		printf("�̸� : %s\n", res.name);
		printf("���� : %d��\n", res.age);
		printf("Ű : %.2lf\n", res.height);
		printf("������ : %.2lf\n", res.weight);
		printf("--------------------------------\n\n");
	}
	else {
		printf("ȸ�� ��ȣ�� Ȯ���ϼ���!\n");
	}


	return 0;
}