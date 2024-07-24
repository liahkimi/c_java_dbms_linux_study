#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	/*
	정수를 입력 받아서 해당 정수의 십의 자리와 일의 자리 출력하기

	입력 예시 : 10

	출력 예시
			십의 자리 : 1
			일의 자리 : 0
	*/
	printf("\n---------- 1번 문제 ----------\n");
	// 사용할 변수는 선언부에 몰아서.
	// 입력한 정수를 저장해줄 변수.
	int num;
	printf("십의 자리 정수를 입력 >> ");
	scanf("%d", &num);

	printf("십의 자리 : %d\n일의 자리 : %d\n", num / 10, num % 10);

	/*
	노래 한 곡당 300원인 코인 노래방에서
	사용자에게 금액을 입력 받고, 부를 수 있는 노래와 잔 돈을 출력하기

	입력 예시
			금액 입력 >> 1600

	출력 예시
			부를 수 있는 노래는 5곡이며, 잔돈은 100원입니다.

	*/
	printf("\n---------- 2번 문제 ----------\n");
	int money;
	int cost = 300;
	printf("금액 입력 >> ");
	scanf("%d", &money);

	printf("부를 수 있는 노래는 %d곡이며 잔돈은 %d원입니다.\n", money / cost, money % cost);



	/*
	정수 세 개를 입력 받아
	소주점 아래 둘째 자리까지 평균을 출력하기.

	*/
	printf("\n---------- 3번 문제 ----------\n");
	int num1, num2, num3;
	double avg;

	printf("세 개의 정수를 엔터 또는 스페이스바를 기준으로 입력하세요.\n");
	scanf("%d%d%d", &num1, &num2, &num3);

	avg = (num1 + num2 + num3) / (double)3;

	printf("세 정수의 평균은 %.2lf입니다.\n", avg);



	return 0;
}