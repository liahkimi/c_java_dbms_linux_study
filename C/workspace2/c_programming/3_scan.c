#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// & �ּҿ�����
	//int num;
	//printf("num�� �ּҰ��� %p\n", &num);

	// ����ڿ��� �Է� �޴� �Լ��� �������.
	int data1, data2;
	printf("����1 �Է� >> ");
	scanf("%d", &data1);

	printf("����2 �Է� >> ");
	scanf("%d", &data2);

	printf("data1 �� �� : %d\n", data1);
	printf("data2 �� �� : %d\n", data2);

	//printf("�� ������ �����̽��ٸ� �������� �ΰ� �Է� >> ");
	//scanf("%d %d", &data1, &data2);
	//printf("data1 : %d  data2 : %d\n", data1, data2);

	return 0;