#include <stdio.h>

//�Լ��� ����� ��� 

//������ �ִ� �����Լ�
int add(int a, int b) {
	int sum = a + b;
	return sum;//��
	//�Լ� ȣ���� ����Ǹ� ����ߴ� ������ ���� �޸𸮿��� �����ȴ�.}

	//������ ���� �����Լ�
	void add2(int a, int b) {
		//������ �ִ� �Լ��� ��ü�� �ϳ��� ���ϰ�
		int sum = a + b;
	}


	int main() {
		//������ �ִ� �Լ��� ��ü�� �ϳ��� ���� ��
		int result = add(4, 9);
		printf("%d\n", result);//13

		printf("%d\n", add2(4, 9));//13

		return 0;
	}