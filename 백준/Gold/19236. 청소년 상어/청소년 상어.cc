#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int arr[4][4][2], ans, score = -1;
vector<pair<int, pair<int, int>>> v_pp;
bool eat[17];

bool Sort(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	return a.first < b.first;
}
void input() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cin >> arr[r][c][0] >> arr[r][c][1];
			v_pp.push_back({ arr[r][c][0], {r,c} });
		}
	}
	sort(v_pp.begin(), v_pp.end(), Sort);
}
void moveFish() {
	for (int i = 0; i < 16; i++) {
		int fishNum = v_pp[i].first;
		int cy = v_pp[i].second.first;
		int cx = v_pp[i].second.second;
		int moveWay = arr[cy][cx][1];
		if (!eat[fishNum]) {
			int nx = dx[moveWay] + cx;
			int ny = dy[moveWay] + cy;
			int moveCount = 0;
			if (nx >= 0 && nx <= 3 && ny >= 0 && ny <= 3 && arr[ny][nx][0] != -1) { // 이동 o
				int temp_fishNum = arr[ny][nx][0];
				int temp_moveWay = arr[ny][nx][1];

				arr[ny][nx][0] = fishNum;
				arr[ny][nx][1] = moveWay;

				arr[cy][cx][0] = temp_fishNum;
				arr[cy][cx][1] = temp_moveWay;

				v_pp[fishNum - 1].second.first = ny;
				v_pp[fishNum - 1].second.second = nx;
				if (temp_fishNum > 0) {
					v_pp[temp_fishNum - 1].second.first = cy;
					v_pp[temp_fishNum - 1].second.second = cx;
				}
			}
			else { // 이동 x
				for (int m = 1; m <= 8; m++) {
					int nd = (moveWay + m - 1) % 8 + 1;
					nx = dx[nd] + cx;
					ny = dy[nd] + cy;
					moveCount++;
					if (nx <= -1 || nx >= 4 || ny <= -1 || ny >= 4 || arr[ny][nx][0] == -1) continue;
					int temp_fishNum = arr[ny][nx][0];
					int temp_moveWay = arr[ny][nx][1];

					arr[ny][nx][0] = fishNum;
					arr[ny][nx][1] = nd;

					arr[cy][cx][0] = temp_fishNum;
					arr[cy][cx][1] = temp_moveWay;

					v_pp[fishNum - 1].second.first = ny;
					v_pp[fishNum - 1].second.second = nx;
					if (temp_fishNum > 0) {
						v_pp[temp_fishNum - 1].second.first = cy;
						v_pp[temp_fishNum - 1].second.second = cx;
					}
					break;
				}
			}
		}
	}
}
void dfs(int score, int x, int y) { // 백트랙킹으로 모든 조합을 찾아서 가장 큰 값을 리턴을 함. 한 번 이동
	// 만약에 더 이상 갈 곳이 없으면 리턴
	ans = max(ans, score);

	moveFish(); // 물고기 움직이고
	int dir = arr[y][x][1];
	// 상어가 움직여서 한 칸 ~ 세 칸 이동할 때
	for (int m = 1; m < 4; m++) {
		int nx = x + dx[dir] * m;
		int ny = y + dy[dir] * m;
		if (nx >= 0 && nx <= 3 && ny >= 0 && ny <= 3 && arr[ny][nx][0] > 0) { // 조건에 만족하면
			int arrCopy[4][4][2];
			bool eatCopy[17];
			auto v_ppCopy = v_pp;
			memcpy(arrCopy, arr, sizeof(arr));
			memcpy(eatCopy, eat, sizeof(eat));
			// 물고기를 먹고, 상어가 움직인다.
			int fishNum = arr[ny][nx][0];
			arr[y][x][0] = 0;
			arr[ny][nx][0] = -1;
			eat[fishNum] = true;
			dfs(fishNum + score, nx, ny);

			// 상태 복원
			v_pp = v_ppCopy;
			memcpy(arr, arrCopy, sizeof(arr));
			memcpy(eat, eatCopy, sizeof(eat));
		}
	}
}
void func() {
	// init
	int first = arr[0][0][0]; 
	eat[first] = true;
	arr[0][0][0] = -1;

	dfs(first, 0, 0);
}
int main() {
	input();
	func();
	cout << ans << "\n";
	return 0;
}