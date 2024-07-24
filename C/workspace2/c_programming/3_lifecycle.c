#include <stdio.h>

// 전역변수
int global = 0;

void f1() {
	global = 333;
	printf("f1 내에서 global 출력 : %d\n", global);
};

void f2(int num) { // 지역변수 test
	num = 100;
	printf("f2 함수의 num : %d\n", num);
}

// 스태틱 변수
void f3() {
	static int data = 100;
	data++;
	printf("현재 data : %d\n", data);
}

int main() {
	// 전역변수 : 어디에서든 접근이 가능 (수정도 가능).
	printf("\n ===== 전역 변수 =====\n");
	printf("전역변수 global : %d\n", global);
	f1();
	printf("전역변수 global : %d\n", global);

	// 지역변수 : 값이 복사가 되어 들어갔을 뿐!
	printf("\n ===== 지역 변수 =====\n");

	int num = 49;
	f2(num);
	printf("메인 함수 내의 num : %d\n", num);

	printf("\n ===== 스태틱 변수 =====\n");
	f3();
	f3();

	// 스태틱 변수도 외부에서는 접근 불가!
	/*printf("%d\n", data);*/

	return 0;
}