#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc 함수

void printTime(int second) {

	int hours, miniutes, seconds;

	hours = second / 3600;
	miniutes = (second % 3600) / 60;
	seconds = second % 60;

	printf("%d시간 / %d분 / %d초\n", hours, miniutes, seconds);
}

void getTime(int second, int* time) {

	int hours, miniutes, seconds;

	hours = second / 3600;
	miniutes = (second % 3600) / 60;
	seconds = second % 60;


	time[0] = hours;
	time[1] = miniutes;
	time[2] = seconds;
}

int* returnTime(int second) {
	int hours, miniutes, seconds;
	//int time[3]; 함수가 종료되면 함수 안에서 만들어준 포인터도 당연히 해제!
	int* time = (int*)malloc(3 * sizeof(int));

	hours = second / 3600;
	miniutes = (second % 3600) / 60;
	seconds = second % 60;

	time[0] = hours;
	time[1] = miniutes;
	time[2] = seconds;

	return time;
}

int main() {
	//// 1번 모양
	//printTime(3605);

	//// 2번 모양
	//int result[3];
	//getTime(3888, result);

	//printf("%d시간 / %d분 / %d초\n", result[0], result[1], result[2]);

	// 3번 모양
	int* result = returnTime(8745);
	printf("%d시간 / %d분 / %d초\n", result[0], result[1], result[2]);
	printf("%d시간 / %d분 / %d초\n", result[0], result[1], result[2]);


	return 0;
}