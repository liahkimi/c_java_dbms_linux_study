#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// ��ø for��
	// for�� �ȿ� for���� �ִ�.
	//for (int out = 0; out < 3; out++) {
	//	printf("���� out : %d\n", out);
	//	for (int in = 0; in < 4; in++) {
	//		printf("���� in : %d\n", in);
	//	}
	//}

	// 2�� ~ 9�ܱ��� ������ ���
	// 1. ���� ����
	for (int dan = 2; dan <= 9; dan++) {
		printf("=== %d�� ===\n", dan);
		for (int i = 1; i <= 9; i++) {
			printf("%d * %d = %d\n", dan, i, dan * i);
		}
		printf("\n");
	}

	// 2. ����� ����

	// �ƽ��� �ڵ� Ȱ��!
	// �ݺ��� Ȱ��!
	printf("\n---------- ��ȭ ���� ----------\n");

	// A B C D E F <-- �� �� ��� �ܼ� â�� ���!
	for (int i = 0; i < 6; i++) {
		printf("%c ", i + 65);
	}

	printf("\n");

	for (char i = 'A'; i <= 'F'; i++) {
		printf("%c ", i);
	}
	printf("\n");

	// A B D E F <-- �� ��� �ܼ� â�� ���!
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