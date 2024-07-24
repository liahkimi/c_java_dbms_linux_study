#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수의 선언
// 메인 함수 위에 선언을 해놓아야지만 사용가능!
// 매개변수와 리턴 둘 다 없는 함수!
void printRyu();

// 국영수 점수의 총점과 평균을 출력해주는 함수.
// 매개변수만 있는 함수!
void printScore1(int kor, int eng, int math) {
	int sum = kor + eng + math;
	double avg = sum / 3.0;

	printf("총점 : %d\n평균 : %.2lf\n", sum, avg);
}

void printScore2() {
	int kor, eng, math, sum;
	double avg;
	printf("국영수 점수 입력 >> ");
	scanf("%d%d%d", &kor, &eng, &math);

	sum = kor + eng + math;
	avg = sum / 3.0;

	printf("총점 : %d\n평균 : %.2lf\n", sum, avg);
}

// 정수 3개를 덧셈해주고 리턴.
// 매개변수와 리턴이 전부다 있는 함수.
// 리턴이 있는 함수는 함수 사용부분 전체를
// 하나의 값으로 볼 줄 알아야한다.
int add(int num1, int num2, int num3) {
	int sum = num1 + num2 + num3;
	return sum;
}

// 매개변수로 값을 넘겨줄 때, 순서에 맞게 넘겨줘야한다.
// 이름을 n번 출력.
void printName(int count, const char name[]) {
	for (int i = 0; i < count; i++) {
		printf(name);
	}
}

// 출생연도를 보고 성인인지 아닌지를 판별해주는 함수
void checkAdult(int year) {
	int age = getAge(year);
	if (age >= 20) {
		printf("성인 입니다.\n");
	}
	else {
		printf("미성년자입니다.\n");
	}
}

// 연도를 입력받아 나이를 구해주는 함수
int getAge(int year) {
	return 2024 - year + 1;
}



int main() {
	//printRyu();
	//printScore1(70, 50, 30);
	//printScore2();

	//int n1, n2, n3;
	//int result;
	//printf("정수 3개를 입력 >> ");
	//scanf("%d%d%d", &n1, &n2, &n3);

	//result = add(n1, n2, n3);
	//printf("결과 : %d\n", result);

	// 매개변수는 순서에 맞게!
	//printName("류호근", 5);
	//printName(5, " 류호근");
	int year;

	while (1) {
		printf("출생연도 입력 (0 입력시 종료) >> ");
		scanf("%d", &year);
		if (year == 0) {
			printf("프로그램 종료");
			break;
		}
		checkAdult(year);
	}

	return 0;
}

// 함수의 정의
void printRyu() {
	for (int i = 0; i < 3; i++) {
		printf("류호근");
	}
}