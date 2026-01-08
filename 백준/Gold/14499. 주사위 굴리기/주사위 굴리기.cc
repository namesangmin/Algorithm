#include <iostream>
#include <vector>

using namespace std;

int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int diceX[4], diceY[4];
int N, M, x, y, K;
vector<vector<int>>arr;
void input() {
	cin >> N >> M >> y >> x >> K;
	arr.resize(N, vector<int>(M));
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> arr[r][c];
		}
	}
}
// 1 동 | 2 서 | 3 북 | 4 남
// 오른쪽(왼쪽)으로 두 번 갔을 때 diceX의 bottom에서 diceY의 Top부분이 나옴
	// 그러면 diceX Top 부분에서, diceY의 bottom 부분이 나옴

void func() {
	// init 
	int dir, cIdx_X = 0; int cIdx_Y = 0; // x축, y 축

	for (int i = 0; i < K; i++) {
		cin >> dir;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

		if (dir == 1 || dir == 2) {
			// x축 
			cIdx_X = (cIdx_X + dx[dir] + dy[dir] + 4) % 4;

			// 맵이 0이면 주사위의 bottom에 있는 값을 복사
			if (arr[ny][nx] == 0) arr[ny][nx] = diceX[((cIdx_X + 2) % 4)];
			else {
				int bottomVal = arr[ny][nx]; arr[ny][nx] = 0;
				diceX[((cIdx_X + 2) % 4)] = bottomVal;
			}

			diceY[(cIdx_Y + 2) % 4] = diceX[(cIdx_X + 2) % 4]; // bottom부분 탑으로
			diceY[cIdx_Y] = diceX[cIdx_X]; // top부분 bottom으로
		}
		else {
			// y축
			cIdx_Y = (cIdx_Y + dx[dir] + dy[dir] + 4) % 4;

			// 맵이 0이면 주사위의 bottom에 있는 값을 복사
			if (arr[ny][nx] == 0) arr[ny][nx] = diceY[(cIdx_Y + 2) % 4];
			else {
				int bottomVal = arr[ny][nx]; arr[ny][nx] = 0;
				diceY[(cIdx_Y + 2) % 4] = bottomVal;
			}

			diceX[(cIdx_X + 2) % 4] = diceY[(cIdx_Y + 2) % 4];
			diceX[cIdx_X] = diceY[cIdx_Y];
		}

		x = nx; y = ny;
		if (dir == 1 || dir == 2) cout << diceX[cIdx_X] << "\n";
		else cout << diceY[cIdx_Y] << "\n";
	}
}
int main() {
	input();
	func();
	return 0;
}