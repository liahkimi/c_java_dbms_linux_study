#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// 날짜를 입력 받아 출력하는 프로그램을 간단히 만들어보자.
	// 변수의 선언은 영역 상단부에 몰아서 한다.
	//int month, day;

	//printf("오늘은 몇 월 >> ");
	//scanf("%d", &month);

	//printf("오늘은 몇 일 >> ");
	//scanf("%d", &day);

	//printf("오늘은 %02d월 %d일 입니다.\n", month, day);


	// 현재 기온을 입력받아 출력하는 프로그램을 만들어보자.
	// 소수점 첫째자리까지만 표현.
	double tem;

	printf("현재 기온 입력 >> ");
	scanf("%lf", &tem);

	// 자릿수가 넘으면 반올림되어서 잘린다.
	printf("현재 기온 : %.1lf도\n", tem);

	// 플러스 알파
	printf("현재 기온 : %d도\n", tem);




	return 0;
}