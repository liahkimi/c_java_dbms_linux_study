#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 정수를 하나 입력 받아
	// 0인지, 홀수인지, 짝수인지를 판단하는 프로그램
	int data;
	int num = 10;
	printf("정수 하나 입력 >> ");
	scanf("%d", &data);

	if (data == 0) {
		num = 100;
		printf("0을 입력했습니다.");
	}
	else if (data % 2 != 0) {
		printf("홀수 입니다.");
	}
	else {
		printf("짝수 입니다.");
	}

	printf("num : %d", num);


	return 0;
}