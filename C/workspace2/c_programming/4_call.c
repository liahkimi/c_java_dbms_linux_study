#include <stdio.h>

void change1(int data1) {
	data1 = 100;
}

void change2(int* data1) {
	*data1 = 555;
}

// ���� �ӿ� ����ִ� ���� ���� �����ϴ� �Լ�
void swapNumber1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapNumber2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main() {
	printf("\n========== Call By Value ==========\n");
	int data1 = 22;
	printf("���� �� data1 : %d\n", data1);
	change1(data1);
	printf("���� �� data1 : %d\n", data1);

	int a = 3;
	int b = 45;
	printf("���� �� a : %d,  b : %d\n", a, b);
	swapNumber1(a, b);
	printf("���� �� a : %d,  b : %d\n", a, b);

	printf("\n========== Call By Reference ==========\n");
	int data2 = 22;
	printf("���� �� data2 : %d\n", data2);
	change2(&data2);
	printf("���� �� data2 : %d\n", data2);

	int c = 3;
	int d = 45;
	printf("���� �� c : %d,  d : %d\n", c, d);
	swapNumber2(&c, &d);
	printf("���� �� c : %d,  d : %d\n", c, d);
}