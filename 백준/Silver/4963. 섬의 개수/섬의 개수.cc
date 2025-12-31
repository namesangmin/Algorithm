#include <iostream>
#include <queue>

using namespace std;
queue<pair<int, int>>q_p;
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
void bfs(bool a[][51], bool Check[][51], int height, int width) {
	while (!q_p.empty()) {
		int c_x = q_p.front().second;
		int c_y = q_p.front().first;
		q_p.pop();
		for (int i = 0; i < 8; i++) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];
			if ((n_x > 0 && n_x <= width) && (n_y > 0 && n_y <= height)	&& !Check[n_y][n_x]){
				Check[n_y][n_x] = true;
				if (a[n_y][n_x] == 1) {
					q_p.push({ n_y,n_x });
				}
			}
		}
	}
}
int main() {
	while (true) {
		int result = 0;
		bool arr[51][51];
		bool visited[51][51] = { false, };
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (!visited[i][j] && arr[i][j] == 1) {
					visited[i][j] = true;
					q_p.push({ i,j });
					bfs(arr, visited, h, w);
					result++;
				}
			}
		}
		cout << result << "\n";
	}
}