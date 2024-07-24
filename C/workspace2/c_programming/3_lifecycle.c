#include <stdio.h>

// ��������
int global = 0;

void f1() {
	global = 333;
	printf("f1 ������ global ��� : %d\n", global);
};

void f2(int num) { // �������� test
	num = 100;
	printf("f2 �Լ��� num : %d\n", num);
}

// ����ƽ ����
void f3() {
	static int data = 100;
	data++;
	printf("���� data : %d\n", data);
}

int main() {
	// �������� : ��𿡼��� ������ ���� (������ ����).
	printf("\n ===== ���� ���� =====\n");
	printf("�������� global : %d\n", global);
	f1();
	printf("�������� global : %d\n", global);

	// �������� : ���� ���簡 �Ǿ� ���� ��!
	printf("\n ===== ���� ���� =====\n");

	int num = 49;
	f2(num);
	printf("���� �Լ� ���� num : %d\n", num);

	printf("\n ===== ����ƽ ���� =====\n");
	f3();
	f3();

	// ����ƽ ������ �ܺο����� ���� �Ұ�!
	/*printf("%d\n", data);*/

	return 0;
}