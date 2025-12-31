#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	
	int num;
	scanf("%d", &num);
	int a, b, c;
	int count = 0;

	a = num / 10;
	b = num % 10;
	c = a+b;
	if (c < 10) c = b * 10 + c;
	else c = b * 10 + c % 10;

	count++;

	if (c == num) {
		printf("%d", count);
	}
	else {
		while (c != num) {
			a = c / 10;
			b = c % 10;
			if(a+b<10) c = b * 10 + (a + b);
			else {
				c = b * 10 + (a + b) % 10;
			}
			count++;
		}
		printf("%d", count);
	}

	



	return 0;
}



