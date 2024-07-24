#include <stdio.h>

int main() {

	for (int i = 0; i <= 9; i++) {
		for (int dan = 2; dan <= 9; dan++) {
			if (i == 0) {
				printf("=== %d´Ü ===  ", dan);
			}
			else {
				printf("%d * %d = %2d   ", dan, i, dan * i);
			}
		}
		printf("\n");
	}


	return 0;
}