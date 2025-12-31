#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int num;
	scanf("%d", &num);
	char name[150][30];
	char m[150];


	char a[26];
	int number[26];

	for (int i = 0; i < 26; i++) {
		a[i] = 'a' + i;
		number[i] = 0;
	}


	for (int i = 0; i < num; i++) {
		scanf("%s", &name[i]);

		m[i] = name[i][0];
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 26; j++) {
			if (m[i] == a[j]) {
				number[j]++;
			}
		}
	}
	int count = 0;

	for (int i = 0; i < 26; i++) {
		if (number[i] >= 5) {
			printf("%c", a[i]);
			count++;
		}
	}
	if (count == 0) printf("PREDAJA");


	return 0;
}



