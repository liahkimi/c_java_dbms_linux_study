#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// ������ �ϳ� �Է� �޾�
	// 0����, Ȧ������, ¦�������� �Ǵ��ϴ� ���α׷�
	int data;
	int num = 10;
	printf("���� �ϳ� �Է� >> ");
	scanf("%d", &data);

	if (data == 0) {
		num = 100;
		printf("0�� �Է��߽��ϴ�.");
	}
	else if (data % 2 != 0) {
		printf("Ȧ�� �Դϴ�.");
	}
	else {
		printf("¦�� �Դϴ�.");
	}

	printf("num : %d", num);


	return 0;
}