#include <iostream>
#include <cstring>
using namespace std;
int N, dp[10][100][1 << 10];
long long func(int n, int cnt, int m) {
	if (n >= 10 || n <= -1) return false;
	if(dp[n][cnt][m] != -1) return dp[n][cnt][m];
	if (cnt == N - 1) {
		return dp[n][cnt][m] = (m == (1 << 10) - 1) ? 1 : 0;
	}
	long long int v1 = func(n + 1, cnt + 1, m | (1 << (n + 1)));
	long long int v2 = func(n - 1, cnt + 1, m | (1 << (n - 1)));
	
	return dp[n][cnt][m] = (v1 + v2) % 1000000000;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N; 
	if (N < 10) {
		cout << 0 << "\n";
		return 0;
	}
	memset(dp, -1, sizeof(dp)); 
	// 0부터 시작을 할 수 없음
	long long ans = 0;
	for (int i = 1; i < 10; i++) {
		ans += func(i, 0, 1 << i);
	}
	cout << ans % 1000000000;

	return 0;
}