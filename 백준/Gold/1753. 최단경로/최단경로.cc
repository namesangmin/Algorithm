#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000
using namespace std;

int u, v, w, V, E, start;
vector<vector<pair<int, int>>> v_p;
vector<int> cost;

void bfs_dj(int start) {
	// 이동 cost, current node
	priority_queue<pair<int, int>> pq;
	cost[start] = 0;
	pq.push({0, start});

	while (!pq.empty()) {
		int c_move_cost = -pq.top().first;
		int c_node = pq.top().second;
		pq.pop();

		if (c_move_cost > cost[c_node]) continue;
		// c_node와 연결된 노드 찾고 push
		//cout << v_p[c_node].size() << "\n";
		for (int i = 0; i < v_p[c_node].size(); i++) {
			int n_node = v_p[c_node][i].first;
			int c = v_p[c_node][i].second;
			//cout << n_node << " : " << c << "\n";
			if (cost[c_node] + c < cost[n_node]) {
				cost[n_node] = cost[c_node] + c;
				pq.push({ -cost[n_node],n_node });
			}
		}
		/*
		for (auto a : v_p[c_node]) {
			int n_node = a.first;
			int c = a.second;
			if (cost[c_node] + c < cost[n_node]) {
				cost[n_node] = cost[c_node] + c;
				q.push(n_node);
			}
		}
		*/
	}
}

int main() {
	cin >> V >> E;
	cin >> start;
	v_p.resize(V + 1);
	cost.assign(V + 1, INF);
	for (int i = 1; i <= E; i++) {
		cin >> u >> v >> w;
		v_p[u].push_back({ v,w });
	}

	bfs_dj(start);

	for (int i = 1; i <= V; i++) {
		if (cost[i] == INF) cout << "INF\n";
		else cout << cost[i] << "\n";
	}
	return 0;
}