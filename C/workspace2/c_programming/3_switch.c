#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num = 5;

	switch (num) {
	case 10:
		printf("num에 저장된 값은 10입니다.\n");
		// if문을 제외한 가장 가까운 중괄호 영역을 탈출.
	case 7:
		printf("num에 저장된 값은 7입니다.\n");
		break;
	case 5:
		printf("num에 저장된 값은 5입니다.\n");
		break;
	case 3:
		printf("num에 저장된 값은 3입니다.\n");
		break;
	case 1:
		printf("num에 저장된 값은 1입니다.\n");
		break;
	default:
		printf("그 외에 수 입니다.");
		// break 필요 없다. 어차피 마지막 구문 때문!
	}

	printf("\n---------- switch 실습 ----------\n");

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

	avg = (kor + eng + math) / 3.0;

	switch ((int)avg / 10) {
	case 10: // 10일 때, 9일 대 모두 실행
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	default:
		grade = 'F';
	}

	printf("평균 : %.2lf\n학점 : %c", avg, grade);



	return 0;
}