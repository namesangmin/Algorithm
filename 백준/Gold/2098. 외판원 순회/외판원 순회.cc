#include <iostream>
#include <algorithm>
#define INF 99999999
using namespace std;
int N, W[16][16], dp[16][1<<16], minCost;

void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> W[r][c];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (1 << N); j++) {
			dp[i][j] = -1;
		}
	}
}
int func(int cur, int v) {
	// 길이 없을 때
	if (v == (1 << N)-1) {
		if (W[cur][0] != 0) return W[cur][0];
		else return INF;
	}
	if (dp[cur][v] != -1) return dp[cur][v];

	dp[cur][v] = INF;
	for (int i = 0; i < N; i++) {
		int Next = 1 << i;
		
		if (W[cur][i] == 0) continue;
		if (v & Next) continue;

		int nextV = v | Next;
		int Cost = W[cur][i] + func(i, nextV);
		dp[cur][v] = min(dp[cur][v], Cost);
	}
	return dp[cur][v];
}
int main() {
	input();
	int ans = func(0,1);
	cout << ans << "\n";
	return 0;
}