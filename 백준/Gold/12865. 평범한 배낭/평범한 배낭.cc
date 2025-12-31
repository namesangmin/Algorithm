#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
int dp[100001];
vector<pair<int, int>>v_p;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	v_p.resize(N+1);
	int weight, value;

	for (int i = 0; i < N; i++) {
		cin >> weight >> value;
		v_p[i].first = weight;
		v_p[i].second = value;
	}
	for (int i = 0; i < N; i++) {
		for (int j = K; j >= 0; j--) {
			if (v_p[i].first <= j)
				dp[j] = max(dp[j], dp[j - v_p[i].first] + v_p[i].second);
		}
	}
	cout << dp[K] << "\n";
	return 0;
}