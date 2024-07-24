#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	/*
	상자에 10개의 라면이 들어간다.
	라면의 갯수를 입력 받아서, 몇 개의 상자가 필요한지 출력해보자!

	입력 예시 : 15
	출력 예시 : 2상자가 필요합니다.

	입력 예시 : 20
	출력 예시 : 2상자가 필요합니다.
	*/

	// if문
	//int ramen, box;
	//int boxSize = 10;

	//printf("라면 갯수 입력 >> ");
	//scanf("%d", &ramen);

	//if (ramen % 10 == 0) {
	//	box = ramen / boxSize;
	//}
	//else {
	//	box = ramen / boxSize + 1;
	//}
	//printf("%d상자가 필요합니다.\n", box);

	// 삼항연산자
	//box = ramen % 10 == 0 ? ramen / boxSize : ramen / boxSize + 1;
	//printf("%d상자가 필요합니다.\n", box);

	/*
	두 정수를 입력 받아서 두 수의 차를 구하기

	입력 예시 : 10  30
	출력 예시 : "두 수의 차는 20 입니다."

	*/

	//int num1, num2;
	//int sub;
	//printf("차를 알고 싶은 두 정수 입력 >> ");
	//scanf("%d %d", &num1, &num2);

	// if 문
	//if (num1 > num2) {
	//	sub = num1 - num2;
	//}
	//else {
	//	sub = num2 - num1;
	//}
	//printf("두 수의 차는 %d 입니다.\n", sub);

	// 삼항연산자
	//sub = num1 > num2 ? num1 - num2 : num2 - num1;
	//printf("두 수의 차는 %d 입니다.\n", sub);


	/*
	사용자에게 국어, 영어, 수학 점수를 입력 받아
	평균을 구하고 소수점 둘째자리 까지 출력한다.
	그 다음 바로 밑으로 학점도 출력하는 프로그램을 작성을하자.
	학점 : 평균에 따라 나온다!
	90 이상이라면 A학점
	80 이상 90 미만이라면 B학점
	70 이상 80 미만이라면 C학점
	70 미만이라면 F학점

	입력 예시 :
		국영수 점수 입력 >> 80, 90, 100

	출력 예시 :
		평균 : 90.00
		학점 : A
	*/
	int kor, eng, math;
	double avg;
	char grade;

	printf("국영수 점수 입력 >> ");
	scanf("%d %d %d", &kor, &eng, &math);

	if (kor < 0) {
		printf("국어가 음수니?\n");
		printf("장난치나?");
	}
	else if (eng < 0) {
		printf("영어가 음수니?\n");
		printf("장난치나?");
	}
	else if (math < 0) {
		printf("수학이 음수니 ? \n");
		printf("장난치나?");
	}
	else {
		avg = (kor + eng + math) / 3.0;

		if (avg >= 90) {
			grade = 'A';
		}
		else if (avg >= 80 /*&& avg < 90*/) { // 위의 조건식에 이미 검사한 부분!
			grade = 'B';
		}
		else if (avg >= 70 /*&& avg < 80*/) { // 위의 조건식에 이미 검사한 부분!
			grade = 'C';
		}
		else {
			grade = 'F';
		}

		printf("평균 : %.2lf\n학점 : %c", avg, grade);
	}


	return 0;
}