#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 999999999
using namespace std;
int N, M, K, X;
int result[300001];
vector<vector<int>> v;
struct node {
	int x, value;
	bool operator<(const node& a) const{
		return value > a.value;
	}
};
void bfs(int x) {
	priority_queue<node>pq;
	fill(result, result + N+1, INF);
	result[x] = 0;
	pq.push({ x, 0 });

	while (!pq.empty()) {
		int cx = pq.top().x;
		int c_value = pq.top().value;
		pq.pop();

		for (int i = 0; i < v[cx].size(); i++) {
			int nx = v[cx][i];
			int n_value = 1 + result[cx];

			if (n_value < result[nx]) {
				result[nx] = n_value;
				pq.push({ nx,n_value });
			}
		}
	}
}
void input() {
	cin >> N >> M >> K >> X;
	v.resize(N + 1);
	for (int i = 1; i <= M; i++) {
		int start, End;
		cin >> start >> End;
		v[start].push_back(End);
	}
}

void Print() {
	bool trigger = false;
	for (int i = 1; i <= N; i++) {
		if (result[i] == K) {
			cout << i << "\n";
			trigger = true;
		}
		
	}
	if (!trigger)
		cout << "-1\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	bfs(X);
	Print();

	return 0;
}