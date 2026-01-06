#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

vector<vector<char>>arr;
vector<vector<bool>>visited;
queue<pair<int, int>> q;
int N, M;
int W, B;

void input() {
	cin >> N >> M;
	arr.resize(M, vector<char>(N));
	visited.resize(M, vector<bool>(N, false));
	for (int r = 0; r < M; r++) {
		for (int c = 0; c < N; c++) {
			cin >> arr[r][c];
		}
	}
}

void bfs(int x, int y) {
	while (!q.empty()) q.pop();
	q.push({ y,x });
	visited[y][x] = true;
	int cnt = 0;
	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		cnt++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[ny][nx]) {
				if (arr[y][x] == arr[ny][nx]) {
					q.push({ ny,nx });
					visited[ny][nx] = true;
				}
			}
		}
	}
	if (arr[y][x] == 'W') W += cnt*cnt;
	else B += cnt * cnt;
}

void func() {
	for (int r = 0; r < M; r++) {
		for (int c = 0; c < N; c++) {
			if (!visited[r][c]) {
				bfs(c, r);
			}
		}
	}
	cout << W << " " << B << "\n";
}
int main() {
	input();
	func();
}