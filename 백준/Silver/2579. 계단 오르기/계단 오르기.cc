#define INF -99999999
#include <iostream>
#include <algorithm>

using namespace std;
int stair_num[301];
int dp[301][3];
int stair;
int DP(int n, int check) {
	if (dp[n][check] != 0) return dp[n][check];
	if (n > stair) return INF;
	if (n == stair) return stair_num[n]; // 마지막 계단

	int stair_value = stair_num[n];
	//cout << "stair_value : " << stair_value << "\n";
	//cout <<"n : " << n << " check : " << check << "\n\n";

	// 1 계단 씩 올랐을 때, 3개 연속 밟으면 안됨
	if (check < 2) {
		dp[n][check] = max(dp[n][check], DP(n + 1, check + 1) + stair_value);
	}
	// 2 계단
	dp[n][check] = max(dp[n][check], DP(n + 2, 1) + stair_value);
	return dp[n][check];
}
int main() {
	cin >> stair;
	for (int i = 1; i <= stair; i++) {
		cin >> stair_num[i];
	}
	int result = DP(0,0);
	cout << result << "\n";
	return 0;
}