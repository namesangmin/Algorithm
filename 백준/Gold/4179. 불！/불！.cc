#include <iostream>
#include <queue>
using namespace std;
bool visited[1001][1001];
char arr[1001][1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int	R, C, startX, startY;
struct node {
	int x, y, dist;
};
queue<node> q_node;

void bfs() {
	q_node.push({ startX,startY,1 });
	visited[startY][startX] = true;
	while (!q_node.empty()) {
		int cx = q_node.front().x;
		int cy = q_node.front().y;
		int dist = q_node.front().dist;
		q_node.pop();
		if (arr[cy][cx] == 'J') {
			if (cx == 1 || cx == C || cy == 1 || cy == R ) {
				cout << dist << "\n";
				return;
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 1 && nx <= C && ny >= 1 && ny <= R) {
				if (!visited[ny][nx] && arr[ny][nx] == '.') {
                    visited[ny][nx] = true;
					if (arr[cy][cx] == 'J') {
						arr[ny][nx] = 'J';
						q_node.push({ nx,ny,dist + 1 });
					}
					else if (arr[cy][cx] == 'F') {
						arr[ny][nx] = 'F';
						q_node.push({ nx,ny,dist });
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}
void input() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'F') {
				q_node.push({ j,i,1 });
				visited[i][j] = true;
			}
			else if (arr[i][j] == 'J') {
				startX = j;
				startY = i;
			}
		}
	}
}
int main() {
	input();
	bfs();
	return 0;
}