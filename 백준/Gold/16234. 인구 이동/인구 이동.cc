#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, L, R;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<int>> Map;
vector<vector<bool>> visited;
vector<pair<int, int>> Set;
queue<pair<int, int>> q;
void input() {
	cin >> N >> L >> R;
	Map.resize(N, vector<int>(N));
	visited.resize(N, vector<bool>(N));
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> Map[r][c];
		}
	}
}
bool bfs(int x, int y) {
	Set.clear();
	while (!q.empty()) q.pop();
	int total = 0, cnt = 1;
	q.push({ y,x });
	visited[y][x] = true;
	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		int cVal = Map[cy][cx];
		total += cVal;
		Set.push_back({ cy,cx });
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx]) {
				int nVal = Map[ny][nx];
				int diff = abs(nVal - cVal);
				if (L <= diff && R >= diff) {
					visited[ny][nx] = true;
					q.push({ ny,nx });
					cnt++;
				}
			}
		}
	}

	if (Set.size() == 1)return false;
	for (auto a : Set) {
		int cx = a.second;
		int cy = a.first;
		Map[cy][cx] = (int)(total / cnt);
	}
	return true;
}

int func() {
	int ans = 0;
	while (true) {
		bool isC = false;
		for (int i = 0; i < N; i++) 
			fill(visited[i].begin(), visited[i].end(), false);

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (!visited[r][c] && bfs(c,r)) {
					isC = true;
				}
			}
		}
		
		if (!isC) break;
		ans++;
	}
	return ans;
}

int main() {
	input();
	cout << func() << "\n";
	return 0;
}