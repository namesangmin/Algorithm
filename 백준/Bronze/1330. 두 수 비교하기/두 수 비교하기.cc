#include <stdio.h>

int main(void) {
	int A = 0;
	int B = 0;

	scanf("%d %d", &A, &B);

	if ((-10000 <= A && A <= 10000) && (-10000 <= B && B <= 10000)) {
		if (A > B) {
			printf(">\n");
		}
		else if (A < B) {
			printf("<\n");
		}
		else if (A == B) {
			printf("==\n");
		}
		else {
			printf("숫자를 입력하세요\n");
		}
	}
	else {
		printf("-10000~10000 사이의 숫자를 입력하세요\n");
	}

	return 0;
}
