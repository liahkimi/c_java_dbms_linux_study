#include <stdio.h>

int main() {
	// ���մ��Կ�����

	int num = 49;
	int data = 10;

	num += 5;

	// ���� �����ڴ� ������ ��� ��ü�� �����μ� ������.
	//printf("num : %d\n", num = 3);
	//printf("num : %d\n", num);

	// ������
	printf("num++ : %d\n", num++);
	printf("num : %d\n\n", num);

	// ������
	printf("++num : %d\n", ++num);
	printf("num : %d\n\n", num);

	// �������� �� �𸥴��ϴ��� �������.

	//data++;
	//printf("������ ��� : %d\n", data + 10);

	// �������� �˰������� �̷� ��絵 ����.
	printf("������ ��� : %d\n", ++data + 10);
	printf("data : %d\n", data);



	return 0;
}