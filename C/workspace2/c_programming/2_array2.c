#include <stdio.h>

int main() {
	//�迭�� for���� �ݶ�
	int ar[] = { 10,20,30 };
	int datas[3] = { 0 }; // �ʱⰪ�� �ϳ��� �������ָ� �ش� ������ ���� �ʱ�ȭ�� 

	//sizeof ������
	printf("sizeof(ar) : %d\n", sizeof(ar));//12 = 4byte * 3 = ����� ���� 3��
	printf("sizeof(int) : %d\n", sizeof(int));//4byte
	printf("�迭 �� ��� ���� : %d\n", sizeof(ar) / sizeof(int));//3�� <-size�� �ʹ� Ŭ ��� �̷��� ����Ű��


	for (int i = 0; i < sizeof(ar) / sizeof(int); i++) {
		printf("ar[%d]�� ���� %d\n", i, ar[i]);//ar[0]�� ���� 10  ar[1]�� ���� 20  ar[2]�� ���� 30
	}
	for (int i = 0; i < sizeof(ar) / sizeof(int); i++) {
		printf("datas[%d]�� ���� %d\n", i, datas[i]);//datas[0]�� ���� 0  datas[1]�� ���� 0  datas[2]�� ���� 0
	}






	return 0;
}