#include <stdio.h>

int main() {
    // 배열 포인터
    int ar1[5] = { 1, 2, 3, 4, 5 };
    int* ptr = ar1;//ar1배열을 가리키는 포인터
    printf("%d\n", ptr);//1446902184 <-포인터(배열의 주소)
    printf("%d\n", *ptr);//1* <-포인터를 역참조하면 해당 값이 나옴

    // 포인터 배열 : 포인터를 요소로 가진 배열
    int* ar2[10]; // 요소가 int* 인 10칸 배열을 선언!
    int* a;//포인터 선언은 연결해서 할 수 없다.
    int* b;//포인터 배열인 a, b

    int data = 10;
    int nums[5] = { 10, 20, 30, 40, 50 };//칸수가 5개인 배열 선언

    a = &data;//주소값
    b = nums;

    ar2[0] = a; //ar2[0] = 10;
    ar2[1] = b; //  ar2[1] = { 10, 20, 30, 40, 50 };

    printf("ar2에 저장된 주소 %d\n", ar2);
    printf("ar2에 저장된 값 %d\n", *ar2);
    printf("ar2에 저장된 값 %d\n", *(*ar2));
    printf("ar2에 저장된 값 %d\n", *ar2[0]);

    // [실습]
    // for문 돌려서, ar2로 접근! 10, 20, 30, 40, 50 출력
    for (int i = 0; i < 5; i++) {

    }
    printf("%d\n", &ar2[1]);


    return 0;
}