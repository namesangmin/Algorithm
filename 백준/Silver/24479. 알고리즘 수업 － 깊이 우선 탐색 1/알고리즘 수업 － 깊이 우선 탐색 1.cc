#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, R, idx = 1;
vector<vector<int>> vv;
vector<int> ans;
vector<bool> visited;
void input() {
	cin >> N >> M >> R;
	vv.resize(N + 1);
	ans.resize(N + 1, 0);
	visited.resize(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int st, ed;
		cin >> st >> ed;
		vv[st].push_back(ed);
		vv[ed].push_back(st);

	}
	for (int i = 0; i < N; i++) {
		sort(vv[i].begin(), vv[i].end());
	}
}
void func(int node) {
	if (visited[node]) return;
	visited[node] = true;
	ans[node] = idx++;
	for (int n = 0; n < vv[node].size(); n++) {
		int nextNode = vv[node][n];
		if (!visited[nextNode]) {
			func(nextNode);
		}
	}
}
void Print() {
	for (int i = 1; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	func(R);
	Print();
	return 0;
}