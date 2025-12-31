#include <iostream>
#include <queue>
#define MIN -1
using namespace std;
int arr[101][101];
int dx[4] = { 0, 0, -1 ,1 };
int dy[4] = { 1, -1, 0, 0 };
struct node {
	int x, y;
};
void bfs(int n, int currentH, bool v[][101], int startX, int startY) {
	queue<node> q_node;
	v[startY][startX] = true;
	// 0, 0 에서 시작 n, n 까지 조사
	q_node.push({ startX,startY });
	while (!q_node.empty()) {
		int c_x = q_node.front().x;
		int c_y = q_node.front().y;
		q_node.pop();

		for (int i = 0; i < 4; i++) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			if (n_x > 0 && n_x <= n && n_y > 0 && n_y <= n) {
				if (!v[n_y][n_x] && arr[n_y][n_x] >= currentH) {
					v[n_y][n_x] = true;
					q_node.push({ n_x,n_y });
				}
			}
		}
	}
}

void loop(int N, int getMax) {
	int maxArea = -1;
	for (int cH = 1; cH <= getMax; cH++) {
		int tempArea = 0;
		bool visited[101][101] = { false, };

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visited[i][j] && arr[i][j] >= cH) {
					bfs(N, cH, visited, j, i);
					tempArea++;
				}
			}
		}

		// 높이 중 가장 영역이 많은 애를 저장
		if (maxArea < tempArea) {
			maxArea = tempArea;
		}
	}
	cout << maxArea << "\n";

}
int main() {
	int N;
	int getMax = MIN;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > getMax) {
				getMax = arr[i][j];
			}
		}
	}
	loop(N, getMax);
	return 0;
}