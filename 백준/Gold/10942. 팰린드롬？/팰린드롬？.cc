#include <iostream>
#include <vector>

using namespace std;

int N, M;
int S, E;
vector<vector<bool>> dp;
vector<int> arr;

void func() {
	// 한 칸만 볼 때(기저)
	for (int i = 1; i <= N; i++) {
		dp[i][i] = true; // 자기 자신
	}
	// 두 칸만 볼 때 (기저)
	for (int i = 1; i < N; i++) {
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = true; // 인접한 2개
	}

	// 보려는 길이에 대한 값을 다 채움(길이)
	for (int len = 3; len <= N; len++) { 
		// 1번 idx부터 N번 idx까지 값을 채움
		for (int st = 1; st <= N - len + 1; st++) {
			int end = len + st - 1;
			if (arr[st] == arr[end] && dp[st + 1][end - 1]) dp[st][end] = true;
		}
	}
}
void input() {
	cin >> N;
	dp.resize(N + 1, vector<bool>(N + 1));
	arr.resize(N + 1);
	int temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	func();
	
	// print
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		cout << dp[S][E] << "\n";
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	input();
	return 0;
}
