#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visited[11][11][11][11];
struct info {
	int rx, ry;
	int bx, by;
	int cnt;
};
vector<vector<char>> arr;
pair<int, int> hole;
queue<info> q;
void input() {
	cin >> N >> M;
	arr.resize(N + 1, vector<char>(M + 1));
	pair <int, int> red;
	pair<int, int> blue;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> arr[r][c];
			if (arr[r][c] == 'O') {
				hole.first = r;
				hole.second = c;
			}
			if (arr[r][c] == 'R') red = { r,c };
			if (arr[r][c] == 'B') blue = { r,c };
		}
	}
	q.push({ red.second,red.first, blue.second, blue.first, 0 });
	visited[red.first][red.second][blue.first][blue.second] = true;
}
// 규칙 1. # 인 곳은 지나갈 수 없음
// 규칙 2. R, B가 동시에 구멍에 빠지면 안됨
// 규칙 3. R, B가 동시에 움직임
// 규칙 4. R, B가 한 칸에 동시에 존재할 수 없음

int Check(int& x, int& y, int idx) {
	int dist = 0;

	while (true) {
		int nx = x + dx[idx];
		int ny = y + dy[idx];

		if (arr[ny][nx] == '#') break;
		x = nx; y = ny; dist++;
		if (arr[ny][nx] == 'O') break;
	}
	return dist;
}
// 한 번 기울면 중간에 멈출 수 없으니 중간에 있는 visited를 갱신할 필요가 없을듯
// 끝에 닿으면 그떄의 위치를 리턴 -> 만약 가능하면 그 위치를 visited = true로 바꿈
int func() {
	int ans = -1;
	while (!q.empty()) {
		int redX = q.front().rx, redY = q.front().ry;
		int blueX = q.front().bx, blueY = q.front().by;
		int cnt = q.front().cnt;
		q.pop();
		if (cnt > 10) break;

		// 가장 먼저 나온 게 답임 -> cnt는 계속 증가
		if (redX == hole.second && redY == hole.first) {
			ans = cnt;
			break;
		}

		// 4 방향 조사
		for (int i = 0; i < 4; i++) {
			int n_rx = redX, n_ry = redY;
			int n_bx = blueX, n_by = blueY;

			int redMoveCnt = Check(n_rx, n_ry, i);
			int blueMoveCnt = Check(n_bx, n_by, i);
			
			if (arr[n_by][n_bx] == 'O') continue;
			if (n_rx == n_bx && n_ry == n_by) {
				if (redMoveCnt > blueMoveCnt) {
					n_rx -= dx[i];
					n_ry -= dy[i];
				}
				else {
					n_bx -= dx[i];
					n_by -= dy[i];
				}
			}

			if (!visited[n_ry][n_rx][n_by][n_bx]) {
				visited[n_ry][n_rx][n_by][n_bx] = true;
				q.push({ n_rx, n_ry, n_bx, n_by, cnt + 1 });
			}
		}
	}
	return ans;
}
int main() {
	input();
	cout << func() << "\n";
}