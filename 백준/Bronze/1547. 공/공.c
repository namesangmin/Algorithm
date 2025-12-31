#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int M = -1;
	int X, Y;
	int Cup[4] = { 0,1,0,0 };
	int temp;

	scanf("%d", &M);

	if (M > 50 || M < 0) {
		return 0;
	}

	for (int i = 0; i < M; i++) {
		scanf(" %d %d", &X, &Y);
		if ((X > 3 || X <= 0 ) || (Y > 3 || Y <= 0) || (X == Y))
			break;
		temp = Cup[X];
		Cup[X] = Cup[Y];
		Cup[Y] = temp;
		
	}
	for (int i = 1; i < 4; i++)if (Cup[i] == 1)printf("%d\n", i);

//	printf("%d\n", Cup[0]);
	return 0;
}