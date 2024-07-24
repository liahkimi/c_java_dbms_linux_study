#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[30];
    int score;
}Stu;

// 함수 만들기
// 구조체 배열을 전달 받아, 점수의 평균을 리턴해주는 함수.
// 매개변수로 넘어올 때는 포인터 형태로 넘어온다.
// 복사된 포인터를 이용해서는 sizeof 연산자를 사용할 수 없다.
double getAvg(Stu stu[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += stu[i].score;
    }
    printf("%d\n", sum);
    return sum / (double)len;
}

int main() {
    //Stu s1 = { "류호근", 100 };
    //Stu s2 = { "류지환", 50 };
    //Stu s3 = { "김철수", 100 };
    //Stu s4 = { "신짱구", 100 };
    //Stu s5 = { "훈이", 100 };

    //Stu students[] = {s1, s2, s3, s4, s5};
    Stu students[] = {
       { "류호근", 100 },
       { "류지환", 50 },
       { "김철수", 88 },
       { "신짱구", 75 },
       { "훈이", 69 }
    };

    printf("배열의 길이 : %d\n", sizeof(students) / sizeof(Stu));
    printf("학생 점수의 평균 : %.2lf\n", getAvg(students, sizeof(students) / sizeof(Stu)));

    printf("==================================================================");
    // 구조체 포인터
// 포인터는 포인터인데, 구조체 변수의 주소값을 담아주는 포인터
    Stu ryu = { "류호근", 100 };
    Stu* sptr = &ryu; // 구조체 포인터

    (*sptr).score = 50;
    printf("ryu의 socre : %d\n", ryu.score);

    // ->
    sptr->score = 70;
    printf("ryu의 socre : %d\n", sptr->score);


    return 0;
}