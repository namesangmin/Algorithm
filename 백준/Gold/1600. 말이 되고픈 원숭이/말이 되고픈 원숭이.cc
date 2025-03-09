#include <iostream>
#include <queue>

using namespace std;
char arr[201][201];
bool visited[201][201][31];
int K, W, H;
// 시작 (0,0) 끝 (W,H);
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int Mx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int My[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
struct node {
	int x, y, dist,chance;
};
void bfs() {
	queue<node> q_node;
	visited[1][1][K] = true;
	q_node.push({ 1,1,0,K });

	while (!q_node.empty()) {
		int cx = q_node.front().x;
		int cy = q_node.front().y;
		int dist = q_node.front().dist;
		int chance = q_node.front().chance;
		q_node.pop();
		//cout << cx << " " << cy << " " << dist << " " << chance << "\n";
		if (cx == W && cy == H) {
			cout << dist << "\n";
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 1 && nx <= W && ny >= 1 && ny <= H) {
				if (!visited[ny][nx][chance] && arr[ny][nx] == '0') {
					// 없을 때.. 그냥 bfs
					visited[ny][nx][chance] = true;
					q_node.push({ nx,ny,dist + 1,chance });
				}
			}		
		}
		if (chance > 0) {
			for (int i = 0; i < 8; i++) {
				int nx = cx + Mx[i];
				int ny = cy + My[i];

				if (nx >= 1 && nx <= W && ny >= 1 && ny <= H) {
					if (!visited[ny][nx][chance-1] && arr[ny][nx] == '0') {
						visited[ny][nx][chance-1] = true;
						q_node.push({ nx,ny,dist + 1,chance - 1 });
					}
				}
			}
		}
	}
	cout << "-1\n";
}
void input() {
	cin >> K >> W >> H;;
	for(int i=1; i<=H; i++){
		for (int j = 1; j <= W; j++) {
			char temp;
			cin >> temp;
			if (temp != ' ')
				arr[i][j] = temp;
		}
	}
}
int main() {
	input();
	bfs();
	return 0;
}