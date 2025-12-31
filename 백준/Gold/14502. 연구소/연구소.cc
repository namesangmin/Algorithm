#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M, map[9][9], wall, ans;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct RowCol{
	int row, col;
};
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
}

// 1. 벽 세우기(전체 맵을 탐색해서 벽을 세워서 바이러스 퍼뜨려보기)
// - 벽을 세우고 되돌려야 함
// - 벽의 개수가 3개이면 바이러스 퍼뜨리기
// - 바이러스를 퍼뜨려보고 max 계산으로 더 많은 값으로 저장

void spreadVirus() {
	int temp_map[9][9];
	memcpy(temp_map, map, sizeof(map));

	queue<RowCol> q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (temp_map[i][j] == 2)
				q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int cx = q.front().col;
		int cy = q.front().row;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if ((nx >= 1 && nx <= M) && (ny >= 1 && ny <= N)) {
				if (temp_map[ny][nx] == 0) {
					temp_map[ny][nx] = 2;
					q.push({ ny, nx });
				}
			}
		}
	}

	int Count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (temp_map[i][j] == 0)
				Count++;
		}
	}
	ans = max(ans, Count);
}

void makeWall(int wall_count) {
	if (wall_count == 3) {
		spreadVirus();
		return;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				makeWall(wall_count + 1);
				map[i][j] = 0;
			}
		}
	}
}

void func() {
	makeWall(0);
	cout << ans << "\n";
}
int main() {
	input();
	func();
	return 0;
}