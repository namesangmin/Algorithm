#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int T, N, M;
vector<vector<int>> v;
vector<int>m;
queue<int> q;
bool func();
void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		v.assign(N + 1, vector<int>());
		m.assign(N + 1, -1);
		
		int a, b;
		for (int j = 0; j < M; j++) {
			cin >> a >>  b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		if (func()) cout << "YES\n";
		else cout << "NO\n";
	}
}

bool bfs(int node) {
	q = queue<int>();
	q.push(node);

	while (!q.empty()) {
		int cNode = q.front();
		q.pop();

		for (int i = 0; i < v[cNode].size(); i++) {
			int nNode = v[cNode][i];

			if (nNode == cNode) continue;
			if (m[cNode] == m[nNode])return false;

			if (m[nNode] == -1) {
				q.push(nNode);
				m[nNode] = m[cNode] ^ 1;
			}
		}
	}
	return true;
}

bool func() {
	for (int i = 1; i <= N; i++) {
		if (m[i] == -1) {
			m[i] = 1;
			if (!bfs(i)) return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	return 0;
}