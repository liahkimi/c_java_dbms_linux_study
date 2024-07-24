#include <stdio.h>

// 1���� ����ڰ� �Է��� ������ �����ִ� �Լ�
int factorial(int num) {
	int res = 1;
	for (int i = 1; i <= num; i++) {
		res *= i;
	}
	return res;
}

// ��� �Լ��� Ȱ��
int re_fac(int num) {
	if (num == 1) {
		return 1;
	}
	return num * re_fac(num - 1);
}

// [�ǽ�]
// ���� num �� �Է� �޾� �Ʒ��� ���� ó���ϴ� ���α׷��� ������.
// 1. num �� Ȧ���� (3*num)+1 �� ��
// 2. num �� ¦���� num �� 2�� ����
// 3. �̷��� ��� �����ؼ� num �� �ᱹ 1�� �� ������ 1�� 2�� �ݺ��ؼ� ����
// 4. ��� �Լ��� �ۼ�

// ��� ����
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

// ����Լ��� �̿��� �Ǻ���ġ ���� ����
int fibo(int num) {
	if (num == 0) return 0;
	else if (num == 1) return 1;
	else {
		return fibo(num - 2) + fibo(num - 1);
	}
}



int main() {

	printf("factorial(5)�� ��� : %d\n\n", factorial(5));
	printf("re_fac(5)�� ��� : %d\n\n", re_fac(5));
	prac_re(3);
	printf("\n========================\n");
	printf("�Ǻ���ġ ���� �׽�Ʈ!\n");
	printf("%d\n\n", fibo(9));

	for (int i = 0; i < 20; i++) {
		printf("[%d] ", fibo(i));
	}
	printf("\n");

	// �Ǻ���ġ ������ �ݺ��� ���� �����ý��ϴ�.
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