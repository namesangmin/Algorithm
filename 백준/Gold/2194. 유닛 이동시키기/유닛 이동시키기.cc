#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A, B, K, stY, stX, edY, edX;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int visited[501][501];
struct xy {
	int x, y;
	int moveCount;
};

void input() {
	cin >> N >> M >> A >> B >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		visited[y][x] = 2;
	}
	cin >> stY >> stX >> edY >> edX;
}
int func(int x, int y) {
	queue<xy> q;
	visited[stY][stX] = 1;
	q.push({ stX,stY,0 });
	int ans = 999999;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int moveC = q.front().moveCount;
		q.pop();
		if (cx == edX && cy == edY) {
			if (ans > moveC)
				ans = moveC;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 1 && nx <= M && ny >= 1 && ny <= N && !visited[ny][nx]) {
				// 움직였을 때, 4개 공간을 확인을 해.
				bool check = true;
				for (int r = 0; r < A; r++) {
					for (int c = 0; c < B; c++) {
						int X = c + nx;
						int Y = r + ny;
						if (((X < 1 || X > M) || (Y < 1 || Y > N)) || visited[Y][X] == 2) check = false;
 					}
				}
				if (check) {
					q.push({ nx,ny, moveC+1 });
					visited[ny][nx] = 1;
				}
			}
		}
	}
	if (ans == 999999) return -1;
	return ans;
}
int main() {
	input();
	cout << func(stX, stY) << "\n";
	return 0;
}