#include <stdio.h>
int main() {
	//�迭 �ӿ��� Ÿ�Կ� �ش��ϴ� ���� ���� �� �ִ�.
	int datas[] = { 10,20,30 };
	printf("datas : %d\n", datas);//���� �ּ�, ù��° ���� �ּ�
	printf("datas+1 : %d\n", datas + 1);//

	//������ ������ *(�ֽ��͸���ũ ��ȣ)
	printf("*datas : %d\n", *datas);//�����ּҸ� �������ؼ� 10 ���
	printf("*(datas+1) : %d\n", *(datas + 1));//�ι�° �� 20 ���
	printf("*(datas+2) : %d\n", *(datas + 2)); // = datas[2]

	printf("datas[0] : %d\n", datas[0]);
	printf("datas[1] : %d\n", datas[1]);
	printf("datas[2] : %d\n", datas[2]);

	//������ ���� ������, �ش� �ּҿ� ���� �ʱ�ȭ ���� �ʾұ⿡, �����Ⱚ�� ���´�.
	printf("datas[3] : %d\n", datas[3]);//���� ��� �ּҴ� ����


	//�迭 �� ��� �����ϱ�
	datas[1] = 49;
	printf("������ �� datas[1] : %d\n", datas[1]); // 49
	//datas[3] = 50;
	//printf("������ �� datas[3] : %d\n", datas[3]);//�������� ��������, ���� �迭���̸� �Ѿ ���߰��� �Ұ�!




	return 0;
}