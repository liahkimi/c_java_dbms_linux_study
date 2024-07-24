#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5

typedef struct {
	int ar[MAX];
	int length;
}ArrayList;

// 구조체를 이용해서 변수를 만들고,
// 그 변수를 초기화해주는 함수 정의
void init(ArrayList* list) {
	list->length = 0;
}

// 요소 확인용 함수
void show(ArrayList* list) {
	int length = list->length;
	if (length == 0) {
		printf("요소가 없습니다.\n");
		return; // 함수의 종료를 의미
	}

	for (int i = 0; i < length; i++) {
		printf("[%04d] ", list->ar[i]);
	}
	printf("\n");
}

// 요소가 가득 찼는지 유무를 검사하는 함수
// 조건식으로 사용할 함수.
int isFull(ArrayList* list) {
	if (list->length >= MAX) {
		return 1;
	}
	return 0;
}

// 추가
// 맨 뒤에 추가
int append(ArrayList* list, int element) {
	if (isFull(list)) {
		return 0;
	}
	list->ar[list->length++] = element;
	return 1;
}

// 삽입
int insert(ArrayList* list, int element, int idx) {
	int length = list->length;
	if (isFull(list) || idx > length) { // 가득 찼거나, 인덱스 번호가 범위를 벗어날 때
		return 0;
	}
	else if (idx == length) { // 맨 뒤에 추가한다는 내용과 동일.
		return append(list, element);
	}
	else {
		// 이사를 먼저 시킨다.
		for (int i = length; i > idx; i--) {
			list->ar[i] = list->ar[i - 1];
		}
		list->ar[idx] = element;
		list->length++;
		return 1;
	}
}

// 삭제
// 인덱스 번호로 삭제하기
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

// 요소로 삭제하기
int removeElement(ArrayList* list, int element) {
	int idx = 0;
	int flag = 0;

	// 매개변수로 넘어온 요소가 리스트에 있는지 확인!
	// 있다면 해당 인덱스 번호를 idx에 저장해준다.
	for (int i = 0; i < list->length; i++) {
		if (list->ar[i] == element) { // 요소가 있다!
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

// 같은 요소 모두 삭제하기.
void removeElements(ArrayList* list, int element) {
	while (removeElement(list, element));
}

// 수정
// 인덱스 번호로 수정하기
int updateByIdx(ArrayList* list, int idx, int element) {
	int length = list->length;
	if (length == 0 || idx >= length) {
		return 0;
	}
	list->ar[idx] = element;
	return 1;
}

// 요소로 수정하기, 
// 첫번째 만난 요소만 바꾸는 걸로!
// data -> 얘를 수정하고 싶어요.
// source -> 요걸로 수정할래요.
int updateByElement(ArrayList* list, int data, int source) {
	int idx = 0;
	idx = prevCount(list, data);

	if (idx != -1) {
		updateByIdx(list, idx, source);
		return 1;
	}
	return 0;
}

// 예약 시스템, 실습 함수
// 내 앞에 몇 팀의 대기자가 있는지를 구하는 함수
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

	//// 테스트, 요소를 직접 추가해보자.
	////list.ar[0] = 10;
	////list.length = 1;
	////show(&list);

	//// 우리가 만든 함수로 테스트!
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

	// ==================== Test 끝! =================================


	// 예약 서비스 프로그램 제작 실습
	ArrayList users;
	ArrayList* ptr = &users;
	int choice = 0;
	int phone, updatePhone;
	init(ptr);

	while (1) {
		printf("===== 예약 정보 시스템 =====\n");
		printf("1. 현재 예약 정보 확인하기\n");
		printf("2. 예약 하기\n");
		printf("3. 예약 취소 하기\n");
		printf("4. 내 예약 정보 보기\n"); // 내 앞에 몇 팀?
		printf("5. 프로그램 종료하기\n\n");
		printf("메뉴를 선택하세요 >> ");
		scanf("%d", &choice);

		if (choice == 5) {
			printf("프로그램 종료\n");
			break;
		}

		switch (choice) {
		case 1: // 예약 확인
			show(ptr);
			printf("\n");
			break;
		case 2: // 예약 하기
			if (isFull(ptr)) {
				printf("현재 예약 인원이 가득 찼습니다. 잠시만 기다려주세요.\n\n");
				break;
			}
			printf("\n휴대폰 번호 뒤 네자리를 입력 >> ");
			scanf("%d", &phone);
			if (append(ptr, phone)) {
				printf("\n예약이 성공적으로 완료되었습니다.\n\n");
				break;
			}
			printf("\n오류가 발생했습니다.\n\n");
			break;
		case 3: // 예약 취소
			printf("\n예약 취소 휴대폰 번호 네자리 >> ");
			scanf("%d", &phone);

			if (removeElement(ptr, phone)) {
				printf("예약 취소 완료\n\n");
			}
			else {
				printf("해당 번호가 존재하지 않습니다.\n\n");
			}
			break;

		case 4: // 내 앞에 대기자가 몇 명 있는지!
			printf("번호 입력 >> ");
			scanf("%d", &phone);

			int waiting = prevCount(ptr, phone);

			if (waiting == -1) {
				printf("번호를 다시 확인해주세요.\n\n");
			}
			else {
				while (1) {
					printf("%04d번님의 정보\n", phone);
					printf("1. 번호 변경\n2. 내 앞 대기자 몇 명인지 확인\n3. 나가기\n");
					printf("메뉴 선택 >> ");
					scanf("%d", &choice);

					if (choice == 3) {
						printf("이전으로 이동합니다.\n\n");
						break;
					}
					else if (choice == 1) { // 번호 변경
						printf("새 번호 입력 >> ");
						scanf("%d", &updatePhone);
						updateByElement(ptr, phone, updatePhone);
						phone = updatePhone;
						printf("변경 완료\n\n");
					}
					else if (choice == 2) {
						printf("%d명이 앞에 대기자로 있습니다.\n\n", waiting);
					}
					else {
						printf("제대로 입력해주세요.\n\n");
					}
				}
			}
			break;
		default:
			printf("다시 입력해주세요\n\n");
		}
	}


	return 0;
}