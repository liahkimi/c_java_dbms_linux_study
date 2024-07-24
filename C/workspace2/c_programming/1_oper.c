#include <stdio.h>

int main() {
	// 복합대입연산자

	int num = 49;
	int data = 10;

	num += 5;

	// 대입 연산자는 연산의 결과 자체를 값으로서 가진다.
	//printf("num : %d\n", num = 3);
	//printf("num : %d\n", num);

	// 후위형
	printf("num++ : %d\n", num++);
	printf("num : %d\n\n", num);

	// 전위형
	printf("++num : %d\n", ++num);
	printf("num : %d\n\n", num);

	// 전위형을 잘 모른다하더라도 상관없다.

	//data++;
	//printf("연산의 결과 : %d\n", data + 10);

	// 전위형을 알고있으면 이런 모양도 가능.
	printf("연산의 결과 : %d\n", ++data + 10);
	printf("data : %d\n", data);



	return 0;
}