#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc �Լ�

void printTime(int second) {

	int hours, miniutes, seconds;

	hours = second / 3600;
	miniutes = (second % 3600) / 60;
	seconds = second % 60;

	printf("%d�ð� / %d�� / %d��\n", hours, miniutes, seconds);
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
	//int time[3]; �Լ��� ����Ǹ� �Լ� �ȿ��� ������� �����͵� �翬�� ����!
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
	//// 1�� ���
	//printTime(3605);

	//// 2�� ���
	//int result[3];
	//getTime(3888, result);

	//printf("%d�ð� / %d�� / %d��\n", result[0], result[1], result[2]);

	// 3�� ���
	int* result = returnTime(8745);
	printf("%d�ð� / %d�� / %d��\n", result[0], result[1], result[2]);
	printf("%d�ð� / %d�� / %d��\n", result[0], result[1], result[2]);


	return 0;
}