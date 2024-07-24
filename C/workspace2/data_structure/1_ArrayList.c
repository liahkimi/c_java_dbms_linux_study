#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5

typedef struct {
	int ar[MAX];
	int length;
}ArrayList;

// ����ü�� �̿��ؼ� ������ �����,
// �� ������ �ʱ�ȭ���ִ� �Լ� ����
void init(ArrayList* list) {
	list->length = 0;
}

// ��� Ȯ�ο� �Լ�
void show(ArrayList* list) {
	int length = list->length;
	if (length == 0) {
		printf("��Ұ� �����ϴ�.\n");
		return; // �Լ��� ���Ḧ �ǹ�
	}

	for (int i = 0; i < length; i++) {
		printf("[%04d] ", list->ar[i]);
	}
	printf("\n");
}

// ��Ұ� ���� á���� ������ �˻��ϴ� �Լ�
// ���ǽ����� ����� �Լ�.
int isFull(ArrayList* list) {
	if (list->length >= MAX) {
		return 1;
	}
	return 0;
}

// �߰�
// �� �ڿ� �߰�
int append(ArrayList* list, int element) {
	if (isFull(list)) {
		return 0;
	}
	list->ar[list->length++] = element;
	return 1;
}

// ����
int insert(ArrayList* list, int element, int idx) {
	int length = list->length;
	if (isFull(list) || idx > length) { // ���� á�ų�, �ε��� ��ȣ�� ������ ��� ��
		return 0;
	}
	else if (idx == length) { // �� �ڿ� �߰��Ѵٴ� ����� ����.
		return append(list, element);
	}
	else {
		// �̻縦 ���� ��Ų��.
		for (int i = length; i > idx; i--) {
			list->ar[i] = list->ar[i - 1];
		}
		list->ar[idx] = element;
		list->length++;
		return 1;
	}
}

// ����
// �ε��� ��ȣ�� �����ϱ�
int removeByIdx(ArrayList* list, int idx) {
	int length = list->length;
	if (length == 0 || idx >= length) {
		return 0;
	}
	for (int i = idx; i < length - 1; i++) {
		list->ar[i] = list->ar[i + 1];
	}
	list->length--;
	return 1;
}

// ��ҷ� �����ϱ�
int removeElement(ArrayList* list, int element) {
	int idx = 0;
	int flag = 0;

	// �Ű������� �Ѿ�� ��Ұ� ����Ʈ�� �ִ��� Ȯ��!
	// �ִٸ� �ش� �ε��� ��ȣ�� idx�� �������ش�.
	for (int i = 0; i < list->length; i++) {
		if (list->ar[i] == element) { // ��Ұ� �ִ�!
			flag = 1;
			idx = i;
			break;
		}
	}

	if (flag) {
		removeByIdx(list, idx);
	}
	return flag;
}

// ���� ��� ��� �����ϱ�.
void removeElements(ArrayList* list, int element) {
	while (removeElement(list, element));
}

// ����
// �ε��� ��ȣ�� �����ϱ�
int updateByIdx(ArrayList* list, int idx, int element) {
	int length = list->length;
	if (length == 0 || idx >= length) {
		return 0;
	}
	list->ar[idx] = element;
	return 1;
}

// ��ҷ� �����ϱ�, 
// ù��° ���� ��Ҹ� �ٲٴ� �ɷ�!
// data -> �긦 �����ϰ� �;��.
// source -> ��ɷ� �����ҷ���.
int updateByElement(ArrayList* list, int data, int source) {
	int idx = 0;
	idx = prevCount(list, data);

	if (idx != -1) {
		updateByIdx(list, idx, source);
		return 1;
	}
	return 0;
}

// ���� �ý���, �ǽ� �Լ�
// �� �տ� �� ���� ����ڰ� �ִ����� ���ϴ� �Լ�
int prevCount(ArrayList* list, int element) {
	for (int i = 0; i < list->length; i++) {
		if (list->ar[i] == element) {
			return i;
		}
	}
	return -1;
}

int main() {
	//ArrayList list;
	//init(&list);
	//printf("length : %d\n", list.length);
	//show(&list);

	//// �׽�Ʈ, ��Ҹ� ���� �߰��غ���.
	////list.ar[0] = 10;
	////list.length = 1;
	////show(&list);

	//// �츮�� ���� �Լ��� �׽�Ʈ!
	//append(&list, 10);
	//append(&list, 20);
	//append(&list, 30);
	//show(&list);

	//insert(&list, 15, 2);
	//insert(&list, 100, 2);
	//show(&list);

	//removeByIdx(&list, 2);
	//removeByIdx(&list, 5);
	//append(&list, 20);
	//show(&list);

	//removeElement(&list, 20);
	//removeElement(&list, 20);
	//removeElement(&list, 100);
	//show(&list);

	//append(&list, 15);
	//append(&list, 15);
	//show(&list);

	////removeElements(&list, 15);
	//show(&list);
	//
	//updateByIdx(&list, 3, 100);
	//show(&list);

	//updateByElement(&list, 15, 49);
	//show(&list);

	// ==================== Test ��! =================================


	// ���� ���� ���α׷� ���� �ǽ�
	ArrayList users;
	ArrayList* ptr = &users;
	int choice = 0;
	int phone, updatePhone;
	init(ptr);

	while (1) {
		printf("===== ���� ���� �ý��� =====\n");
		printf("1. ���� ���� ���� Ȯ���ϱ�\n");
		printf("2. ���� �ϱ�\n");
		printf("3. ���� ��� �ϱ�\n");
		printf("4. �� ���� ���� ����\n"); // �� �տ� �� ��?
		printf("5. ���α׷� �����ϱ�\n\n");
		printf("�޴��� �����ϼ��� >> ");
		scanf("%d", &choice);

		if (choice == 5) {
			printf("���α׷� ����\n");
			break;
		}

		switch (choice) {
		case 1: // ���� Ȯ��
			show(ptr);
			printf("\n");
			break;
		case 2: // ���� �ϱ�
			if (isFull(ptr)) {
				printf("���� ���� �ο��� ���� á���ϴ�. ��ø� ��ٷ��ּ���.\n\n");
				break;
			}
			printf("\n�޴��� ��ȣ �� ���ڸ��� �Է� >> ");
			scanf("%d", &phone);
			if (append(ptr, phone)) {
				printf("\n������ ���������� �Ϸ�Ǿ����ϴ�.\n\n");
				break;
			}
			printf("\n������ �߻��߽��ϴ�.\n\n");
			break;
		case 3: // ���� ���
			printf("\n���� ��� �޴��� ��ȣ ���ڸ� >> ");
			scanf("%d", &phone);

			if (removeElement(ptr, phone)) {
				printf("���� ��� �Ϸ�\n\n");
			}
			else {
				printf("�ش� ��ȣ�� �������� �ʽ��ϴ�.\n\n");
			}
			break;

		case 4: // �� �տ� ����ڰ� �� �� �ִ���!
			printf("��ȣ �Է� >> ");
			scanf("%d", &phone);

			int waiting = prevCount(ptr, phone);

			if (waiting == -1) {
				printf("��ȣ�� �ٽ� Ȯ�����ּ���.\n\n");
			}
			else {
				while (1) {
					printf("%04d������ ����\n", phone);
					printf("1. ��ȣ ����\n2. �� �� ����� �� ������ Ȯ��\n3. ������\n");
					printf("�޴� ���� >> ");
					scanf("%d", &choice);

					if (choice == 3) {
						printf("�������� �̵��մϴ�.\n\n");
						break;
					}
					else if (choice == 1) { // ��ȣ ����
						printf("�� ��ȣ �Է� >> ");
						scanf("%d", &updatePhone);
						updateByElement(ptr, phone, updatePhone);
						phone = updatePhone;
						printf("���� �Ϸ�\n\n");
					}
					else if (choice == 2) {
						printf("%d���� �տ� ����ڷ� �ֽ��ϴ�.\n\n", waiting);
					}
					else {
						printf("����� �Է����ּ���.\n\n");
					}
				}
			}
			break;
		default:
			printf("�ٽ� �Է����ּ���\n\n");
		}
	}


	return 0;
}