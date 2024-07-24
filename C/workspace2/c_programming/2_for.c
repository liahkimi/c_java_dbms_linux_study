#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i = 10;

	// for문 초기식의 int 선언을 썻다 지웟다 하면서 이해하기!
	// 함수를 만들 때 한 번 더 설명!
	for (int i = 0; i < 3; i++) { // 증감식에 ; 는 쓰지 않는다.
		int data = 49; // for문 안에서 선언한 변수는 for문 안에서만 사용가능.
		printf("for문 내부 i의 값 : %d\n", i);
	}

	// for문의 초기식에서 선언한 변수는 지역변수입니다.
	// for문 실행이 종료되면 메모리에서 해제된다.
	i++;
	printf("for문 외부의 i의 값 : %d\n", i);
	// data; // for문 안에서 선언한 변수는 for문 안에서만 사용가능.

	// for문을 활용한 예제
	printf("\n---------- for문을 활용한 예제 ----------\n");

	// 1. 1부터 5까지의 총합을 for문을 활용하여 구하기
	int sum = 0; // 총합을 저장할 변수

	for (int i = 1; i <= 5; i++) {
		sum += i;
	}

	printf("1부터 5까지의 총합 : %d\n", sum);

	// 2. 1부터 50까지의 값 중에 짝수의 합 구하기
	sum = 0; // 총합을 담아줄 변수, 위에 선언해놓은 변수를 그대로 쓰기위해 0으로 값만 수정.

	//for (int i = 1; i <= 50; i++) {
	//	if (i % 2 == 0) { // i가 짝수라면
	//		sum += i;
	//	}
	//} // 반복횟수 : 50

	//int count = 0;

	//for (int i = 2; i <= 50; i+=2) {
	//	sum += i;
	//	count++;
	//} // 반복횟수 : 25

	//printf("반복횟수 : %d\n", count);
	//printf("1부터 50까지의 짝수의 합 : %d\n", sum);

	//sum = 0;

	//for (int i = 1; i <= 25; i++) {
	//	sum += i * 2;
	//} // 반복횟수 : 25번

	//printf("1부터 50까지의 짝수의 합 : %d\n", sum);

	//sum = 0;

	//for (int i = 1; i <= 50; i++) {
	//	if (i % 2 == 1) { // i 가 홀수라면
	//		continue; // 즉시 다음 반복 실행
	//	}
	//	sum += i;
	//}
	//printf("1부터 50까지의 짝수의 합 : %d\n", sum);

	// 3. 10부터 1까지 숫자, 가로로 이쁘게 출력하기
	//for (int i = 10; i >= 1; i--) {
	//	printf("%d ", i);
	//}

	//for (int i = 0; i < 10; i++) {
	//	printf("%d ", 10 - i);
	//}


	printf("\n---------- for문을 활용한 구구단 문제 ----------\n");

	// 원하는 단을 입력 받은 후, 해당 단을 출력하기
	int dan;
	printf("보고 싶은 단 : ");
	scanf("%d", &dan);

	printf("===== %d단 =====\n", dan);

	for (int i = 0; i < 9; i++) {
		printf("%d * %d = %2d\n", dan, i + 1, dan * (i + 1));
	}

	//printf("%d * %d = %d\n", dan, 1, dan * 1);
	//printf("%d * %d = %d\n", dan, 2, dan * 2);
	//printf("%d * %d = %d\n", dan, 3, dan * 3);
	//printf("%d * %d = %d\n", dan, 4, dan * 4);
	//printf("%d * %d = %d\n", dan, 5, dan * 5);
	//printf("%d * %d = %d\n", dan, 6, dan * 6);
	//printf("%d * %d = %d\n", dan, 7, dan * 7);
	//printf("%d * %d = %d\n", dan, 8, dan * 8);
	//printf("%d * %d = %d\n", dan, 9, dan * 9);


	return 0;
}