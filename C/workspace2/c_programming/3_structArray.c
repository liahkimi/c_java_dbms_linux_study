#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[30];
    int score;
}Stu;

// �Լ� �����
// ����ü �迭�� ���� �޾�, ������ ����� �������ִ� �Լ�.
// �Ű������� �Ѿ�� ���� ������ ���·� �Ѿ�´�.
// ����� �����͸� �̿��ؼ��� sizeof �����ڸ� ����� �� ����.
double getAvg(Stu stu[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += stu[i].score;
    }
    printf("%d\n", sum);
    return sum / (double)len;
}

int main() {
    //Stu s1 = { "��ȣ��", 100 };
    //Stu s2 = { "����ȯ", 50 };
    //Stu s3 = { "��ö��", 100 };
    //Stu s4 = { "��¯��", 100 };
    //Stu s5 = { "����", 100 };

    //Stu students[] = {s1, s2, s3, s4, s5};
    Stu students[] = {
       { "��ȣ��", 100 },
       { "����ȯ", 50 },
       { "��ö��", 88 },
       { "��¯��", 75 },
       { "����", 69 }
    };

    printf("�迭�� ���� : %d\n", sizeof(students) / sizeof(Stu));
    printf("�л� ������ ��� : %.2lf\n", getAvg(students, sizeof(students) / sizeof(Stu)));

    printf("==================================================================");
    // ����ü ������
// �����ʹ� �������ε�, ����ü ������ �ּҰ��� ����ִ� ������
    Stu ryu = { "��ȣ��", 100 };
    Stu* sptr = &ryu; // ����ü ������

    (*sptr).score = 50;
    printf("ryu�� socre : %d\n", ryu.score);

    // ->
    sptr->score = 70;
    printf("ryu�� socre : %d\n", sptr->score);


    return 0;
}