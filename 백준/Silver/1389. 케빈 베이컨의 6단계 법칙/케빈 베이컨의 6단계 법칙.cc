#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<bool> visited;
int N, M;
void input() {
	cin >> N >> M;
	v.resize(N + 1);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}
int bfs(int node) {
	queue<pair<int, int>> q;
	visited = vector<bool>(N + 1, false);
	
	q.push({ node, 0 });
	visited[node] = true;

	int cost = 0;
	while (!q.empty()) {
		int cNode = q.front().first;
		int val = q.front().second;
		q.pop();
		cost += val;

		for (int i = 0; i < v[cNode].size(); i++) {
			int nNode = v[cNode][i];

			if (!visited[nNode]) {
				q.push({ nNode, val + 1 });
				visited[nNode] = true;
			}
		}
	}
	return cost;
}

int func() {
	int ansCost = 99999999;
	int ansNode = 0;
	for (int i = 1; i <= N; i++) {
		int tmCost = bfs(i);
		if (ansCost > tmCost) {
			ansCost = tmCost;
			ansNode = i;
		}
	}
	return ansNode;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	input();
	cout << func() << "\n";

	return 0;
}