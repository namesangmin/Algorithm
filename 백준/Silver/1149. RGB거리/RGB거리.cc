#include <iostream>
#include <algorithm>
#define INF_COST 99999999
using namespace std;
int N;
int arr[1001][4];
int dp[1001][4];
int DP(int n, int cur_signal, int next_signal) {
	if (n > N)return false;
	if (dp[n][cur_signal] != 0) return dp[n][cur_signal];
	
	// 이미 있는 값(dp)과 arr 값을 비교
	// 다음 집 색깔 동일한 것을 색칠하지 말아야 함.
	// 2개 집 (i와 i+1)을 봐야 함
	int houseCost = arr[n][cur_signal];
	//cout <<"houseCode " << houseCost << " dp, n "<< n << " cur_signal " << cur_signal << " next_signal "<< next_signal << " dp value " << dp[n][cur_signal] << "\n";
	// 다른 색깔일 때
	dp[n][cur_signal] = INF_COST; 
	for (int next_signal = 1; next_signal <= 3; next_signal++) {
		// 같은 색깔이면 pass
        if (cur_signal != next_signal) {
			dp[n][cur_signal] = min(dp[n][cur_signal], houseCost + DP(n + 1, next_signal, cur_signal));
		}
	}
	return dp[n][cur_signal];
}

int main(){
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][1] >> arr[i][2] >> arr[i][3];		
	}
	int result = min({ DP(1, 1, -1), DP(1,2,-1), DP(1,3,-1) });
	cout << result << "\n";
	return 0;
}