#include <iostream>
#include <queue>

using namespace std;

char arr[1001][1001];
bool visited[1001][1001][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct node {
	int x, y, dist, wall;
};
int N, M, K;

void bfs(int stX, int stY) {
	queue<node> q_node;
	visited[stY][stX][0] = true;
	q_node.push({ stX,stY,1,0 });

	while (!q_node.empty()) {
		int cx = q_node.front().x;
		int cy = q_node.front().y;
		int dist = q_node.front().dist;
		int wall = q_node.front().wall;
		q_node.pop();
		// 탈출 조건
		if (cx == M && cy == N) {
			cout << dist << "\n";
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 1 && nx <= M && ny >= 1 && ny <= N) {
				if (!visited[ny][nx][wall] && wall <= K) {
					visited[ny][nx][wall] = true;
					// 다음 자리가 0일 때
					if (arr[ny][nx] == '0') {
						q_node.push({ nx,ny,dist + 1,wall });
					}
					// 다음 자리가 1일 때
					else {
						q_node.push({ nx,ny,dist + 1, wall +1 });
					}
				}
			}
		}
	}
	cout << "-1\n";
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	bfs(1, 1);
}
int main() {
	input();
	return 0;
}