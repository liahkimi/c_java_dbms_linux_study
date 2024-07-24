#include <stdio.h>

int main() {
	//배열과 for문의 콜라보
	int ar[] = { 10,20,30 };
	int datas[3] = { 0 }; // 초기값을 하나만 전달해주면 해당 값으로 전부 초기화됨 

	//sizeof 연산자
	printf("sizeof(ar) : %d\n", sizeof(ar));//12 = 4byte * 3 = 요소의 개수 3개
	printf("sizeof(int) : %d\n", sizeof(int));//4byte
	printf("배열 속 요소 갯수 : %d\n", sizeof(ar) / sizeof(int));//3개 <-size가 너무 클 경우 이렇게 계산시키기


	for (int i = 0; i < sizeof(ar) / sizeof(int); i++) {
		printf("ar[%d]의 값은 %d\n", i, ar[i]);//ar[0]의 값은 10  ar[1]의 값은 20  ar[2]의 값은 30
	}
	for (int i = 0; i < sizeof(ar) / sizeof(int); i++) {
		printf("datas[%d]의 값은 %d\n", i, datas[i]);//datas[0]의 값은 0  datas[1]의 값은 0  datas[2]의 값은 0
	}






	return 0;
}