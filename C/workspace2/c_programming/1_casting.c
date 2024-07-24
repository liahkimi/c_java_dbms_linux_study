#include <stdio.h>

int main() {
	// int 연산자 int
	// 정수와 정수의 연산의 결과는 항상 정수이다.
	printf("------- int 연산자 int -------\n");
	printf("%d\n", 10 + 3);
	printf("%d\n", 10 / 3);

	// int 연산자 char
	printf("\n------- int 연산자 char -------\n");
	printf("%d\n", 10 + 'a');

	// 1byte 로 표현할 수 있는 정수는 char 로 사용가능.
	printf("%c\n", 10 + 'a');

	// 1byte 범위를 초과하면 ? 가 뜬다.
	printf("%c\n", 100 + 'a');

	// int 연산자 double
	// 정수와 실수의 연산 결과는 double 이다.
	printf("\n------- int 연산자 double -------\n");
	printf("%lf\n", (double)10 / 3); // 10이 10.0 으로 강제형변환이 먼저된다.
	printf("%lf\n", 10 / 3 + 0.0); // 나눗셈 연산이 먼저되고, 그 결과에 0.0을 더하며 자동형변환 했기 때문
	printf("%lf\n", 10 / (3 + 0.0)); // 소괄호는 최우선 연산자! 10 / 3.0 의 결과와 같다

	// 0 division error
	//printf("%d\n", 5 / 0);
	//printf("%lf\n", 5 / 0.0);

	// 나머지 연산자 %
	printf("\n------- 나머지 연산자 -------\n");
	printf("10을 3으로 나눈 나머지 : %d\n", 10 % 3);

	return 0;
}