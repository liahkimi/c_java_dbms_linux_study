#include <stdio.h>

int main() {
	int num = 10;
	//������ ����
	int* nPtr = &num;//int������ num�ּҸ� ����ִ� ������

	printf("num�� �ּ� : %d\n", &num);
	printf("nPtr�� �� : %d\n", nPtr);

	printf("nPtr�� �����ϰ� �ִ� �ּ� ���� �� : %d\n", *nPtr);//10

	*nPtr = 200;

	printf("num�� �� : %d\n", num);//200


	return 0;
}