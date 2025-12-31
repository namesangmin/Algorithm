#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[101][101];
bool visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
struct node{
	int x, y;
};
vector <int>v;
void bfs(int x, int y, int M, int N) {
	visited[y][x] = true;
	queue<node> q_node;
	q_node.push({ x,y });
	int result = 0;
	while (!q_node.empty()) {
		int c_x = q_node.front().x;
		int c_y = q_node.front().y;
		q_node.pop();
		result++;
		for (int i = 0; i < 4; i++) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];
			if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < M) {
				if (!visited[n_y][n_x] && !arr[n_y][n_x]) {
					q_node.push({ n_x, n_y });
					visited[n_y][n_x] = true;
				}
			}
		}
	}
	v.push_back(result);
}
void loop(int M, int N) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && !arr[i][j]) {
				bfs(j, i, M, N);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i < v.size() - 1) cout << " ";
	}
	cout << "\n";
}
int main() {
	int M, N, K, sX, sY, eX, eY;
	cin >> M >> N >> K;
	for (int i = 1; i <= K; i++) {
		cin >> sX >> sY >> eX >> eY;

		for (int j = sY; j < eY; j++) {
			for (int k = sX; k < eX; k++) {
				arr[j][k] = 1;
			}
		}
	}
	loop(M, N);
	/*cout << N << " " << M << "\n";
	for (int j = 0; j < M; j++) {
		for (int k = 0; k < N; k++) {
			cout << arr[j][k] << " ";
		}
		cout << "\n";
	}*/
	return 0;
}