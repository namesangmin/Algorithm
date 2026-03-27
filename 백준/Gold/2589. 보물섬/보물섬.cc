#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int R, C;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<vector<char>> m;
vector<vector<bool>> v;
queue<pair<pair<int, int>, int>> q;
void input() {
	cin >> R >> C;
	char tm;
	m.resize(R, vector<char>(C));
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> tm;
			m[r][c] = tm;
		}
	}
}
int bfs(int r, int c) {
	q = queue<pair<pair<int, int>, int>>();
	q.push({ {r,c},0 });
	v[r][c] = true;
	int tmAns = 0;
	while (!q.empty()) {
		int cx = q.front().first.second;
		int cy = q.front().first.first;
		int cost = q.front().second;
		q.pop();
		tmAns = max(tmAns, cost);

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= C || ny < 0 || ny >= R || v[ny][nx]) continue;
			if (m[ny][nx] == 'W') continue;
			
			
			q.push({ {ny,nx},cost + 1 });
			v[ny][nx] = true;
		}
	}
	return tmAns;
}
int func() {
	int ans = 0;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (m[r][c] == 'W') continue;
			v.assign(R, vector <bool>(C, false));
			int tm = bfs(r, c);
			ans = max(tm, ans);
		}
	}

	return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	input();
	cout << func() << "\n";
	return 0;
}