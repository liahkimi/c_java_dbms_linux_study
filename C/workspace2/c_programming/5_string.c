#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	// strcmp(���ڿ�, ���ڿ�2);
	// ���ڿ�1�� ���ڿ�2�� ���ٸ� 0
	// ���ڿ�1�� ���ڿ�2���� �ƽ�Ű�ڵ尪�� �����ٸ� -1
	// ���ڿ�1�� ���ڿ�2���� �ƽ�Ű�ڵ尪�� �����ٸ� 1
	printf("%d\n", strcmp("��ȣ��", "�����"));
	printf("%d\n", strcmp("apple", "apple"));
	printf("%d\n", strcmp("apple", "banana"));
	printf("%d\n", strcmp("banana", "apple"));

	// strcat(������, ���ڿ� ��)
	// �ش� ������ ����ִ� ���ڿ��� �ڿ� �������� ���ڿ���
	// �����ؼ� �ش� ������ �������ش�.

	// �������� �� �Ŀ� ĭ���� ����ٸ� �������� �ʴ´�.
	char temp[11] = "I'm ";
	strcat(temp, "hungry");
	printf("��� : %s\n", temp);
	printf("��� ���� : %d\n", strlen(temp));

	return 0;