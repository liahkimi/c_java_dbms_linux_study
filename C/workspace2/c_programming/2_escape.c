#include <stdio.h>

int main() {
	// 이스케이프 실습
	printf("설날에 혼자 집에 차타고 내려가기가 살짝\t 겁이납니다.\n");
	printf("오랜만에 집밥을 먹을 생각에 설렙니다.\n");
	printf("엄마한테 오뎅 볶아달라고 할거에요.\n");
	printf("엄마한테 멸치도 볶아달라고 할거에요.\n");

	printf("나는 너에게 \"사랑해\" 라고 말했다.\n");

	// 쌍따옴표 안에서 홑따옴표를 쓰면 알아서 기능이 죽는다.
	// 하지만 역슬래쉬를 붙여도 결과는 똑같다.
	printf("나는 너에게 '사랑해\' 라고 말했다.\n\n\n\n");



	// 서식지정자 실습
	int age = 22;
	char gender = 'M';
	double height = 175.5;

	// 변수로도 가능
	printf("제 나이는 %d살이고 키는 %lfcm 이고 성별은 %c입니다.\n", age, height, gender);

	// 다이렉트로도 가능
	printf("제 나이는 %-5d살이고 키는 %010.2lfcm 이고 성별은 %c입니다.\n", 25, 180.5, 'W');

	return 0;
}