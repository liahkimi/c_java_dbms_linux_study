#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	/*
	���ڿ� 10���� ����� ����.
	����� ������ �Է� �޾Ƽ�, �� ���� ���ڰ� �ʿ����� ����غ���!

	�Է� ���� : 15
	��� ���� : 2���ڰ� �ʿ��մϴ�.

	�Է� ���� : 20
	��� ���� : 2���ڰ� �ʿ��մϴ�.
	*/

	// if��
	//int ramen, box;
	//int boxSize = 10;

	//printf("��� ���� �Է� >> ");
	//scanf("%d", &ramen);

	//if (ramen % 10 == 0) {
	//	box = ramen / boxSize;
	//}
	//else {
	//	box = ramen / boxSize + 1;
	//}
	//printf("%d���ڰ� �ʿ��մϴ�.\n", box);

	// ���׿�����
	//box = ramen % 10 == 0 ? ramen / boxSize : ramen / boxSize + 1;
	//printf("%d���ڰ� �ʿ��մϴ�.\n", box);

	/*
	�� ������ �Է� �޾Ƽ� �� ���� ���� ���ϱ�

	�Է� ���� : 10  30
	��� ���� : "�� ���� ���� 20 �Դϴ�."

	*/

	//int num1, num2;
	//int sub;
	//printf("���� �˰� ���� �� ���� �Է� >> ");
	//scanf("%d %d", &num1, &num2);

	// if ��
	//if (num1 > num2) {
	//	sub = num1 - num2;
	//}
	//else {
	//	sub = num2 - num1;
	//}
	//printf("�� ���� ���� %d �Դϴ�.\n", sub);

	// ���׿�����
	//sub = num1 > num2 ? num1 - num2 : num2 - num1;
	//printf("�� ���� ���� %d �Դϴ�.\n", sub);


	/*
	����ڿ��� ����, ����, ���� ������ �Է� �޾�
	����� ���ϰ� �Ҽ��� ��°�ڸ� ���� ����Ѵ�.
	�� ���� �ٷ� ������ ������ ����ϴ� ���α׷��� �ۼ�������.
	���� : ��տ� ���� ���´�!
	90 �̻��̶�� A����
	80 �̻� 90 �̸��̶�� B����
	70 �̻� 80 �̸��̶�� C����
	70 �̸��̶�� F����

	�Է� ���� :
		������ ���� �Է� >> 80, 90, 100

	��� ���� :
		��� : 90.00
		���� : A
	*/
	int kor, eng, math;
	double avg;
	char grade;

	printf("������ ���� �Է� >> ");
	scanf("%d %d %d", &kor, &eng, &math);

	if (kor < 0) {
		printf("��� ������?\n");
		printf("�峭ġ��?");
	}
	else if (eng < 0) {
		printf("��� ������?\n");
		printf("�峭ġ��?");
	}
	else if (math < 0) {
		printf("������ ������ ? \n");
		printf("�峭ġ��?");
	}
	else {
		avg = (kor + eng + math) / 3.0;

		if (avg >= 90) {
			grade = 'A';
		}
		else if (avg >= 80 /*&& avg < 90*/) { // ���� ���ǽĿ� �̹� �˻��� �κ�!
			grade = 'B';
		}
		else if (avg >= 70 /*&& avg < 80*/) { // ���� ���ǽĿ� �̹� �˻��� �κ�!
			grade = 'C';
		}
		else {
			grade = 'F';
		}

		printf("��� : %.2lf\n���� : %c", avg, grade);
	}


	return 0;
}