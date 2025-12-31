#define _CRT_SECURE_NO_WARNINGS
#define MAX 10001
#include <stdio.h>

int parents[MAX];		// 초기에 부모노드는 자기 자신을 부모노드로 삼아야하므로 여기서 초기화하면 x main에서 해야함
int rank[MAX];

int main() {
	int T, N, first_input, second_input;
	int i = 0;
	scanf("%d", &T);

	for (int j = 0; j < T; j++) {

		scanf("%d", &N);

		for (int i = 0; i <= N; i++) {
			parents[i] = i;
			rank[i] = 0;
		}

		for (int i = 0; i < N-1; i++) {
			scanf(" %d %d", &first_input, &second_input);
			parents[second_input] = first_input;
			rank[second_input] = rank[first_input] + 1;
			//printf("first_input >> %d %d\n", parents[first_input], rank[first_input]);
			//printf("second_input >> %d %d\n", parents[second_input], rank[second_input]);
		}
		int a, b;
		scanf("%d %d", &a, &b);
		while (a != b) {
			if (rank[a] != rank[b]) {
				if (rank[a] > rank[b]) {
					a = parents[a];
				}
				else if (rank[a] < rank[b]) {
					b = parents[b];
				}
			}
			else {
				a = parents[a];
				b = parents[b];
			}

		}
		printf("%d\n", a);
	}
	return 0;
}