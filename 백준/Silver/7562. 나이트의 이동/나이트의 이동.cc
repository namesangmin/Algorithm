#include <iostream>
#include <queue>

using namespace std;
int dx[8] = { 1,1,-1,-1,2,-2,2,-2 };
int dy[8] = { 2,-2,2,-2,1,1,-1,-1 };

void bfs(int chess, int stX, int stY, int endX, int endY, bool v[][301]) {
	int dist = 0;
	queue<pair<pair<int, int>,int>> q_p;
	v[stY][stX] = true;
	q_p.push({ { stY,stX }, dist });

	while (!q_p.empty()) {
		int c_x = q_p.front().first.second;
		int c_y = q_p.front().first.first;
		int cost = q_p.front().second;
		q_p.pop();
		
		if (c_x == endX && c_y == endY) {
			cout << cost << "\n";
			return;
		}

		for (int i = 0; i < 8; i++) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];
			//cout << "next x : " << n_x << " next y : " << n_y << "\n";
			if ((n_x >= 0 && n_x < chess) && (n_y >= 0 && n_y < chess) && !v[n_y][n_x]) {
				//cout << " hi\n";
				v[n_y][n_x] = true;
				q_p.push({ {n_y,n_x},cost + 1 });
			}
		}
	}
}

int main() {
	int N, I, start_x, start_y, end_x, end_y;

	cin >> N;
	for (int i = 0; i < N; i++) {
		bool visited[301][301] = { false, };
		cin >> I;	
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;
		bfs(I, start_x, start_y, end_x, end_y, visited);
	}

	return 0;
}