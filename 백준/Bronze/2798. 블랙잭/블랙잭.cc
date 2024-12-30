#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];
int dp[101];
int N, M;

// N장 카드에 3장을 골라야 함
// 만약 더한 값이 M보다 크면 다시
// 선택 1. 카드를 선택할 것인가?
// 선택 2. 카드를 버릴 것인가?
int f(int n, int temp_sum, int Count) {
	if (Count == 3) {
		if (temp_sum <= M)return temp_sum;
		else
			return 0;
	}
	if (n > N) return 0;
	int Pcard = f(n+1,temp_sum+arr[n],Count+1);
	//cout << Pcard << "\n";
	int Ecard = f(n + 1, temp_sum, Count);
	//cout << Ecard << "\n";
	return max(Pcard, Ecard);
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int result = f(1,0,0);
	cout << result << "\n";
	return 0;
}