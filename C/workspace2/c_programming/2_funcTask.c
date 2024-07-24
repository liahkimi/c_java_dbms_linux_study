#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// [실습]
// 사용자에게 정수를 입력 받아서 해당 정수가
// 짝수인지 홀수인지 판별하는 함수
// 리턴은 짝수이면 1 리턴, 홀수이면 0 리턴
// if문을 활용해서 main 함수에서 테스트까지 진행!
int isEven(int num) {
	return num % 2 == 0 ? 1 : 0;
}

int main() {
	int num;

	while (1) {
		printf("정수 입력 >> ");
		scanf("%d", &num);

		if (num == 0) {
			printf("프로그램 종료");
			break;
		}

		if (isEven(num)) {
			printf("짝수!\n");
		}
		else {
			printf("홀수!\n");
		}
	}




	return 0;
}