#include <iostream>
#include <queue>
using namespace std;
int visited[100001];
int dist[100001];
int cx[3] = { 2, -1,1 };
int bfs(int a, int b) {
	queue<int> q;
	q.push(a);
	visited[a] = true;
	dist[a] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == b)
			return dist[x];

		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 0)
				nx = 2 * x;
			else {
				nx = x + cx[i];
			}
			if (nx >= 0 && nx <= 100000 && !visited[nx]) {
				q.push(nx);
				visited[nx] = true;
				if (i == 0) {
					dist[nx] = dist[x];
				}
				else {
					dist[nx] = dist[x] + 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	int N, K;
	cin >> N >> K;
	int result = bfs(N, K);
	cout << result << "\n";
	return 0;
}
