#include <iostream>
#include <queue>
using namespace std;
int arr[301][301];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
struct node {
	int x, y;
};

void bfs(bool v[][301],int x , int y, int N, int M) {
	queue<node> q_node;
	v[y][x] = true;
	q_node.push({ x, y });

	while (!q_node.empty()) {
		int c_x = q_node.front().x;
		int c_y = q_node.front().y;
		q_node.pop();

		for (int i = 0; i < 4; i++) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			if (n_x > 0 && n_x <= M && n_y > 0 && n_y <= N) {
				if (!v[n_y][n_x] && arr[c_y][c_x] > 0 && arr[n_y][n_x] == 0) {
					arr[c_y][c_x]--;
					v[c_y][c_x] = true;
					q_node.push({ n_x, n_y });
				}
			}
		}
	}
}

void check_bfs(bool v[][301], int x, int y, int N, int M) {
	queue<node> q_node;
	v[y][x] = true;
	q_node.push({ x, y });

	while (!q_node.empty()) {
		int c_x = q_node.front().x;
		int c_y = q_node.front().y;
		q_node.pop();

		for (int i = 0; i < 4; i++) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			if (n_x > 0 && n_x <= M && n_y > 0 && n_y <= N) {
				if (!v[n_y][n_x] && arr[n_y][n_x] > 0) {
					v[n_y][n_x] = true;
					q_node.push({ n_x, n_y });
				}
			}
		}
	}
}
// N >> y
// M >> x
void loop(int N, int M) {
	int year = 0;
	while(true) {
		bool visited[301][301] = { false, };
		
		// 확인
		int land_count = 0;
		bool v[301][301] = { false, };
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!v[i][j] && arr[i][j] > 0) {
					check_bfs(v, j, i, N, M);
					land_count++;
					if (land_count >= 2) {
						cout << year << "\n";
						return;
					}
				}
			}
		}

		year++;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!visited[i][j] && arr[i][j] > 0) {
					bfs(visited, j, i, N, M);
				}
			}
		}
		if (land_count == 0){
			cout << "0\n";
			return;
		}
	}

}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	loop(N, M);
	return 0;
}