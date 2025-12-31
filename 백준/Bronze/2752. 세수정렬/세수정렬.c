#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int array[3] = {0};
	int temp;
	scanf("%d %d %d", &array[0], &array[1], &array[2]);

	if ((array[0] < 1 && array[0]>1000000) && (array[1] < 1 && array[1]>1000000) && (array[2]< 1 && array[2]>1000000)) {
		printf("다시 입력하세요\n");
		return 0;
	}
	if (array[0] == array[1] == array[2]) {
		printf("다시 입력하세요\n");
		return 0;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 3; j++) {
			if (array[i] > array[j]) {
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}