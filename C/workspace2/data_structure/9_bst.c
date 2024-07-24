#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; // 실질적인 데이터가 저장될 멤버 변수
	struct Node* left; // 왼쪽 자식을 저장할 포인터 변수
	struct Node* right; // 오른쪽 자식을 저장할 포인터 변수
}BinNode;

// 추가 재귀함수 활용
BinNode* add(BinNode* Node, int element);

// 추가 반복문 활용
void add2(BinNode* root, int element);

// 전위 순회 : 본인 방문, 왼쪽 자식, 오른쪽 자식
void proShow(BinNode* Node);

// 중위 순회 : 왼쪽 자식, 본인 방문, 오른쪽 자식
void inShow(BinNode* Node);

// 후위 순회 : 왼쪽 자식, 오른쪽 자식, 본인 방문
void postShow(BinNode* Node);

// 삭제
void removeElement(BinNode* root, int element);

int main() {
	BinNode* root;
	root = NULL;
	root = add(root, 30); // 최초에 삽입된 데이터를 root로 삼기 위함.

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

	printf("전위 순회 : ");
	proShow(root);
	printf("\n\n");

	printf("중위 순회 : ");
	inShow(root);
	printf("\n\n");

	printf("후위 순회 : ");
	postShow(root);
	printf("\n\n");

	removeElement(root, 15);

	printf("중위 순회 : ");
	inShow(root);
	printf("\n\n");

	return 0;
}

// 추가 재귀함수 활용
BinNode* add(BinNode* Node, int element) {
	if (Node == NULL) {
		// 첫번째 호출이라면
		// 아직 데이터가 하나도 없는 트리라면
		// 루트에다가 노드를 하나 만들어 넣어준다.

		// 그 다음, 재귀함수 활용하면서 호출할 때에는
		// 해당 if문에 들어왔단 얘기는 매개변수로 NULL 들어온것.
		// 즉, 값 비교 후 내려오면서 비어있는 곳에 도착했다는 것을 의미!
		// 그래서 마지막으로 호출된 매개변수 Node에
		// 데이터를 추가해주면서 해당 주소를 리턴하며 끝!
		Node = (BinNode*)malloc(sizeof(BinNode));
		Node->data = element;
		Node->left = NULL;
		Node->right = NULL;
	}
	else if (Node->data == element) { // 중복이라면
		printf("ERROR!!! 중복값 입력 불가!\n\n");
	}
	else if (Node->data < element) {
		Node->right = add(Node->right, element);
	}
	else if (Node->data > element) {
		Node->left = add(Node->left, element);
	}

	return Node;
};

// 추가 반복문 활용
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
			printf("존재하는 값은 담을 수 없습니다!\n\n");
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

// 전위 순회 : 본인 방문, 왼쪽 자식, 오른쪽 자식
void proShow(BinNode* Node) {
	if (Node != NULL) {
		printf("[%d] ", Node->data);
		proShow(Node->left);
		proShow(Node->right);
	}
};

// 중위 순회 : 왼쪽 자식, 본인 방문, 오른쪽 자식
void inShow(BinNode* Node) {
	if (Node != NULL) {
		inShow(Node->left);
		printf("[%d] ", Node->data);
		inShow(Node->right);
	}
};

// 후위 순회 : 왼쪽 자식, 오른쪽 자식, 본인 방문
void postShow(BinNode* Node) {
	if (Node != NULL) {
		postShow(Node->left);
		postShow(Node->right);
		printf("[%d] ", Node->data);
	}
};

// 삭제
void removeElement(BinNode* root, int element) {
	BinNode* curr = root; // 삭제할 노드 찾기
	BinNode* parent = NULL;
	BinNode* child = NULL;

	if (root == NULL) {
		printf("ERROR : 트리가 비어있음\n");
		return;
	}

	// 삭제할 노드 찾기
	while (curr != NULL) {
		if (curr->data < element) {
			parent = curr;
			curr = curr->right;
		}
		else if (curr->data > element) {
			parent = curr;
			curr = curr->left;
		}
		else { // 찾았다면
			break;
		}
	}

	if (curr == NULL) { // 삭제하고픈 요소가 현재 트리에 없다면
		printf("ERROR : 요소 없음\n");
		return;
	}

	// 삭제하고자 하는 노드가 리프노드 라면
	if (curr->left == NULL && curr->right == NULL) { // 리프노드라면
		if (parent == NULL) { // 리프노드면서 루트라면
			root = NULL;
		}
		else { // 루트는 아닌 경우
			if (parent->left == curr) {
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
	}

	// 만일 삭제하고자 하는 노드가 자식 1개를 갖고 있다면
	else if (curr->left == NULL || curr->right == NULL) {
		if (curr->left != NULL) { // 삭제할 노드가 왼쪽 자식을 가진 경우
			child = curr->left;
		}
		else { // 오른쪽 자식을 가진 경우
			child = curr->right;
		}

		if (parent == NULL) { // 자식을 하나가진 루트를 삭제하고자 할 경우
			root = child;
		}
		else {
			if (curr == parent->right) { // 삭제할 노드가 부모의 오른족 자식이라면
				parent->right = child;
			}
			else { // 삭제할 노드가 부모의 왼쪽 자식이라면
				parent->left = child;
			}
		}
	}

	// 삭제하고자 하는 노드가 자식 2개를 갖고 있다면
	else {
		// 왼쪽 서브트리에서 최댓값 찾기!
		BinNode* max_parent = curr; // 최댓값의 부모노드
		BinNode* max = curr->left;


		while (max->right != NULL) {
			max_parent = max;
			max = max->right;
		}
		//// while문이 끝나면
		//// max에는 올려줄 노드가, max_parent에는 올려줄 노드의 부모가 들어있다.
		//if (curr == parent->left) { // 삭제할 노드가 부모의 왼쪽 자식이라면
		//	parent->left = max;
		//}
		//else { // 오른쪽 자식이라면
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