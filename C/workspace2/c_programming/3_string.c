#include <stdio.h>

int main() {
	// 문자열 선언 방식 1.
	char str1[] = "hello"; // 포인터 상수
	//str1 = "bye"; // 포인터 상수이기에 주소 변경 불가능!
	str1[0] = 'K';

	// 문자열 선언 방식 2
	char* str2 = "hellobyebye"; // 상수 포인터
	// str2[1] = 'K'; //주소로 접근해서 다른 값으로 변경이 불가능하다.
	printf("str2 : %s\n", str2);

	printf("str2의 수정 전 주소 : %d\n", str2);
	str2 = "goodNight"; // 가능
	printf("str2의 수정 후 주소 : %d\n", str2);

	// 정리!
	// 문자열을 선언할 때

	// 1. 배열 형식으로 선언하면 요소는 바꿀 수 있지만, 전체는 바꿀 수 없다.
	// 2. 포인터 형식으로 선언하면 요소를 바꿀 수 없지만, 전체는 바꿀 수 있다.

	return 0;
}