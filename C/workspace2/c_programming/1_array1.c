#include <stdio.h>
int main() {
	//배열 속에는 타입에 해당하는 값만 넣을 수 있다.
	int datas[] = { 10,20,30 };
	printf("datas : %d\n", datas);//시작 주소, 첫번째 방의 주소
	printf("datas+1 : %d\n", datas + 1);//

	//역참조 연산자 *(애스터리스크 기호)
	printf("*datas : %d\n", *datas);//시작주소를 역참조해서 10 출력
	printf("*(datas+1) : %d\n", *(datas + 1));//두번째 값 20 출력
	printf("*(datas+2) : %d\n", *(datas + 2)); // = datas[2]

	printf("datas[0] : %d\n", datas[0]);
	printf("datas[1] : %d\n", datas[1]);
	printf("datas[2] : %d\n", datas[2]);

	//오류는 나지 않지만, 해당 주소에 값이 초기화 되지 않았기에, 쓰레기값이 나온다.
	printf("datas[3] : %d\n", datas[3]);//값은 없어도 주소는 있음


	//배열 속 요소 수정하기
	datas[1] = 49;
	printf("수정된 후 datas[1] : %d\n", datas[1]); // 49
	//datas[3] = 50;
	//printf("수정된 후 datas[3] : %d\n", datas[3]);//역참조만 가능하지, 기존 배열길이를 넘어서 값추가는 불가!




	return 0;
}