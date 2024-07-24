#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; // �������� �����Ͱ� ����� ��� ����
	struct Node* left; // ���� �ڽ��� ������ ������ ����
	struct Node* right; // ������ �ڽ��� ������ ������ ����
}BinNode;

// �߰� ����Լ� Ȱ��
BinNode* add(BinNode* Node, int element);

// �߰� �ݺ��� Ȱ��
void add2(BinNode* root, int element);

// ���� ��ȸ : ���� �湮, ���� �ڽ�, ������ �ڽ�
void proShow(BinNode* Node);

// ���� ��ȸ : ���� �ڽ�, ���� �湮, ������ �ڽ�
void inShow(BinNode* Node);

// ���� ��ȸ : ���� �ڽ�, ������ �ڽ�, ���� �湮
void postShow(BinNode* Node);

// ����
void removeElement(BinNode* root, int element);

int main() {
	BinNode* root;
	root = NULL;
	root = add(root, 30); // ���ʿ� ���Ե� �����͸� root�� ��� ����.

	//add2(root, 15);
	//add2(root, 20);
	//add2(root, 11);
	//add2(root, 9);
	//add2(root, 14);
	//add2(root, 33);
	//add2(root, 31);

	add(root, 15);
	add(root, 20);
	add(root, 11);
	add(root, 9);
	add(root, 14);
	add(root, 33);
	add(root, 31);
	add(root, 35);

	printf("���� ��ȸ : ");
	proShow(root);
	printf("\n\n");

	printf("���� ��ȸ : ");
	inShow(root);
	printf("\n\n");

	printf("���� ��ȸ : ");
	postShow(root);
	printf("\n\n");

	removeElement(root, 15);

	printf("���� ��ȸ : ");
	inShow(root);
	printf("\n\n");

	return 0;
}

// �߰� ����Լ� Ȱ��
BinNode* add(BinNode* Node, int element) {
	if (Node == NULL) {
		// ù��° ȣ���̶��
		// ���� �����Ͱ� �ϳ��� ���� Ʈ�����
		// ��Ʈ���ٰ� ��带 �ϳ� ����� �־��ش�.

		// �� ����, ����Լ� Ȱ���ϸ鼭 ȣ���� ������
		// �ش� if���� ���Դ� ���� �Ű������� NULL ���°�.
		// ��, �� �� �� �������鼭 ����ִ� ���� �����ߴٴ� ���� �ǹ�!
		// �׷��� ���������� ȣ��� �Ű����� Node��
		// �����͸� �߰����ָ鼭 �ش� �ּҸ� �����ϸ� ��!
		Node = (BinNode*)malloc(sizeof(BinNode));
		Node->data = element;
		Node->left = NULL;
		Node->right = NULL;
	}
	else if (Node->data == element) { // �ߺ��̶��
		printf("ERROR!!! �ߺ��� �Է� �Ұ�!\n\n");
	}
	else if (Node->data < element) {
		Node->right = add(Node->right, element);
	}
	else if (Node->data > element) {
		Node->left = add(Node->left, element);
	}

	return Node;
};

// �߰� �ݺ��� Ȱ��
void add2(BinNode* root, int element) {

	BinNode* p_curr = NULL;
	BinNode* curr = root;
	while (curr != NULL) {
		if (curr->data < element) {
			p_curr = curr;
			curr = curr->right;
		}
		else if (curr->data > element) {
			p_curr = curr;
			curr = curr->left;
		}
		else {
			printf("�����ϴ� ���� ���� �� �����ϴ�!\n\n");
			return;
		}
	}

	curr = (BinNode*)malloc(sizeof(BinNode));
	curr->data = element;
	curr->left = NULL;
	curr->right = NULL;

	if (p_curr->data < element) {
		p_curr->right = curr;
	}
	else {
		p_curr->left = curr;
	}
};

// ���� ��ȸ : ���� �湮, ���� �ڽ�, ������ �ڽ�
void proShow(BinNode* Node) {
	if (Node != NULL) {
		printf("[%d] ", Node->data);
		proShow(Node->left);
		proShow(Node->right);
	}
};

// ���� ��ȸ : ���� �ڽ�, ���� �湮, ������ �ڽ�
void inShow(BinNode* Node) {
	if (Node != NULL) {
		inShow(Node->left);
		printf("[%d] ", Node->data);
		inShow(Node->right);
	}
};

// ���� ��ȸ : ���� �ڽ�, ������ �ڽ�, ���� �湮
void postShow(BinNode* Node) {
	if (Node != NULL) {
		postShow(Node->left);
		postShow(Node->right);
		printf("[%d] ", Node->data);
	}
};

// ����
void removeElement(BinNode* root, int element) {
	BinNode* curr = root; // ������ ��� ã��
	BinNode* parent = NULL;
	BinNode* child = NULL;

	if (root == NULL) {
		printf("ERROR : Ʈ���� �������\n");
		return;
	}

	// ������ ��� ã��
	while (curr != NULL) {
		if (curr->data < element) {
			parent = curr;
			curr = curr->right;
		}
		else if (curr->data > element) {
			parent = curr;
			curr = curr->left;
		}
		else { // ã�Ҵٸ�
			break;
		}
	}

	if (curr == NULL) { // �����ϰ��� ��Ұ� ���� Ʈ���� ���ٸ�
		printf("ERROR : ��� ����\n");
		return;
	}

	// �����ϰ��� �ϴ� ��尡 ������� ���
	if (curr->left == NULL && curr->right == NULL) { // ���������
		if (parent == NULL) { // �������鼭 ��Ʈ���
			root = NULL;
		}
		else { // ��Ʈ�� �ƴ� ���
			if (parent->left == curr) {
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
	}

	// ���� �����ϰ��� �ϴ� ��尡 �ڽ� 1���� ���� �ִٸ�
	else if (curr->left == NULL || curr->right == NULL) {
		if (curr->left != NULL) { // ������ ��尡 ���� �ڽ��� ���� ���
			child = curr->left;
		}
		else { // ������ �ڽ��� ���� ���
			child = curr->right;
		}

		if (parent == NULL) { // �ڽ��� �ϳ����� ��Ʈ�� �����ϰ��� �� ���
			root = child;
		}
		else {
			if (curr == parent->right) { // ������ ��尡 �θ��� ������ �ڽ��̶��
				parent->right = child;
			}
			else { // ������ ��尡 �θ��� ���� �ڽ��̶��
				parent->left = child;
			}
		}
	}

	// �����ϰ��� �ϴ� ��尡 �ڽ� 2���� ���� �ִٸ�
	else {
		// ���� ����Ʈ������ �ִ� ã��!
		BinNode* max_parent = curr; // �ִ��� �θ���
		BinNode* max = curr->left;


		while (max->right != NULL) {
			max_parent = max;
			max = max->right;
		}
		//// while���� ������
		//// max���� �÷��� ��尡, max_parent���� �÷��� ����� �θ� ����ִ�.
		//if (curr == parent->left) { // ������ ��尡 �θ��� ���� �ڽ��̶��
		//	parent->left = max;
		//}
		//else { // ������ �ڽ��̶��
		//	parent->right = max;
		//}
		//max->left = curr->left;
		//max->right = curr->right;
		//max_parent->right = NULL;
		curr->data = max->data;
		max_parent->right = NULL;
		curr = max;
	}
	free(curr);
};