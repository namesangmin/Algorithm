#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int N, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<int>> vv;
map<int, int> g;
vector<vector<bool>> visited;
void input() {
	cin >> N >> M;
	vv.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M));
	//ans.resize(N, vector<int>(M));

	char temp;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> temp;
			vv[r][c] = temp - '0';
		}
	}
}
void printAns() {
	int sum;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (vv[r][c] == 1) {
				sum = 1;
				map<int, bool> used;
				for (int i = 0; i < 4; i++) {
					int row = dy[i] + r;
					int col = dx[i] + c;
					if (row >= 0 && row < N && col >= 0 && col < M && vv[row][col] != 1) {
						int groupIdx = vv[row][col];
						if (!used[groupIdx]) {
							used[groupIdx] = true;
							sum += g[groupIdx];
						}
					}
				}
				cout << sum % 10;
			}
			else { cout << "0"; }
		}
		cout << "\n";
	}
}

int bfs(int row, int col, int idx) {
	int Count = 1;
	queue<pair<int, int>> q_p;
	q_p.push({ row,col });
	visited[row][col] = true;
	vv[row][col] = idx;
	while (!q_p.empty()) {
		int cx = q_p.front().second;
		int cy = q_p.front().first;
		q_p.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (vv[ny][nx] == 0 && !visited[ny][nx]) {
					visited[ny][nx] = true;
					vv[ny][nx] = idx;
					q_p.push({ ny,nx });
					Count++;
				}
			}
		}
	}
	return Count;
}

void func() {
	int idx = 2;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (!visited[r][c] && vv[r][c] == 0) {
				int Count = bfs(r, c, idx);
				g[idx] = Count;
				idx++;
			}
		}
	}
	printAns();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	func();
	return 0;
}