#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// ��¥�� �Է� �޾� ����ϴ� ���α׷��� ������ ������.
	// ������ ������ ���� ��ܺο� ���Ƽ� �Ѵ�.
	//int month, day;

	//printf("������ �� �� >> ");
	//scanf("%d", &month);

	//printf("������ �� �� >> ");
	//scanf("%d", &day);

	//printf("������ %02d�� %d�� �Դϴ�.\n", month, day);


	// ���� ����� �Է¹޾� ����ϴ� ���α׷��� ������.
	// �Ҽ��� ù°�ڸ������� ǥ��.
	double tem;

	printf("���� ��� �Է� >> ");
	scanf("%lf", &tem);

	// �ڸ����� ������ �ݿø��Ǿ �߸���.
	printf("���� ��� : %.1lf��\n", tem);

	// �÷��� ����
	printf("���� ��� : %d��\n", tem);




	return 0;
}