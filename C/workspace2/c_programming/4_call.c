#include <stdio.h>

void change1(int data1) {
	data1 = 100;
}

void change2(int* data1) {
	*data1 = 555;
}

// 변수 속에 들어있는 값을 서로 변경하는 함수
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
	printf("변경 전 data1 : %d\n", data1);
	change1(data1);
	printf("변경 후 data1 : %d\n", data1);

	int a = 3;
	int b = 45;
	printf("변경 전 a : %d,  b : %d\n", a, b);
	swapNumber1(a, b);
	printf("변경 후 a : %d,  b : %d\n", a, b);

	printf("\n========== Call By Reference ==========\n");
	int data2 = 22;
	printf("변경 전 data2 : %d\n", data2);
	change2(&data2);
	printf("변경 후 data2 : %d\n", data2);

	int c = 3;
	int d = 45;
	printf("변경 전 c : %d,  d : %d\n", c, d);
	swapNumber2(&c, &d);
	printf("변경 후 c : %d,  d : %d\n", c, d);
}