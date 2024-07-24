#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num = 5;

	switch (num) {
	case 10:
		printf("num�� ����� ���� 10�Դϴ�.\n");
		// if���� ������ ���� ����� �߰�ȣ ������ Ż��.
	case 7:
		printf("num�� ����� ���� 7�Դϴ�.\n");
		break;
	case 5:
		printf("num�� ����� ���� 5�Դϴ�.\n");
		break;
	case 3:
		printf("num�� ����� ���� 3�Դϴ�.\n");
		break;
	case 1:
		printf("num�� ����� ���� 1�Դϴ�.\n");
		break;
	default:
		printf("�� �ܿ� �� �Դϴ�.");
		// break �ʿ� ����. ������ ������ ���� ����!
	}

	printf("\n---------- switch �ǽ� ----------\n");

	/*
		����ڿ��� ����, ����, ���� ������ �Է� �޾�
		����� ���ϰ� �Ҽ��� ��°�ڸ� ���� ����Ѵ�.
		�� ���� �ٷ� ������ ������ ����ϴ� ���α׷��� �ۼ�������.
		���� : ��տ� ���� ���´�!
		90 �̻��̶�� A����
		80 �̻� 90 �̸��̶�� B����
		70 �̻� 80 �̸��̶�� C����
		70 �̸��̶�� F����

		�Է� ���� :
		������ ���� �Է� >> 80, 90, 100

		��� ���� :
		��� : 90.00
		���� : A
	*/
	int kor, eng, math;
	double avg;
	char grade;

	printf("������ ���� �Է� >> ");
	scanf("%d %d %d", &kor, &eng, &math);

	avg = (kor + eng + math) / 3.0;

	switch ((int)avg / 10) {
	case 10: // 10�� ��, 9�� �� ��� ����
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	default:
		grade = 'F';
	}

	printf("��� : %.2lf\n���� : %c", avg, grade);



	return 0;
}