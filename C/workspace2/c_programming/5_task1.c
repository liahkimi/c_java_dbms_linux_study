#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 매개변수로 넘어온 number ~ number + 200까지
// 7의 배수가 몇 개 인지를 리턴하는 함수
int howManySeven(int number) {
	int count = 0;
	for (int i = number; i <= number + 200; i++) {
		if (i % 7 != 0) {
			continue;
		}
		count++;
	}
	return count;
}

// 매개변수로 넘어온 number ~ number + 200까지
// 매개변수로 넘어논 정수의 배수가 몇 개 인지를 리턴하는 함수
int howMany(int number1, int number2) {
	int count = 0;
	for (int i = number1; i <= number1 + 200; i++) {
		if (i % number2 != 0) {
			continue;
		}
		count++;
	}
	return count;
}

int main() {
	//int number;
	//printf("정수 하나를 입력하세요 : ");
	//scanf("%d", &number);
	//printf("%d와 %d 사이에 7의 배수는 %d개입니다.\n", number, 
	// number+200, howManySeven(number));

	int number1, number2;
	printf("정수 하나를 입력하세요 : ");
	scanf("%d", &number1);
	printf("몇의 배수 >> ");
	scanf("%d", &number2);
	printf("%d와 %d 사이에 %d의 배수는 %d개입니다.\n", number1, number1 + 200, number2,
		howMany(number1, number2));
}