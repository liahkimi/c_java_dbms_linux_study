#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �Ű������� �Ѿ�� number ~ number + 200����
// 7�� ����� �� �� ������ �����ϴ� �Լ�
int howManySeven(int number) {
	int count = 0;
	for (int i = number; i <= number + 200; i++) {
		if (i % 7 != 0) {
			continue;
		}
		count++;
	}
	return count;
}

// �Ű������� �Ѿ�� number ~ number + 200����
// �Ű������� �Ѿ�� ������ ����� �� �� ������ �����ϴ� �Լ�
int howMany(int number1, int number2) {
	int count = 0;
	for (int i = number1; i <= number1 + 200; i++) {
		if (i % number2 != 0) {
			continue;
		}
		count++;
	}
	return count;
}

int main() {
	//int number;
	//printf("���� �ϳ��� �Է��ϼ��� : ");
	//scanf("%d", &number);
	//printf("%d�� %d ���̿� 7�� ����� %d���Դϴ�.\n", number, 
	// number+200, howManySeven(number));

	int number1, number2;
	printf("���� �ϳ��� �Է��ϼ��� : ");
	scanf("%d", &number1);
	printf("���� ��� >> ");
	scanf("%d", &number2);
	printf("%d�� %d ���̿� %d�� ����� %d���Դϴ�.\n", number1, number1 + 200, number2,
		howMany(number1, number2));
}