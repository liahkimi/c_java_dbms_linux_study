#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Ű�� cm ������ �Է� �޾� m ������ ȯ���Ͽ�
// ������ִ� �Լ� �ۼ�.
void convertCentiToMeter1(int height) {
	printf("��� : %.2lfm\n", height / 100.0);
}

double convertCentiToMeter2(int height) {
	return height / 100.0;
}

int main() {
	int height;
	printf("Ű�� cm ������ �Է��ϼ��� >> ");
	scanf("%d", &height);
	convertCentiToMeter1(height);
	printf("��� : %.2lfm\n", convertCentiToMeter2(height));

	return 0;
}