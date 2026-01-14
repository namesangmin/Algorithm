#include <iostream>
#include <vector>

using namespace std;

// 자기 자신한테까지 와야하니까 [0] 값을 하나 더 추가함
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1, 0,-1 };

vector<vector<int>> arr, tmVec;
vector<pair<int, int>> Robot;
int R, C, T;
int topIdx, bottomIdx;
void input() {
	cin >> R >> C >> T;
	arr.resize(R, vector<int>(C));
	tmVec.resize(R, vector<int>(C, 0));

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> arr[r][c];
			// 무조건 먼저 나온게 위에
			if (arr[r][c] == -1) {
				Robot.push_back({ r,c });
				arr[r][c] = 0;
			}
		}
	}
}

// temp vector를 만들어거 그 vec에 업데이트
void diffuse() {
	// 먼지 확산
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if ((r == Robot[0].first && c == Robot[0].second) || (r == Robot[1].first && c == Robot[1].second)) continue;

			int curVal = arr[r][c];
			int diffuseVal = (int)(arr[r][c] / 5);
			
			// 음 하나 더 만들기 귀찮아서 그냥 공유하자
			for (int i = 0; i < 4; i++) {
				if (r + dy[i] < 0 || r + dy[i] >= R || c + dx[i] < 0 || c + dx[i] >= C) continue;
				if (r + dy[i] == Robot[0].first && c + dx[i] == Robot[0].second ||
					r + dy[i] == Robot[1].first && c + dx[i] == Robot[1].second) continue;

				tmVec[r + dy[i]][c + dx[i]] += diffuseVal;
				curVal -= diffuseVal;
			}
			tmVec[r][c] += curVal;
		}
	}
	arr = tmVec;
}

void XToEnd(int Sty, int Stx, int Endy, int Endx) {
	for (int x = Stx; x < Endx; x++) {
		arr[Sty][x+1] = tmVec[Sty][x];
	}
}
void EndToY(int Sty, int Stx, int Endy, int Endx) {
	for (int y = Sty; y > Endy; y--) {
		arr[y - 1][Stx] = tmVec[y][Stx];
	}
}
void EndToX(int Sty, int Stx, int Endy, int Endx) {
	for (int x = Stx; x > Endx; x--) {
		arr[Sty][x - 1] = tmVec[Sty][x];
	}
}
void YToEnd(int Sty, int Stx, int Endy, int Endx){
	for (int y = Sty; y < Endy; y++) {
		arr[y + 1][Stx] = tmVec[y][Stx];
	}
}
void dustMoveTop(int cy, int cx) {

	// 방향
	XToEnd(cy, 0, cy, C - 1);
	EndToY(cy, C - 1, 0, C - 1);
	EndToX(0, C - 1, 0, 0);
	YToEnd(0, 0, cy, 0);
}
void dustMoveBottom(int cy, int cx) {
	// 방향
	XToEnd(cy, 0, cy, C - 1);
	YToEnd(cy, C - 1, R - 1, C  - 1);
	EndToX(R - 1, C - 1, R - 1, 0);
	EndToY(R - 1, 0, cy, 0);
}
int func() {
	int ans = 0;

	// 미세먼지 -> 로봇
	for (int t = 0; t < T; t++) {
		tmVec.assign(R, vector<int>(C, 0));
		diffuse();
		dustMoveTop(Robot[0].first, Robot[0].second);
		dustMoveBottom(Robot[1].first, Robot[1].second);

		// 로봇위치 값 없애기
		arr[Robot[0].first][Robot[0].second] = 0;
		arr[Robot[1].first][Robot[1].second] = 0;
	}

	//정답 구하기
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			ans += arr[r][c];
		}
	}
	return ans;
}
int main() {
	input();
	cout << func() << "\n";
	return 0;
}