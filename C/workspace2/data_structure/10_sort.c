#include <stdio.h>

// ��ũ�� �Լ�
#define CHANGE(data1, data2){int temp; temp = data1; data1 = data2; data2 = temp;}

// �迭�� ��Ҹ� ���
void show(int* ar, int n) {
	for (int i = 0; i < n; i++) {
		printf("%2d ", ar[i]);
	}
	printf("\n");
}

// ���� ����
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

// ���� ����
void selectionSort(int* ar, int n) {

	int min; // �ּڰ��� �ε���
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

// ���� ����
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

// ���� ���� �˰���
// �� ����
void quickSort(int ar[], int start, int end) {

	int L = start, R = end;
	int pivot = ar[(start + end) / 2]; // �߰� �ε����� pivot

	while (L <= R) { // pivot�� �߰����̴�, �߰� ������ �Ѿ�� ����.
		while (ar[L] < pivot) { // start �ε������� �����ϸ� pivot �̻��� ���� ã��.
			L++;
		}

		while (ar[R] > pivot) { // end ���� �����ϸ� pivot ���� ���� ���� ã��
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

	// ��� ȣ��
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