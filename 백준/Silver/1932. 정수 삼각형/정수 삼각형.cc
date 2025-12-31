#include <iostream>
#include <algorithm>

using namespace std;
int N;
int input[501][501];
int dp[501][501];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> input[i][j];
		}		
	}
	dp[1][1] = input[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			// dp에 이미 값이 있을 때 비교해서 더 큰 값 저장
			dp[i][j] = max(dp[i - 1][j-1], dp[i-1][j])+input[i][j];
		}
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[N][i] > result)
			result = dp[N][i];
	}
	cout << result << "\n";
	return 0;
}