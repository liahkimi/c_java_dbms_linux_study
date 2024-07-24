#include <stdio.h>
#include <time.h>//time()함수를 사용하기 위해 호출
#include <stdlib.h>//rand()함수를 사용하기 위해 호출

// 난수 생성 부분 테스트
int main() {
	// time.h
	// time(NULL) --> 70년 1월 1일 0시 0분 0초 이후로 지금까지 경과한 시간을 초로 가져온다.
	printf("%d\n", time(NULL));//1707969646 <- 현재시간을 초단위로 표현한것

	// stdlib.h
	// rand() 0 ~ 32767 사이의 난수를 가져온다.
	// rand() % 20 + 1 --> 1 ~ 20 
	srand(time(NULL));//매번 다른 랜덤숫자가 나오게 해주는 함수
	//rand() 쓰기전에 초기화


	//1~20사이의 숫자 중, 랜덤숫자를 10번 출력하기
	for (int i = 0; i < 10; i++) {
		printf("난수 : %d\n", rand() % 20 + 1);// 어떤수(랜덤수)에서 20를 나눈 나머지에 (0~19) 1을 더함.=>1~20사이의 숫자
	}
}