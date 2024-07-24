#include <stdio.h>

// 1부터 사용자가 입력한 값까지 곱해주는 함수
int factorial(int num) {
	int res = 1;
	for (int i = 1; i <= num; i++) {
		res *= i;
	}
	return res;
}

// 재귀 함수를 활용
int re_fac(int num) {
	if (num == 1) {
		return 1;
	}
	return num * re_fac(num - 1);
}

// [실습]
// 정수 num 을 입력 받아 아래와 같이 처리하는 프로그램을 만들어보자.
// 1. num 이 홀수면 (3*num)+1 을 함
// 2. num 이 짝수면 num 을 2로 나눔
// 3. 이렇게 계속 진행해서 num 이 결국 1이 될 때까지 1과 2를 반복해서 실행
// 4. 재귀 함수로 작성

// 출력 예시
// 3
// 10
// 5
// 16
// 8
// 4
// 2
// 1
int prac_re(int num) {
	printf("%d\n", num);

	if (num == 1) return;
	if (num % 2 == 1) {
		return prac_re((3 * num) + 1);
	}
	else {
		return prac_re(num / 2);
	}
}

// 재귀함수를 이용한 피보나치 수열 구현
int fibo(int num) {
	if (num == 0) return 0;
	else if (num == 1) return 1;
	else {
		return fibo(num - 2) + fibo(num - 1);
	}
}



int main() {

	printf("factorial(5)의 결과 : %d\n\n", factorial(5));
	printf("re_fac(5)의 결과 : %d\n\n", re_fac(5));
	prac_re(3);
	printf("\n========================\n");
	printf("피보나치 수열 테스트!\n");
	printf("%d\n\n", fibo(9));

	for (int i = 0; i < 20; i++) {
		printf("[%d] ", fibo(i));
	}
	printf("\n");

	// 피보나치 수열을 반복문 없이 만들어봤습니다.
	int idx = 20;
	int temp1 = 0, temp2 = 1, temp3;
	for (int i = 0; i < 20; i++) {
		printf("[%d] ", temp1);
		temp3 = temp1 + temp2;
		temp1 = temp2;
		temp2 = temp3;
	}

	return 0;
}