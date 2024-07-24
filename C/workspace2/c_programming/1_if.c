#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	//printf("if문 위의 문장\n");

	//if (0) {
	//	printf("if문 내의 문장1\n");
	//	printf("if문 내의 문장2\n");
	//}

	//printf("if문 아래 문장\n");

	// if, else문
	//int num;
	//printf("정수 입력 >> ");
	//scanf("%d", &num);

	// 조건이 하나일 때
	//if (num >= 10) { // 해당 조건이 참일 때
	//	printf("10번 대 숫자를 입력했군요.\n");
	//}
	//else { // 해당 조건이 거짓일 때
	//	printf("10번 대 말구 다른 숫자를 입력했군요.\n");
	//}

	// 조건이 두 개 이상 일 때
	// if, else if, else 문
	//if (num >= 10 && num < 20) {
	//	printf("10번 대 숫자를 입력했군요.\n");
	//}
	//else if (num >= 20 && num < 30) {
	//	printf("20번 대 숫자를 입력했군요.\n");
	//}
	//else if (num >= 30 && num < 40) {
	//	printf("30번 대 숫자를 입력했군요.\n");
	//}
	//else {
	//	printf("10, 20, 30번 대 말고 다른 숫자를 입력했군요!");
	//}

	// 하나만 더!
	// 나이를 입력 받아, 성인인지, 청소년인지, 유아, 신생아 인지를 판단하는 프로그램.
	//int age;
	//printf("나이 입력 >> ");
	//scanf("%d", &age);

	//if (age > 19) {
	//	printf("성인 입니다.");
	//}
	//if (age > 14) {
	//	printf("청소년 입니다.");
	//}
	//if (age < 14 && age > 2) {
	//	printf("유아 입니다.");
	//}
	//if (age < 2 && age > 0) {
	//	printf("신생아 입니다.");
	//}

	//if (age > 19) {
	//	printf("성인 입니다.");
	//}
	//// 위의 조건식에서 이미 19 초과가 아니란 걸 검사하고 내려왔기에 다시 한 번 검사할 필요는 없다.
	//else if (age > 14) { 
	//	printf("청소년 입니다.");
	//}
	//else if (age > 2) {
	//	printf("유아 입니다.");
	//}
	//else {
	//	printf("신생아 입니다.");
	//}

	// day03 메모장 하단, 과제 풀이
	//	정수를 입력해서 십의 자리 정수를 입력했다면
	//	십의 자리 : 9
	//	일의 자리 : 1

	//	백의 자리 정수를 입력했다면
	//	백의 자리 : 1
	//	십의 자리 : 3
	//	일의 자리 : 4

	//	이렇게 나오게 하기. (천의 자리, 만의 자리는 구현하지 않아도 된다.)

	int data;
	int temp;
	printf("정수 입력 >> ");
	scanf("%d", &data);

	temp = data / 10;

	//if (data >= 10 && data < 100) {
	if (temp >= 10) {
		printf("백의 자리 : %d\n", data / 100);
		printf("십의 자리 : %d\n", (data % 100) / 10);
		printf("일의 자리 : %d\n", data % 10);
	}
	//else if (data >= 100 && data < 1000) {
	else if (temp >= 1) {
		printf("십의 자리 : %d\n", data / 10);
		printf("일의 자리 : %d\n", data % 10);
	}
	else {
		printf("10, 100 자리의 정수만 입력하세요!");
	}


	return 0;
}