#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_SIZE (101)
int V, E;
int adjL[ARR_SIZE][ARR_SIZE];  // 인접리스트
int visited[ARR_SIZE];
int answer;

void inputDataL() {
	int from, to;
	(void)scanf("%d %d", &V, &E);
	for (int i = 0; i < E; ++i) {
		(void)scanf("%d %d", &from, &to);
		adjL[from][++adjL[from][0]] = to;
		adjL[to][++adjL[to][0]] = from;
	}
}

// 인접행렬 사용
void test_adjL(int curr) {
	visited[curr] = 1; // 확실하게 
	for (int next = 1; next <= V; ++next) {
		int nNode = adjL[curr][next];
		if (!visited[nNode]) {
			visited[nNode] = 1;
			answer++;
			test_adjL(nNode);
		}
	}
}
int main(void) {
	inputDataL();
	answer = -1;
	test_adjL(1);
	printf("%d\n", answer);
	return 0;
}