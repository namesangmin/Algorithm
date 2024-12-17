#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
// M 상자의 가로
// N 상자의 세로
// H 쌓아 올려지는 상자의 수
int M, N, H;
int arr[101][101][101]; // [h] [y] [x]
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<pair< pair<int, int>, int>>q_pp;
void f() {

	while (!q_pp.empty()) {
		int c_x = q_pp.front().first.first;
		int c_y = q_pp.front().first.second;
		int c_z = q_pp.front().second;
		q_pp.pop();
		for (int i = 0; i < 6; i++) {
			int n_x = dx[i] + c_x;
			int n_y = dy[i] + c_y;
			int n_z = dz[i] + c_z;
			if (n_x > 0 && n_x <= M && n_y > 0 && n_y <= N && n_z > 0 && n_z <= H) {
				if (arr[n_z][n_y][n_x] == 0) {
					arr[n_z][n_y][n_x] = arr[c_z][c_y][c_x] + 1;
					q_pp.push({ {n_x,n_y},n_z });

				}
			}
		}
	}
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
	cin >> M >> N >> H;
	// N개의 줄
	// 각 줄에는 상자 가로줄이 들어있는 토마토들의 상태
	// 1 익은 토마토
	// 0 익지 x 토마토
	// -1 토마토 없음
	for (int h = 1; h <= H; h++) {
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= M; x++) {
				cin >> arr[h][y][x];
				// 익은 토마토 저장
				if (arr[h][y][x] == 1) {
					q_pp.push({ {x, y}, h });
				}
			}
		}
	}
	
	f();

	// check
	int result = 0;
	for (int h = 1; h <= H; h++) {
		for (int y = 1; y <= N; y++)   {
			for (int x = 1; x <= M; x++) {
				if (arr[h][y][x] == 0) {
					cout << "-1\n";
					return 0;
				}
				result = max(result, arr[h][y][x]);
			}
		}
	}
	cout << result-1 << "\n";
	return 0;
}