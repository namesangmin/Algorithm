#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, node;
vector<vector<int>> v;
vector<bool> visited;
void input() {
	cin >> N >> M;
	v.resize(N + 1);
	visited.resize(N + 1, false);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}
	cin >> node;
}
int func() {
	int ans = 0;

	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty()) {
		int cNode = q.front();
		q.pop();

		for (int i = 0; i < v[cNode].size(); i++) {
			int nNode = v[cNode][i];
			if (!visited[nNode]) {
				q.push(nNode);
				visited[nNode] = true;
				ans++;
			}
		}
	}
	return ans;
}
int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
	input();
	cout << func() << "\n";

	return 0;
}