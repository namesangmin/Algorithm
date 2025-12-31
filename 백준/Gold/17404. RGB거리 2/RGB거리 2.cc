#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000001
using namespace std;
int N;
vector<vector<int>> vv, dp;

void input() {
	cin >> N;
	vv.resize(N + 1, vector<int>(3));
	dp.resize(N + 2, vector<int>(3, INF));

	int R,G,B;
	for (int i = 1; i <= N; i++) {
		cin >> R >> G >> B;
		vv[i][0] = R;
		vv[i][1] = G;
		vv[i][2] = B;
	}
}

int DP(int cur, int rgb, int stRgb) {
	if (cur == N + 1) {
		if (stRgb == rgb) return INF;
		return 0;
	}
	if (dp[cur][rgb] != INF) return dp[cur][rgb];
	
    // rgb와 다른 색을 선택해야 함.
	for (int i = 0; i < 3; i++) {
		// 선택
		if (rgb != i) {
			dp[cur][rgb] = min(vv[cur][i] + DP(cur + 1, i, stRgb), dp[cur][rgb]);
		}
	}

	return dp[cur][rgb];
}
int func() {
	int ans = INF;
	// 집 idx 2부터 시작
	for (int i = 0; i < 3; i++) {
		dp.assign(N + 2, vector<int>(3, INF));
		ans = min(ans, vv[1][i] + DP(2,i, i));
	}
	return ans;
}
int main() {
	input();
	cout << func() << "\n";
	return 0;
}