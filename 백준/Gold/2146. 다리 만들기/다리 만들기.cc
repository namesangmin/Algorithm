#include <iostream>
#include <queue>
#include <cstring>
#define INF 99999999
using namespace std;

int arr[101][101];
int N;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool visited[101][101];
struct node {
	int x, y, dist;
};

// 라벨 붙이기
void LandLabel(int x, int y, int labelNum) {
	queue<node> q_node;
	memset(visited, 0, sizeof(visited));

	q_node.push({ x,y,0 });
	visited[y][x] = true;
	arr[y][x] = labelNum;

	while (!q_node.empty()) {
		int cx = q_node.front().x;
		int cy = q_node.front().y;
		q_node.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
				if (!visited[ny][nx] && arr[ny][nx] != 0) {
					visited[ny][nx] = true;
					arr[ny][nx] = labelNum;
					q_node.push({ nx,ny,0});
				}
			}
		}
	}
}
int bfs(int x, int y, int label) {
	queue<node> q_node;
	memset(visited, 0, sizeof(visited));

	visited[y][x] = true;
	q_node.push({ x,y,0 });

	while (!q_node.empty()) {
		int cx = q_node.front().x;
		int cy = q_node.front().y;
		int dist = q_node.front().dist;
		q_node.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
				if (arr[ny][nx] != 0 && arr[ny][nx] != label) return dist;
				if (!visited[ny][nx] && arr[ny][nx] == 0) {
					visited[ny][nx] = true;
					q_node.push({ nx,ny, dist + 1 });
				}
			}
		}
	}
	return INF;
}

void loop() {
	// 라벨 먼저 붙이기
	int label = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && arr[i][j]) {
				LandLabel(j, i, label);
				label++;
			}
		}
	}

	int result = INF;
	for (int k = 1; k < label; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visited[i][j] && arr[i][j] == k) {
					int temp = bfs(j, i, k);
					if (temp < result)
						result = temp;
				}
			}
		}
	}
	cout << result << "\n";
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int input;
			cin >> input;
			if (input == 1)
				arr[i][j] = input;
		}
	}
	loop();
}
int main() {
	input();
	return 0;
}