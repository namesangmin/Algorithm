#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N = -1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < i; j++) 
			printf(" ");

		for(int j = i; j<N; j++)
			printf("*");

		
		printf("\n");
	}
}