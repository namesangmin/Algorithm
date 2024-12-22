#include <iostream>

using namespace std;
// 1,2,3 합으로 나타내기
// n은 11보다 작음 1~10
long long int dp[1000001];
long long int f(long long int n) {
	// 이미 계산한 값이면 return;
	if (dp[n] > 0) { return dp[n]; }

	if (n > 0) {
		// n이 양수이면 계속 함수를 돈다.
		// 여기서 n 값을 조정하고 재귀함수
		return dp[n] = (f(n - 1) + f(n - 2) + f(n - 3))% 1000000009;
	}
	else if (n < 0) {
		// n이 음수이면 스탑(false), return 0
		return false;
	}
	else if (n == 0) {
		// n=0이면 나눠지는 것이므로 true, return 1
		return true;
	}
}
int main() {
	int n;
	int input;
	long long int result;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		result = f(input);
		cout << result << "\n";
	}
	return 0;
}