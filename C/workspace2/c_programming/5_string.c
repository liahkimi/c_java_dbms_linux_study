#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	// strcmp(문자열, 문자열2);
	// 문자열1과 문자열2가 같다면 0
	// 문자열1이 문자열2보다 아스키코드값이 빠르다면 -1
	// 문자열1이 문자열2보다 아스키코드값이 느리다면 1
	printf("%d\n", strcmp("류호근", "김수현"));
	printf("%d\n", strcmp("apple", "apple"));
	printf("%d\n", strcmp("apple", "banana"));
	printf("%d\n", strcmp("banana", "apple"));

	// strcat(변수명, 문자열 값)
	// 해당 변수에 들어있는 문자열과 뒤에 전달해준 문자열을
	// 연결해서 해당 변수에 저장해준다.

	// 연결해준 이 후에 칸수를 벗어난다면 동작하지 않는다.
	char temp[11] = "I'm ";
	strcat(temp, "hungry");
	printf("결과 : %s\n", temp);
	printf("결과 길이 : %d\n", strlen(temp));

	return 0;