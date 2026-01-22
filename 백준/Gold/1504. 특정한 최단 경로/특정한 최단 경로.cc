#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2000000001
using namespace std;
int N, E;
int a, b, c, v1, v2;

vector<vector<pair<int, int>>> v;
vector<int> CostMap;
void input() {
	cin >> N >> E;
	v.resize(N + 1);
	CostMap.resize(N + 1, INF);
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
}
void dk(int node) {
	CostMap.assign(N + 1, INF);
	CostMap[node] = 0;

	queue<int> q;
	q.push(node);

	while (!q.empty()) {
		int cNode = q.front();
		int cCost = CostMap[cNode];
		q.pop();

		for (int i = 0; i < v[cNode].size(); i++) {
			int nNode = v[cNode][i].first;
			int nCost = v[cNode][i].second;

			if (nCost + cCost < CostMap[nNode]) {
				CostMap[nNode] = nCost + cCost;
				q.push(nNode);
			}
		}
	}
}
int func() {
	int ans = 0;
	// v1 -> v2 의 최솟값 구하기
	// 구하면 1번과 N번의 최소값이 나옴
	dk(v1);
	int Dist_v1_To_v2 = CostMap[v2];
	if (CostMap[N] == INF) {
		ans = -1;
		return ans;
	}
	dk(1);
	int firstV1 = CostMap[v1];
	int firstV2 = CostMap[v2];

	dk(N);
	int secondV1 = CostMap[v1];
	int secondV2 = CostMap[v2];
	
	int cmp = min(firstV1 + secondV2, firstV2 + secondV1);

	ans = cmp + Dist_v1_To_v2;


	return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	input();
	cout << func() << "\n";
	return 0;
}