#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �Լ��� ����
// ���� �Լ� ���� ������ �س��ƾ����� ��밡��!
// �Ű������� ���� �� �� ���� �Լ�!
void printRyu();

// ������ ������ ������ ����� ������ִ� �Լ�.
// �Ű������� �ִ� �Լ�!
void printScore1(int kor, int eng, int math) {
	int sum = kor + eng + math;
	double avg = sum / 3.0;

	printf("���� : %d\n��� : %.2lf\n", sum, avg);
}

void printScore2() {
	int kor, eng, math, sum;
	double avg;
	printf("������ ���� �Է� >> ");
	scanf("%d%d%d", &kor, &eng, &math);

	sum = kor + eng + math;
	avg = sum / 3.0;

	printf("���� : %d\n��� : %.2lf\n", sum, avg);
}

// ���� 3���� �������ְ� ����.
// �Ű������� ������ ���δ� �ִ� �Լ�.
// ������ �ִ� �Լ��� �Լ� ���κ� ��ü��
// �ϳ��� ������ �� �� �˾ƾ��Ѵ�.
int add(int num1, int num2, int num3) {
	int sum = num1 + num2 + num3;
	return sum;
}

// �Ű������� ���� �Ѱ��� ��, ������ �°� �Ѱ�����Ѵ�.
// �̸��� n�� ���.
void printName(int count, const char name[]) {
	for (int i = 0; i < count; i++) {
		printf(name);
	}
}

// ��������� ���� �������� �ƴ����� �Ǻ����ִ� �Լ�
void checkAdult(int year) {
	int age = getAge(year);
	if (age >= 20) {
		printf("���� �Դϴ�.\n");
	}
	else {
		printf("�̼������Դϴ�.\n");
	}
}

// ������ �Է¹޾� ���̸� �����ִ� �Լ�
int getAge(int year) {
	return 2024 - year + 1;
}



int main() {
	//printRyu();
	//printScore1(70, 50, 30);
	//printScore2();

	//int n1, n2, n3;
	//int result;
	//printf("���� 3���� �Է� >> ");
	//scanf("%d%d%d", &n1, &n2, &n3);

	//result = add(n1, n2, n3);
	//printf("��� : %d\n", result);

	// �Ű������� ������ �°�!
	//printName("��ȣ��", 5);
	//printName(5, " ��ȣ��");
	int year;

	while (1) {
		printf("������� �Է� (0 �Է½� ����) >> ");
		scanf("%d", &year);
		if (year == 0) {
			printf("���α׷� ����");
			break;
		}
		checkAdult(year);
	}

	return 0;
}

// �Լ��� ����
void printRyu() {
	for (int i = 0; i < 3; i++) {
		printf("��ȣ��");
	}
}