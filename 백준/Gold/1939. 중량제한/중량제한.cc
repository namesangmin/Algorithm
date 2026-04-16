#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 10000000000
using namespace std;
struct Info {
	int nodeNum;
	long long cost;
};
struct compare {
	bool operator()(const Info& a, const Info& b) {
		return a.cost < b.cost;
	}
};

vector<vector<pair<int, int>>> Map;
vector<long long> dist;
priority_queue<Info, vector<Info>, compare> pq;
int N, M, A, B, C, st, ed;
void input() {
	cin >> N >> M;
	Map.resize(N + 1);
	dist.resize(N + 1, 0);
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		Map[A].push_back({ B,C });
		Map[B].push_back({ A,C });
	}
	cin >> st >> ed;
}

long long func() {
	pq.push({ st, MAX });

	while (!pq.empty()) {
		auto nodeInfo = pq.top();
		int cNode = nodeInfo.nodeNum;
		long long cCost = nodeInfo.cost;
		pq.pop();
		if (cCost < dist[cNode]) continue;
		for (auto nNodeInfo : Map[cNode]) {
			int nNode = nNodeInfo.first;
			long long nCost = nNodeInfo.second;

			long long val = min(cCost, nCost);

			if (val > dist[nNode]) {
				dist[nNode] = val;
				pq.push({ nNode, dist[nNode] });
			}
		}
	}
	return dist[ed];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie();
	input();
	cout << func() << "\n";
	return 0;
}