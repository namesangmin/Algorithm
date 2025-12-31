#include <iostream>

using namespace std;
int N;
int dp[46];
int DP(int n) {
	if (n <= 0) return 0;
	if (dp[n]) return dp[n];

	return dp[n] = DP(n - 1) + DP(n - 2);
}

void input() {
	cin >> N;
}
int main() {
	input();
	dp[0] = 0;
	dp[1] = 1;

	cout << DP(N) << "\n";

	return 0;
}