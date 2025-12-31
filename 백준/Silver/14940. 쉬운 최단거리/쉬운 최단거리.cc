#include <iostream>
#include <queue>

using namespace std;
int arr[1000][1000];
int result[1000][1000];
bool visited[1000][1000];
int M, N;
int start_x, start_y;
queue<pair<int, int>>v_p;
int dx[4] = { 0, 1,-1,0 };
int dy[4] = { -1,0,0,1 };
void bfs(int x, int y) {
	visited[y][x] = true;
	result[y][x] = 0;
	v_p.push(make_pair(x, y));
	while (!v_p.empty()) {
		int current_x = v_p.front().first;
		int current_y = v_p.front().second;
		v_p.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = dx[i] + current_x;
			int next_y = dy[i] + current_y;
			if ( (next_x >= 0 && next_x < M) && (next_y >= 0 && next_y < N)&& !visited[next_y][next_x]) {
				if (arr[next_y][next_x] == 1) {
					visited[next_y][next_x] = true;
					result[next_y][next_x] = result[current_y][current_x]+1;
					v_p.push(make_pair(next_x, next_y));
				}
			}
		}
	}
	// 결과 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j]==1 && !result[i][j]) {
				cout << "-1 ";
			}
			else {
				cout << result[i][j] << " ";
			}
		}
		cout << "\n";
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {	// y
		for (int j = 0; j < M; j++) {	// x
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				start_y = i;
				start_x = j;
			}
		}
	}
	bfs(start_x, start_y);
	return 0;
}
