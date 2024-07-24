#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#pragma pack(2)

//구조체 정의
struct Student {
	char name[30]; //멤버변수
	int kor; //멤버변수
	int eng; //멤버변수
};
//구조체에 별명 설정하기
typedef struct Human {
	int age;
}Hu;

//별명만 존재하는 구조체
typedef struct {
	int age;
}Per;


void printStudent(struct Student stu) {
	printf("이름 : %s\n국어점수 : %d\n영어점수 : %d\n", stu.name, stu.kor, stu.eng);
}




int main() {
	//일반 자료형 선언
	int num;

	//사용자 정의 자료형 선언
	struct Student ryu; //ryu라는 이름을 가진 구조체 변수 선언

	//구조체 변수의 초기화
	/*ryu.name = "류호근";*/ //배열이기 때문에 주소값 변경 불가능
	//strcpy() 함수를 이용
	strcpy(ryu.name , "류호근");
	ryu.kor = 100;
	ryu.eng = 49;
	printStudent(ryu);
	printf("\n==========================================\n");

	//변수 선언과 동시에 초기화
	struct Student kim = { "김철수", 90, 80 };
	printStudent(kim);
	printf("\n==========================================\n");

	//변수 선언과 동시에 초기화
	//각 멤버변수를 직접 명시해주면 된다.
	struct Student hong = { .eng=80, .name="홍길동", .kor = 100};
	hong.eng = 85;//구조체 변수값 수정
	printStudent(hong);
	printf("\n==========================================\n");

	//구조체에 별명 설정하기
	struct Human hu1; //원래모양으로도 사용 가능
	//Hu hu2; //별명을 이용해서 변수 선언
	
	Per per1;
	//struct Per per2; //원래 모양은 사용 불가능

	printf("구조체 변수 사이즈 : %d\n", sizeof(ryu));//사이즈 : 40으로 나옴 <-why? 30+4+4 = 38이지만 만약 4byte로 나누면 애매해지므로 40으로 처리함
	//#pragma pack(2) 를 헤더파일로 넣어주면 정확한 사이즈가 나오지만, 성능 떨어짐


	return 0;
}