#include <iostream>
#include <queue>
using namespace std;
int N, M;
char arr[601][601];
bool visited[601][601];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int result;
int dooyeon_x;
int dooyeon_y;
void f(int x, int y) {
	queue<pair<int, int>> q_p;
	q_p.push({ x, y });
	visited[y][x] = true;

	while (!q_p.empty()) {
		int c_x = q_p.front().first;
		int c_y = q_p.front().second;
		q_p.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];
			//cout << "n_x : " << n_x << " n_y : " << n_y << " arr " << arr[n_x][n_y] << "\n";
			if ((n_x > 0 && n_x <= M) && (n_y > 0 && n_y <= N) && arr[n_y][n_x] != 'X' && !visited[n_y][n_x]) {
				//cout << n_y << " " << n_x << " " << arr[n_y][n_x] <<"\n";
				if (arr[n_y][n_x] == 'P') {
					result++;
				}
				visited[n_y][n_x] = true;
				q_p.push({ n_x, n_y });
			}
		}
	}
}

int main() {
   	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'I') {
				dooyeon_x = j;
				dooyeon_y = i;
			}
		}
	}
	//cout << dooyeon_x << " " << dooyeon_y << "\n";
	f(dooyeon_x, dooyeon_y);
	if (result == 0) {
		cout << "TT\n";
	}
	else {
		cout << result << "\n";

	}
	return 0;
}