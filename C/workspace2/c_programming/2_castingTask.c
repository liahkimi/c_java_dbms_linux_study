#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	/*
	������ �Է� �޾Ƽ� �ش� ������ ���� �ڸ��� ���� �ڸ� ����ϱ�

	�Է� ���� : 10

	��� ����
			���� �ڸ� : 1
			���� �ڸ� : 0
	*/
	printf("\n---------- 1�� ���� ----------\n");
	// ����� ������ ����ο� ���Ƽ�.
	// �Է��� ������ �������� ����.
	int num;
	printf("���� �ڸ� ������ �Է� >> ");
	scanf("%d", &num);

	printf("���� �ڸ� : %d\n���� �ڸ� : %d\n", num / 10, num % 10);

	/*
	�뷡 �� ��� 300���� ���� �뷡�濡��
	����ڿ��� �ݾ��� �Է� �ް�, �θ� �� �ִ� �뷡�� �� ���� ����ϱ�

	�Է� ����
			�ݾ� �Է� >> 1600

	��� ����
			�θ� �� �ִ� �뷡�� 5���̸�, �ܵ��� 100���Դϴ�.

	*/
	printf("\n---------- 2�� ���� ----------\n");
	int money;
	int cost = 300;
	printf("�ݾ� �Է� >> ");
	scanf("%d", &money);

	printf("�θ� �� �ִ� �뷡�� %d���̸� �ܵ��� %d���Դϴ�.\n", money / cost, money % cost);



	/*
	���� �� ���� �Է� �޾�
	������ �Ʒ� ��° �ڸ����� ����� ����ϱ�.

	*/
	printf("\n---------- 3�� ���� ----------\n");
	int num1, num2, num3;
	double avg;

	printf("�� ���� ������ ���� �Ǵ� �����̽��ٸ� �������� �Է��ϼ���.\n");
	scanf("%d%d%d", &num1, &num2, &num3);

	avg = (num1 + num2 + num3) / (double)3;

	printf("�� ������ ����� %.2lf�Դϴ�.\n", avg);



	return 0;
}