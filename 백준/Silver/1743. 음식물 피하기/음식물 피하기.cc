#include <iostream>

using namespace std;

int N, M, K;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool arr[101][101], visited[101][101];

void input() {
	int r, c;
	cin >> N >> M >> K;
	
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		arr[r][c] = true;
	}
}
int dfs(int r, int c, int Count) {

	visited[r][c] = true;
	Count++;

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + c;
		int ny = dy[i] + r;
		if (nx <= M && nx >= 1 && ny <= N && ny >= 1 && !visited[ny][nx] && arr[ny][nx]) {
			visited[ny][nx] = true;
			Count = dfs(ny, nx, Count);
		}
	}
	return Count;
}
void func() {
	int temp, ans = 0, Count = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (!visited[r][c] && arr[r][c]) {
				temp = dfs(r, c, 0);
				if (temp > ans)
					ans = temp;
			}
		}
	}
	cout << ans << "\n";
}
int main() {
	input();
	func();
	return 0;
}