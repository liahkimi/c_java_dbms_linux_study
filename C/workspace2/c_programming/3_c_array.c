#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char country1[] = { 'k', 'o', 'r', 'e', 'a' };

	//printf("%s\n", country1);
	//printf("���ڿ��� ������ : %d\n", sizeof(country1));

	//for (int i = 0; i < sizeof(country1); i++) {
	//	printf("%c", country1[i]);
	//}

	char country2[] = { 'k', 'o', 'r', 'e', 'a', /*'\0'*/NULL };
	char country3[] = "singapore";

	printf("country2 : %s\n", country2);
	printf("country3 : %s\n", country3);

	// ū ����ǥ�� ���ڿ��� ǥ���Ѵٸ�
	// \0 �� �����ȴ�.
	// sizeof �� ����, \0���� �޸𸮿� �Ҵ�� ���� Ȯ���� �� �ִ�.
	printf("country3�� ũ�� : %d\n", sizeof(country3));
	printf("%c\n", country3[9]); // �����Ⱑ �ȳ����⿡, NULL �� ���ִٴ� �� Ȯ��!

	printf("\n===== ���ڿ� �Է� �ޱ� =====\n");

	char input[100];

	// scanf���� ������ �ּҸ� �˷�����Ѵ�.
	// input�� �迭�̱� ������ �ּ��̴�.
	// ���� &�� ���� �� �ʿ䰡 ����.
	scanf("%s", input);
	printf("�Էµ� �� : %s\n", input);

	printf("sizeof(input) : %d\n", sizeof(input));
	printf("strlen(input) : %d\n", strlen(input));

	return 0;
}