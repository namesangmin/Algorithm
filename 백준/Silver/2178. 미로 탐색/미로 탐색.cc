#include <iostream>
#include <queue>

using namespace std;
char route[101][101];
bool visited[101][101];
int Move[4][4] = { {1,0,0,-1},{0,-1,1,0} };
int Count[101][101];
int N, M;
void bfs(int x, int y) {
	queue<pair<int,int>> q_pair;
	// while로 돌면서 방문 했는지  확인
	// 아래 방식은 재귀함수를 사용했을 때, 방문했는지 확인하는 코드임(DFS)
	//if(visited[x][y])
	visited[x][y] = true;
	q_pair.push(make_pair(x,y));
	while (!q_pair.empty()) {
		int v = q_pair.front().first;
		int m = q_pair.front().second;
		q_pair.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = v + Move[0][i];
			int n_y = m + Move[1][i];
			// 제약 1. 격자 범위
			if ((n_x <= N && n_y <= M) && (n_x >= 1 && n_y >= 1)) {
				// 제약 2. 1인가? 그리고 방문했는가?
				if (route[n_x][n_y] == '1' && !visited[n_x][n_y]) {
					Count[n_x][n_y] = Count[v][m] + 1;
					visited[n_x][n_y] = true;
					q_pair.push(make_pair(n_x, n_y));
				}
			}
		}
	}
}
int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> route[i][j];
		}
	}
	// 시작점
	bfs(1,1);
	int result = Count[N][M] + 1;
	cout << result << "\n";
	return 0;
}