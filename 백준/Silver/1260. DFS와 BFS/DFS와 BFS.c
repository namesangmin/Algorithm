#include <stdio.h>
#define MAX_N 1001

int visited[MAX_N] = {0}; // 스택
int visited_bfs[MAX_N] = { 0 };
int arr[MAX_N][MAX_N] = {0}; // 노드를 간선으로 연결
	
typedef struct Queue {
	int front, rear;
	int data[MAX_N];
}Queue;
void check_dfs(int head, int N_count) {
	int temp;

	visited[head] = 1;
	printf("%d ", head);

	for (int i = 1; i <= N_count; i++) {
		if (arr[head][i] == 1) {
			temp = i;
			//printf("visited[temp] %d\n", visited[temp]);
			if (!visited[temp])
				check_dfs(temp, N_count);
		}	
	}
}
void check_bfs(int head, int N_count) {
	int there,here;
	Queue q;
	q.front = -1;
	q.rear = -1;

	visited_bfs[head] = 1;
	q.data[++q.rear] = head;

	while (q.front < q.rear) {
		here = q.data[++q.front];
		printf("%d ", here);
		
		for (int i = 1; i <= N_count; i++) {
			if (arr[here][i]) {
				there = i;

				if (!visited_bfs[there]) {
					visited_bfs[there] = 1;
					q.data[++q.rear] = there;
				}
			}
		}
	}
}

int main() {
	int N, M, V;
	int node1, node2;

	// N : 정점 개수
	// M : 간선 개수
	// V : 시작점(헤드)
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &node1, &node2);		
		arr[node1][node2] = 1; // 1 : 연결
		arr[node2][node1] = 1;
	}
	check_dfs(V, N);
	printf("\n");
	check_bfs(V, N);

	return 0;
}