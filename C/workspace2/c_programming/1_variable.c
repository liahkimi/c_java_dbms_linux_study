r#include <stdio.h>

int main() {

	int num1; // 변수의 선언.
	num1 = 49; // 변수 초기화

	printf("num1 변수에 저장된 값은 %d 입니다.\n", num1);

	// 같은 자료형의 변수를 한 번에 선언하면서 초기화도 할 때
	// 같은 값으로 초기화한다하더라도 각각 명시해줘야한다.
	int data1, data2 = 10;
	// 초기화 되지 않은 변수를 사용했기에 실행되지 않음.
	//printf("data1 변수에 저장된 값은 %d 입니다.\n", data1);

	return 0;
}