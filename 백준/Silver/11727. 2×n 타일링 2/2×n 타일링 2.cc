#include <iostream>

using namespace std;
int dp[1001];
int find(int n) {
	if (dp[n] != 0)return dp[n];

	if (n < 0)
		return false;
	else if (n == 0)
		return true;

	return dp[n] = (find(n - 1) + 2*find(n - 2)) % 10007;
}

int main() {
	cin.tie(0);
	iostream::sync_with_stdio(0);
	int n;
	cin >> n;
	int result = find(n);
	cout << result << "\n";
	return 0;
}