#include <stdio.h>

// 매크로 함수
#define CHANGE(data1, data2){int temp; temp = data1; data1 = data2; data2 = temp;}

// 배열의 요소를 출력
void show(int* ar, int n) {
	for (int i = 0; i < n; i++) {
		printf("%2d ", ar[i]);
	}
	printf("\n");
}

// 버블 정렬
void bubbleSort(int* ar, int n) {
	show(ar, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1-i; j++) {
			if(ar[j] > ar[j+1]) {
				CHANGE(ar[j], ar[j + 1]);
				show(ar, n);
			}
		}
	}
}

// 선택 정렬
void selectionSort(int* ar, int n) {

	int min; // 최솟값의 인덱스
	show(ar, n);
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i; j < n; j++) {
			if (ar[min] > ar[j]) {
				min = j;
			}
		}
		CHANGE(ar[min], ar[i]);
		show(ar, n);
	}
}

// 삽입 정렬
void insertionSort(int* ar, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (ar[j] < ar[j-1]) {
				CHANGE(ar[j], ar[j - 1]);
				show(ar, n);
			}
			else {
				break;
			}
		}
	}
}

// 분할 정복 알고리즘
// 퀵 정렬
void quickSort(int ar[], int start, int end) {

	int L = start, R = end;
	int pivot = ar[(start + end) / 2]; // 중간 인덱스가 pivot

	while (L <= R) { // pivot이 중간값이니, 중간 지점을 넘어가면 종료.
		while (ar[L] < pivot) { // start 인덱스부터 증가하며 pivot 이상의 값을 찾음.
			L++;
		}

		while (ar[R] > pivot) { // end 부터 감소하며 pivot 보다 작은 값을 찾음
			R--;
		}

		if(L <= R) {
			if (L != R) {
				CHANGE(ar[L], ar[R]);
			}
		}
		L++;
		R--;
	}

	// 재귀 호출
	if (start < R) {
		quickSort(ar, start, R);
	}

	if (L < end) {
		quickSort(ar, L, end);
	}
	show(ar, 10);
}

int main() {
	int ar[10] = {10, 4, 5, 8, 1, 2, 6, 7, 9, 3};
	show(ar, 10);
	//bubbleSort(ar, 10);
	//selectionSort(ar, 10);
	//insertionSort(ar, 10);
	
	quickSort(ar, 0, 9);
	show(ar, 10);


	return 0;
}