#include <stdio.h>

int main() {
	// int ������ int
	// ������ ������ ������ ����� �׻� �����̴�.
	printf("------- int ������ int -------\n");
	printf("%d\n", 10 + 3);
	printf("%d\n", 10 / 3);

	// int ������ char
	printf("\n------- int ������ char -------\n");
	printf("%d\n", 10 + 'a');

	// 1byte �� ǥ���� �� �ִ� ������ char �� ��밡��.
	printf("%c\n", 10 + 'a');

	// 1byte ������ �ʰ��ϸ� ? �� ���.
	printf("%c\n", 100 + 'a');

	// int ������ double
	// ������ �Ǽ��� ���� ����� double �̴�.
	printf("\n------- int ������ double -------\n");
	printf("%lf\n", (double)10 / 3); // 10�� 10.0 ���� ��������ȯ�� �����ȴ�.
	printf("%lf\n", 10 / 3 + 0.0); // ������ ������ �����ǰ�, �� ����� 0.0�� ���ϸ� �ڵ�����ȯ �߱� ����
	printf("%lf\n", 10 / (3 + 0.0)); // �Ұ�ȣ�� �ֿ켱 ������! 10 / 3.0 �� ����� ����

	// 0 division error
	//printf("%d\n", 5 / 0);
	//printf("%lf\n", 5 / 0.0);

	// ������ ������ %
	printf("\n------- ������ ������ -------\n");
	printf("10�� 3���� ���� ������ : %d\n", 10 % 3);

	return 0;
}