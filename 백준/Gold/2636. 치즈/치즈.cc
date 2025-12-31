#include<iostream>
#include<vector>
#include <queue>
using namespace std;
int R, C, resultTime, cnt;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<vector<int>> arr;
vector<vector<bool>> visited;
queue<pair<int, pair<int, int>>> makeZeroCheese;
void input() {
	cin >> R >> C;
	arr.resize(R + 1, vector<int>(C + 1));
	visited.resize(R + 1, vector<bool>(C + 1));

	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cin >> arr[r][c];
			if (r == 1 || r == R || c == 1 || c == C) {
				makeZeroCheese.push({ 0,{r,c} });
				visited[r][c] = true;
			}
		}
	}
}

void func() {
	//vector<int> ans(5001,0);
	queue<pair<int,pair<int, int>>> cheese;

	// 첫 번째 루프 -> 치즈 가장가리를 담는다.
	while (!makeZeroCheese.empty()) {
		int cx = makeZeroCheese.front().second.second;
		int cy = makeZeroCheese.front().second.first;
		int ct = makeZeroCheese.front().first;
		makeZeroCheese.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 1 && nx <= C && ny >= 1 && ny <= R && !visited[ny][nx]) {
				if (arr[ny][nx] == 0) makeZeroCheese.push({ ct, { ny,nx } });
				visited[ny][nx] = true;

				if (arr[ny][nx] == 1) {
					arr[ny][nx] = 0;
					cheese.push({ ct+1,{ ny,nx } });
					//ans[ct]++;
				}
			}
		}
	}
	// 가장 자리를 담았으니 다 없어질 때까지 돈다.
	while (!cheese.empty()) {
		cnt = cheese.size();
		resultTime = cheese.front().first;
		makeZeroCheese.swap(cheese);

		while (!makeZeroCheese.empty()) {
			int cx = makeZeroCheese.front().second.second;
			int cy = makeZeroCheese.front().second.first;
			int ct = makeZeroCheese.front().first;
			makeZeroCheese.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 1 && nx <= C && ny >= 1 && ny <= R && !visited[ny][nx]) {
					visited[ny][nx] = true;
					if (arr[ny][nx] == 0) makeZeroCheese.push({ ct,{ny,nx} });
					if (arr[ny][nx] == 1) {
						arr[ny][nx] = 0;
						cheese.push({ ct + 1,{ ny,nx } });
					}
				}
			}
		}
	}
}
int main() {
	input();
	func();
	cout << resultTime << "\n";
	cout << cnt << "\n";
	return 0;
}