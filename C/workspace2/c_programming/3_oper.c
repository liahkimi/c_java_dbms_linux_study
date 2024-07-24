#include <stdio.h>

int main() {
	int num1 = 20, num2 = 30, num3 = 10;

	printf("---------- 관계 연산자 ----------\n");
	printf("num1 == num2 : %d\n", num1 == num2);
	printf("num1 != num2 : %d\n", num1 != num2);

	printf("\n---------- 논리 연산자 ----------\n");
	printf("%d\n", num3 > 0 && num3 == 20);
	printf("%d\n", 10 && -5);
	printf("%d\n", 10 && 0);

	printf("\n---------- 삼항 연산자 ----------\n");
	// 조건식 ? 참일 때 값 : 거짓일 때 값
	printf("%d\n", num1 == 20 ? num1 * 2 : num1);

	int result = num1 == 20 ? num1 * 2 : num1;

	printf("result : %d\n", result);

}
