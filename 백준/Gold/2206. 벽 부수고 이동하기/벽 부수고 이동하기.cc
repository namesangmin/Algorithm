#include <iostream>
#include <queue>
using namespace std;
bool visited[1001][1001][2];
char arr[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct node {
	int x;
	int y;
	int dist;
};

void bfs(int endX, int endY) {
	bool one_wall = true;
	queue<pair<node, bool>> q_pp;
	q_pp.push({ {1,1,1},one_wall });
	int result = 0;
	visited[1][1][0] = true;

	while (!q_pp.empty()) {
		int c_x = q_pp.front().first.x;
		int c_y = q_pp.front().first.y;
		int c_dist = q_pp.front().first.dist;
		bool is_wall = q_pp.front().second;
		q_pp.pop();

		// 처음으로 도달한 것이 최단 경로.. 1칸 씩 밖에 이동을 하지 않으니
		if (c_x == endX && c_y == endY) {
			cout << c_dist << "\n";
			return;
		}
		for (int i = 0; i < 4; i++) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];
			// 만약 다음 좌표가 1일 때 -> 0으로 바꿈
			// 그래도 다음 좌표가 1일 때, 걍 넣지 않음. pass

			// 1. 일단 좌표 만족
			if (n_x >= 1 && n_x <= endX && n_y >= 1 && n_y <= endY && !visited[n_y][n_x][is_wall]) {
				// 2. 다음 좌표가 0일 때
				if (arr[n_y][n_x] =='0') {
					q_pp.push({ {n_x,n_y,c_dist+1},is_wall });
					visited[n_y][n_x][is_wall] = true;

				}
				else {
					// 3. 다음 좌표가 1 인데 is_wall = t일 때
					if (is_wall) {
						q_pp.push({ {n_x,n_y,c_dist + 1},false });
						visited[n_y][n_x][is_wall] = true;
					}
				}
			}
		}
	}
	cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	bfs(M,N);
	return 0;
}