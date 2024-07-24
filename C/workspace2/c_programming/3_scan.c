#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// & 주소연산자
	//int num;
	//printf("num의 주소값은 %p\n", &num);

	// 사용자에게 입력 받는 함수를 배워보자.
	int data1, data2;
	printf("정수1 입력 >> ");
	scanf("%d", &data1);

	printf("정수2 입력 >> ");
	scanf("%d", &data2);

	printf("data1 의 값 : %d\n", data1);
	printf("data2 의 값 : %d\n", data2);

	//printf("두 정수를 스페이스바를 기준으로 두개 입력 >> ");
	//scanf("%d %d", &data1, &data2);
	//printf("data1 : %d  data2 : %d\n", data1, data2);

	return 0;