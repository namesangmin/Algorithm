#include <iostream>
#include <queue>
using namespace std;
int N, M, x, y, look;
int arr[50][50];
struct node {
	int x, y, look;
};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
void bfs() {
	queue<node> q_node;
	arr[y][x] = 2;
	q_node.push({ x,y,look });
	int result = 1;
	while (!q_node.empty()) {
		bool check = false;
		int cx = q_node.front().x;
		int cy = q_node.front().y;
		int c_look = q_node.front().look;
		q_node.pop();

		for (int i = 0; i < 4; i++) {
			// 4방향 둘러보기
			int n_look = (c_look + 3 - i) % 4;
			int nx = cx + dx[n_look];
			int ny = cy + dy[n_look];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (arr[ny][nx] == 0) {
					check = true;
					arr[ny][nx] = 2;
					q_node.push({ nx,ny,n_look });
					result++;
					break;
				}
			}
		}
		// 후진
		if (!check) {
			
			int bx = cx - dx[c_look];
			int by = cy - dy[c_look];
			if (arr[by][bx] == 1) {
				cout << result << "\n";
				return;
			}
			else {
				q_node.push({ bx,by, c_look });
			}
		}
	}
}

void input() {
	cin >> N >> M;
	cin >> y >> x >> look;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
}

int main() {
	input();
	bfs();
	return 0;
}