#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#pragma pack(2)

//����ü ����
struct Student {
	char name[30]; //�������
	int kor; //�������
	int eng; //�������
};
//����ü�� ���� �����ϱ�
typedef struct Human {
	int age;
}Hu;

//���� �����ϴ� ����ü
typedef struct {
	int age;
}Per;


void printStudent(struct Student stu) {
	printf("�̸� : %s\n�������� : %d\n�������� : %d\n", stu.name, stu.kor, stu.eng);
}




int main() {
	//�Ϲ� �ڷ��� ����
	int num;

	//����� ���� �ڷ��� ����
	struct Student ryu; //ryu��� �̸��� ���� ����ü ���� ����

	//����ü ������ �ʱ�ȭ
	/*ryu.name = "��ȣ��";*/ //�迭�̱� ������ �ּҰ� ���� �Ұ���
	//strcpy() �Լ��� �̿�
	strcpy(ryu.name , "��ȣ��");
	ryu.kor = 100;
	ryu.eng = 49;
	printStudent(ryu);
	printf("\n==========================================\n");

	//���� ����� ���ÿ� �ʱ�ȭ
	struct Student kim = { "��ö��", 90, 80 };
	printStudent(kim);
	printf("\n==========================================\n");

	//���� ����� ���ÿ� �ʱ�ȭ
	//�� ��������� ���� ������ָ� �ȴ�.
	struct Student hong = { .eng=80, .name="ȫ�浿", .kor = 100};
	hong.eng = 85;//����ü ������ ����
	printStudent(hong);
	printf("\n==========================================\n");

	//����ü�� ���� �����ϱ�
	struct Human hu1; //����������ε� ��� ����
	//Hu hu2; //������ �̿��ؼ� ���� ����
	
	Per per1;
	//struct Per per2; //���� ����� ��� �Ұ���

	printf("����ü ���� ������ : %d\n", sizeof(ryu));//������ : 40���� ���� <-why? 30+4+4 = 38������ ���� 4byte�� ������ �ָ������Ƿ� 40���� ó����
	//#pragma pack(2) �� ������Ϸ� �־��ָ� ��Ȯ�� ����� ��������, ���� ������


	return 0;
}