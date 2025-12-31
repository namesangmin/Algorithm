#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int visited[1001][1001];
int mmap[1001][1001];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans = 0;

void go(int x, int y) {
	visited[x][y] = 1;
	int dir = mmap[x][y];
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (visited[nx][ny] == 0) go(nx, ny);
	if (visited[nx][ny] == 1) ans++; // 사이클 발견
	visited[x][y] = 2;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'U') mmap[i][j] = 0;
			else if (s[j] == 'D') mmap[i][j] = 1;
			else if (s[j] == 'L') mmap[i][j] = 2;
			else if (s[j] == 'R') mmap[i][j] = 3;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] != 0) continue;
			go(i, j);
		}
	}
	cout << ans;
	return 0;
}