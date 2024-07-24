#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char input[100];
	char u_input[100];
	printf("문자열 입력 >> ");
	scanf("%s", input);
	printf("입력된 값 : %s\n", input);

	// input에 입력된 영어를 대문자는 소문자로, 소문자는 대문자로
	// 나머지(정수, 특수문자 등등)는 그대로 출력하는 프로그램 만들기!

	// for
	printf("변환된 값 : ");
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 65 && input[i] <= 90) { // 대문자라면
			printf("%c", input[i] + 32);
		}
		else if (input[i] >= 97 && input[i] <= 122) { // 소문자라면
			printf("%c", input[i] - 32);
		}
		else {
			printf("%c", input[i]);
		}
	}



	// while
	printf("\n변환된 값 : ");
	int i = 0;
	while (input[i] != '\0') {
		if (input[i] >= 65 && input[i] <= 90) { // 대문자라면
			printf("%c", input[i] + 32);
		}
		else if (input[i] >= 97 && input[i] <= 122) { // 소문자라면
			printf("%c", input[i] - 32);
		}
		else {
			printf("%c", input[i]);
		}
		i++;
	}

	// u_input 문자열에 변환된 값이 들어가도록 하기.
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 65 && input[i] <= 90) { // 대문자라면
			u_input[i] = input[i] + 32;
		}
		else if (input[i] >= 97 && input[i] <= 122) { // 소문자라면
			u_input[i] = input[i] - 32;
		}
		else {
			u_input[i] = input[i];
		}
		// 반복이 돌 때 마다 항상 검사를 하기에, 비추천.
		//if (i == strlen(input) - 1) {
		//	u_input[i + 1] = '\0';
		//}
	}
	u_input[strlen(input)] = '\0';

	printf("\n변환된 값 : %s\n", u_input);

	return 0;
}