#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// [�ǽ�]
// ����ڿ��� ������ �Է� �޾Ƽ� �ش� ������
// ¦������ Ȧ������ �Ǻ��ϴ� �Լ�
// ������ ¦���̸� 1 ����, Ȧ���̸� 0 ����
// if���� Ȱ���ؼ� main �Լ����� �׽�Ʈ���� ����!
int isEven(int num) {
	return num % 2 == 0 ? 1 : 0;
}

int main() {
	int num;

	while (1) {
		printf("���� �Է� >> ");
		scanf("%d", &num);

		if (num == 0) {
			printf("���α׷� ����");
			break;
		}

		if (isEven(num)) {
			printf("¦��!\n");
		}
		else {
			printf("Ȧ��!\n");
		}
	}




	return 0;
}