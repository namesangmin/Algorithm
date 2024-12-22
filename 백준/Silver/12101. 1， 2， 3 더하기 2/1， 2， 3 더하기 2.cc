#include <iostream>

using namespace std;
int N, M, check;
int dp[12][4];
int store[12];
int DP(int n,int m, int depth) {
	if (n < 0) return false;
	store[depth] = m;
	if (n == 0) {
  		check++;
		if (check == M) {
			for (int i = 0; i <= N; i++) { 
				if (store[i] != 0) {
					cout << store[i];
					if (i < N && store[i + 1] != 0) cout << "+";
				}
			}
			cout << "\n";
		}
		store[depth] = 0;
		return true;
	}
	//if (dp[n][m] != 0) return dp[n][m];

	return dp[n][m] = DP(n - 1, 1,depth+1) + DP(n - 2, 2,depth+1) + DP(n - 3, 3,depth+1);
}

int main() {
	cin >> N >> M;

	DP(N,0,0);

	if (check < M) {
		cout << "-1\n";
	}
	return 0;
}