#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 9999990099
using namespace std;

vector<int> dk(int start, int cost, int N, vector<vector<pair<int,int>>>& g, int end) {
	vector<int> dist(N + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ start,cost });
	dist[start] = cost;

	while (!pq.empty()) {
		int current_node = pq.top().first;
		int current_cost = pq.top().second;
		pq.pop();

		for (int i = 0; i < g[current_node].size(); i++) {
			int next_node = g[current_node][i].first;
			int next_cost = g[current_node][i].second + current_cost;

			if (next_cost < dist[next_node]) {
				dist[next_node] = next_cost;
				pq.push({ next_node, next_cost });
			}
		}
	}
	return dist;
}

void start(int N, int M, int X, vector<vector<pair<int,int>>>& vv_p) {
	vector<int> result(N + 1);
	// 1번째 다익스트라
	for (int i = 1; i <= N; i++) {
		// 결괏값 저장
		result[i] = dk(i, 0, N, vv_p, X)[X];
	}
	// 2번째 다익스트라
	int Max = -1;
	vector<int> temp_result = dk(X, 0, N, vv_p, -1);
	for (int i = 1; i <= N; i++) {
		Max = max(Max, result[i] + temp_result[i]);
	}

	cout << Max << "\n";
}
int main() {
	int N, M, X;
	vector<vector<pair<int, int>>> vv_p;

	cin >> N >> M >> X;
	vv_p.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int node_from, node_to, cost;
		cin >> node_from >> node_to >> cost;
		vv_p[node_from].push_back({ node_to, cost });
	}
	start(N,M,X, vv_p);
	return 0;
}