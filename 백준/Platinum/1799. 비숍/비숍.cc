#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = { 1,1,-1,-1 };
int dy[4] = { -1,1,-1,1 };
int N;
vector<vector<int>> arr;
vector<pair<int, int>> bList, wList;
void input() {
	cin >> N;
	// 1이 놓을 수 있음
	// 0이 놓을 수 없음
	arr.resize(N + 1, vector<int>(N + 1));
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> arr[r][c];
			if (arr[r][c] == 1) {
				if (((r + c) % 2) == 0) bList.push_back({ r,c });
				else wList.push_back({ r,c });
			}
		}
	}
}
// 그 위치에 놓을 수 있는지 판단.
bool check(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x;
		int ny = y;

		while (true) {
			nx += dx[i];
			ny += dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N) break;
			if (arr[ny][nx] == 2) return false;
		}
	}
	// 놓을 수 있으면 true
	return true; 
}
int dfs(const vector<pair<int,int>>& List, int idx, int cnt) {
	// 해당 위치에 놓을 수 있는지 확인.
	// 벽(1) 통과 o, 비숍(2) 만나면 x 
	// 4방향 조사
	int ans = cnt;
	for (int i = idx; i < List.size(); i++) {
		int cx = List[i].second;
		int cy = List[i].first;
		// 해당 점에 놓았을 때
		if (check(cx, cy)) {
			arr[cy][cx] = 2;
			int tmAns = dfs(List, i + 1, cnt + 1);
			ans = max(ans, tmAns);
			arr[cy][cx] = 1;
		}
	}
	return ans;
}

int main() {
	input();
	cout << dfs(bList, 0, 0) + dfs(wList, 0, 0) << "\n";
	return 0;
}