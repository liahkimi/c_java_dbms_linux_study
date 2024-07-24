#include <stdio.h>

int main() {
	int num = 10;
	//포인터 변수
	int* nPtr = &num;//int변수에 num주소를 담아주는 포인터

	printf("num의 주소 : %d\n", &num);
	printf("nPtr의 값 : %d\n", nPtr);

	printf("nPtr이 참조하고 있는 주소 안의 값 : %d\n", *nPtr);//10

	*nPtr = 200;

	printf("num의 값 : %d\n", num);//200


	return 0;
}