#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, K, X, Y, W;
vector<int> buildingCost;
vector<int> buildingSum;
vector<vector<int>> way;
void input() {
	int In, Out;

	cin >> N >> K; // 건물 N, 규칙 K
	buildingCost.clear();
	buildingSum.clear();
	way.clear();

	buildingCost.resize(N + 1, -1);
	buildingSum.resize(N + 1, -1);
	way.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> buildingCost[i];
	}
	for (int i = 0; i < K; i++) {
		cin >> In >> Out;
		way[Out].push_back(In);
	}
	cin >> W; // 시작 포인트, 승리 건물
}

int dfs(int cB) {
	if (buildingSum[cB] != -1) return buildingSum[cB];

	int maxC = 0;
	for (int i = 0; i < way[cB].size(); i++) {
		int nB = way[cB][i];
		maxC = max(maxC, dfs(nB));
	}
	buildingSum[cB] = maxC + buildingCost[cB];

	return buildingSum[cB];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		input();
		cout << dfs(W) << "\n";
	}
}