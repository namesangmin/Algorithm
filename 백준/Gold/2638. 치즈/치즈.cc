#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> Map;
vector<vector<int>> visited;
queue<pair<int, int>> q;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int N, M;
void input() {
	cin >> N >> M;
	Map.resize(N + 1, vector<int>(M + 1,0));
	visited.resize(N + 1, vector<int>(M + 1, 0));
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> Map[r][c];
			if (r == 1 || r == N || c == 1 || c == M) {
				q.push({ r,c });
				visited[r][c] = 1;
			}
		}
	}
}
int func() {
	int ans = 0;
	queue<pair<int, int>>cheese;
	// 치즈인데 2번 카운트 된 것만 담음
	while (true) {
		if (q.empty()) break;
		ans++;

		while (!q.empty()) {
			int cx = q.front().second;
			int cy = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx >= 1 && nx <= M && ny >= 1 && ny <= N) {
					if (Map[ny][nx] == 0 && visited[ny][nx] == 0) {
						q.push({ ny,nx });
						visited[ny][nx] = 1;
					}

					if (Map[ny][nx] == 1) {
						visited[ny][nx]++; // 치즈이면 + 1(닿았음)을 함
						if (visited[ny][nx] >= 2) { // 치즈이고, 방문을 2번 했으면 cheese 큐에 넣고, 해당 자리를 0 으로 만듦
							cheese.push({ ny,nx });
							Map[ny][nx] = 0;
						}
					}
				}
			}
		}
		cheese.swap(q);
	}
	return ans - 1;
}
int main() {
	input();
	cout << func() << "\n";
	return 0;
}