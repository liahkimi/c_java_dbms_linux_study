#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 키를 cm 단위로 입력 받아 m 단위로 환산하여
// 출력해주는 함수 작성.
void convertCentiToMeter1(int height) {
	printf("결과 : %.2lfm\n", height / 100.0);
}

double convertCentiToMeter2(int height) {
	return height / 100.0;
}

int main() {
	int height;
	printf("키를 cm 단위로 입력하세요 >> ");
	scanf("%d", &height);
	convertCentiToMeter1(height);
	printf("결과 : %.2lfm\n", convertCentiToMeter2(height));

	return 0;
}