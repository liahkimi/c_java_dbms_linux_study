#include <stdio.h>

//함수의 선언과 사용 

//리턴이 있는 리턴함수
int add(int a, int b) {
	int sum = a + b;
	return sum;//값
	//함수 호출이 종료되면 사용했던 변수는 전부 메모리에서 해제된다.}

	//리턴이 없는 실행함수
	void add2(int a, int b) {
		//리턴이 있는 함수는 전체가 하나의 리턴값
		int sum = a + b;
	}


	int main() {
		//리턴이 있는 함수는 전체가 하나의 리턴 값
		int result = add(4, 9);
		printf("%d\n", result);//13

		printf("%d\n", add2(4, 9));//13

		return 0;
	}