#include <iostream>
#include <vector>
using namespace std;

vector<int> arr, dp;
int N;
int main() {
	cin >> N;
	int tm;
	arr.push_back(0);dp.push_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> tm;
		arr.push_back(tm);dp.push_back(1);
	}
	tm = 0;
	for (int i = 1; i <= N - 1; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (arr[i] < arr[j]) {				
				if (dp[i] >= dp[j]) {
					dp[j] = dp[i] + 1;
					if (tm < dp[j]) tm = dp[j];
				}
			}
		}
	}
	cout << N - tm << "\n";
	return 0;
}