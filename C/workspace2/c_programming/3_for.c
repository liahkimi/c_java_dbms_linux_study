#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// 중첩 for문
	// for문 안에 for문이 있다.
	//for (int out = 0; out < 3; out++) {
	//	printf("현재 out : %d\n", out);
	//	for (int in = 0; in < 4; in++) {
	//		printf("현재 in : %d\n", in);
	//	}
	//}

	// 2단 ~ 9단까지 구구단 출력
	// 1. 쉬운 버전
	for (int dan = 2; dan <= 9; dan++) {
		printf("=== %d단 ===\n", dan);
		for (int i = 1; i <= 9; i++) {
			printf("%d * %d = %d\n", dan, i, dan * i);
		}
		printf("\n");
	}

	// 2. 어려운 버전

	// 아스코 코드 활용!
	// 반복문 활용!
	printf("\n---------- 심화 예제 ----------\n");

	// A B C D E F <-- 딱 이 모양 콘솔 창에 출력!
	for (int i = 0; i < 6; i++) {
		printf("%c ", i + 65);
	}

	printf("\n");

	for (char i = 'A'; i <= 'F'; i++) {
		printf("%c ", i);
	}
	printf("\n");

	// A B D E F <-- 이 모양 콘솔 창에 출력!
	for (char i = 'A'; i <= 'F'; i++) {
		if (i != 'C') {
			printf("%c ", i);
		}
	}
	printf("\n");

	for (char i = 'A'; i <= 'F'; i++) {
		if (i == 'C') {
			continue;
		}
		printf("%c ", i);
	}

	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("%c ", i > 1 ? i + 66 : i + 65);
	}

	return 0;
}