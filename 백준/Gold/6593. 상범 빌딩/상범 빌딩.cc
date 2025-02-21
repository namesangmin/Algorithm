#include <iostream>
#include <queue>
#include<cstring>
using namespace std;
int L, R, C;
bool visited[31][31][31];
char arr[31][31][31];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
struct node {
	int x, y, z, minute;
};
int bfs(int x, int y, int z) {
	queue<node> q_node;
	visited[z][y][x] = true;
	q_node.push({ x,y,z,0 });

	while (!q_node.empty()) {
		int c_x = q_node.front().x;
		int c_y = q_node.front().y;
		int c_z = q_node.front().z;
		int c_minute = q_node.front().minute;
		q_node.pop();

		if (arr[c_z][c_y][c_x] == 'E') {
			return c_minute;
		}

		for (int i = 0; i < 6; i++) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];
			int n_z = c_z + dz[i];
			if (n_x > 0 && n_x <= C && n_y > 0 && n_y <= R && n_z > 0 && n_z <= L) {
				if (!visited[n_z][n_y][n_x] && arr[n_z][n_y][n_x] != '#') {
					visited[n_z][n_y][n_x] = true;
					q_node.push({ n_x, n_y, n_z, c_minute + 1 });
				}
			}
		}
	}
	return -1;
}

void input() {
	while (true) {
		int startX, startY, startZ;
		memset(visited, false, sizeof(visited));
		memset(arr, 0, sizeof(visited));
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) {
			return;
		}
		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= R; j++) {
				for (int k = 1; k <= C; k++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S') {
						startX = k;
						startY = j;
						startZ = i;
					}	
				}
			}
		}
		int result = bfs(startX, startY, startZ);
		if (result > 0) 
			cout << "Escaped in " << result << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}
}
int main() {
	input();


	return 0;
}