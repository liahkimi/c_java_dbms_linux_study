#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char input[100];
	char u_input[100];
	printf("���ڿ� �Է� >> ");
	scanf("%s", input);
	printf("�Էµ� �� : %s\n", input);

	// input�� �Էµ� ��� �빮�ڴ� �ҹ��ڷ�, �ҹ��ڴ� �빮�ڷ�
	// ������(����, Ư������ ���)�� �״�� ����ϴ� ���α׷� �����!

	// for
	printf("��ȯ�� �� : ");
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 65 && input[i] <= 90) { // �빮�ڶ��
			printf("%c", input[i] + 32);
		}
		else if (input[i] >= 97 && input[i] <= 122) { // �ҹ��ڶ��
			printf("%c", input[i] - 32);
		}
		else {
			printf("%c", input[i]);
		}
	}



	// while
	printf("\n��ȯ�� �� : ");
	int i = 0;
	while (input[i] != '\0') {
		if (input[i] >= 65 && input[i] <= 90) { // �빮�ڶ��
			printf("%c", input[i] + 32);
		}
		else if (input[i] >= 97 && input[i] <= 122) { // �ҹ��ڶ��
			printf("%c", input[i] - 32);
		}
		else {
			printf("%c", input[i]);
		}
		i++;
	}

	// u_input ���ڿ��� ��ȯ�� ���� ������ �ϱ�.
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 65 && input[i] <= 90) { // �빮�ڶ��
			u_input[i] = input[i] + 32;
		}
		else if (input[i] >= 97 && input[i] <= 122) { // �ҹ��ڶ��
			u_input[i] = input[i] - 32;
		}
		else {
			u_input[i] = input[i];
		}
		// �ݺ��� �� �� ���� �׻� �˻縦 �ϱ⿡, ����õ.
		//if (i == strlen(input) - 1) {
		//	u_input[i + 1] = '\0';
		//}
	}
	u_input[strlen(input)] = '\0';

	printf("\n��ȯ�� �� : %s\n", u_input);

	return 0;
}