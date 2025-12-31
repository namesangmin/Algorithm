#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int child, cost;
};
vector<vector<node>>vv;
bool visited[10001];
int max_cost, far_node;
void dfs(int c_node, int cost) {
	visited[c_node] = true;
	//cout << "c_node : " << c_node << " cost : " << cost << "\n";
	if (max_cost < cost) {
		max_cost = cost;
		far_node = c_node;
	}
	for (unsigned int i = 0; i < vv[c_node].size(); i++) {
		int n_node = vv[c_node][i].child;
		int n_cost = vv[c_node][i].cost;

		if (!visited[n_node]) {
			dfs(n_node, cost + n_cost);
		}
	}
}
int main() {
	int n;
	int parent, child, cost;
	cin >> n;
	vv.resize(n+1);
	for (int i = 0; i < n-1; i++) {
		cin >> parent >> child >> cost;
		vv[parent].push_back({ child,cost });
		vv[child].push_back({ parent, cost });
	}
	dfs(1, 0);

	fill(visited, visited + n + 1, false);
	max_cost = 0;

	dfs(far_node, 0);
	cout << max_cost << "\n"; 
	return 0;
}