#include <stdio.h>

int main() {
	int num1 = 20, num2 = 30, num3 = 10;

	printf("---------- ���� ������ ----------\n");
	printf("num1 == num2 : %d\n", num1 == num2);
	printf("num1 != num2 : %d\n", num1 != num2);

	printf("\n---------- �� ������ ----------\n");
	printf("%d\n", num3 > 0 && num3 == 20);
	printf("%d\n", 10 && -5);
	printf("%d\n", 10 && 0);

	printf("\n---------- ���� ������ ----------\n");
	// ���ǽ� ? ���� �� �� : ������ �� ��
	printf("%d\n", num1 == 20 ? num1 * 2 : num1);

	int result = num1 == 20 ? num1 * 2 : num1;

	printf("result : %d\n", result);

}
