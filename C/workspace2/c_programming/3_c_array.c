#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char country1[] = { 'k', 'o', 'r', 'e', 'a' };

	//printf("%s\n", country1);
	//printf("문자열의 사이즈 : %d\n", sizeof(country1));

	//for (int i = 0; i < sizeof(country1); i++) {
	//	printf("%c", country1[i]);
	//}

	char country2[] = { 'k', 'o', 'r', 'e', 'a', /*'\0'*/NULL };
	char country3[] = "singapore";

	printf("country2 : %s\n", country2);
	printf("country3 : %s\n", country3);

	// 큰 따옴표로 문자열을 표현한다면
	// \0 가 생략된다.
	// sizeof 로 보면, \0까지 메모리에 할당된 것을 확인할 수 있다.
	printf("country3의 크기 : %d\n", sizeof(country3));
	printf("%c\n", country3[9]); // 쓰레기가 안나오기에, NULL 이 들어가있다는 걸 확인!

	printf("\n===== 문자열 입력 받기 =====\n");

	char input[100];

	// scanf에는 저장할 주소를 알려줘야한다.
	// input은 배열이기 때문에 주소이다.
	// 따라서 &는 굳이 쓸 필요가 없다.
	scanf("%s", input);
	printf("입력된 값 : %s\n", input);

	printf("sizeof(input) : %d\n", sizeof(input));
	printf("strlen(input) : %d\n", strlen(input));

	return 0;
}