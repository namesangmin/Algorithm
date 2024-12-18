#include <iostream>
#include <queue>
using namespace std;
// 색깔 : R, G, B
// 색맹 : R == G, B
// 색맹과 정상의 분류 개수?
// visited  없이 해 보자.
int N, normal , abnormal;
char arr[101][101];
bool visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void f(int x, int y, bool Check) {
	queue<pair<int, int>> q_p;
	q_p.push({ x,y });
	visited[y][x] = true;

	while (!q_p.empty()) {
		int c_x = q_p.front().first;
		int c_y = q_p.front().second;
		q_p.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];
			//cout << "c_x : " << c_x << " c_y : " << c_y << " n_x : " << n_x << " n_y : " << n_y << "\n";
			if ((n_x > 0 && n_x <= N) && (n_y > 0 && n_y <= N) && !visited[n_y][n_x]) {
				if (Check) {
					// 색맹의 경우
					if ((arr[n_y][n_x] == 'R' || arr[n_y][n_x] == 'G') && (arr[c_y][c_x] == 'R' || arr[c_y][c_x] == 'G')) {
						q_p.push({ n_x, n_y });
						visited[n_y][n_x] = true;
					}
					else if (arr[n_y][n_x] == 'B' && arr[c_y][c_x] == 'B') {
						q_p.push({ n_x, n_y });
						visited[n_y][n_x] = true;
					}
				}
				else {
					// 정상 시각의 경우
					if (arr[n_y][n_x] == arr[c_y][c_x]) {
						q_p.push({ n_x, n_y });
						visited[n_y][n_x] = true;
					}
				}
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}*/
	// 1번 돎
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				f(j, i, false);
				normal++;
			}
		}
	}
	// 초기화 처음부터 다시 돎 -> 색맹 구하기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = false;
		}
	}
	// 2번 돏
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				f(j, i, true);
				abnormal++;
			}
		}
	}
	cout << normal << "\n";
	cout << abnormal << "\n";

}