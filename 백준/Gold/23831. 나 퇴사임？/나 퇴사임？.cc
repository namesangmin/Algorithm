#include <iostream>
#include <algorithm>
using namespace std;
int N, A, B;
int arr[101][4];
int dp[101][101][2][101];

// 일, 남은 공부 수, 남은 요양 수, 장소
int DP(int n, int Rstudy, bool lounge, int Rrest) {
	if (n <= 0) {
		if (Rstudy <= 0)return 0;
		else return -9999;
	}
	if (dp[n][Rstudy][lounge][Rrest] != 0) return  dp[n][Rstudy][lounge][Rrest];

	int &temp_result = dp[n][Rstudy][lounge][Rrest];
	temp_result = -9999;
	// 자습
	temp_result = max(temp_result, DP(n - 1, Rstudy - 1, true, Rrest) + arr[n][1]);
	
	// 휴게실(2)
	if(lounge)
		temp_result = max(temp_result, DP(n - 1, Rstudy, false, Rrest) + arr[n][2]);
	
	// 방
	if(Rrest > 0)
		temp_result = max(temp_result, DP(n - 1, Rstudy, true, Rrest-1) + arr[n][3]);

	return temp_result;
}

int main() {
	int input, p, q, r, s;
	cin >> N >> A >> B;

	for (int i = 1; i <= N; i++) {
		cin >> p >> q >> r >> s;
		if (p >= q) input = p;
		else input = q;
		arr[i][1] = input; arr[i][2] = r; arr[i][3] = s;
	}

	int result= DP(N, B, true, A);
	cout << result << "\n";
	return 0;
}