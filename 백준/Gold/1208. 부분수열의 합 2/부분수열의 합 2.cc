#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int S, N;
vector<int> L, R, Lm, Rm;
void input() {
	cin >> N >> S;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (i <= N / 2) L.push_back(temp);
		else R.push_back(temp);
	}
}
// 왼쪽 부분집합 구하기
void Make(vector<int>& m, vector<int>& arr, int idx, int sum) {
	if (idx == arr.size()) {
		m.push_back(sum);
		return;
	}
	Make( m, arr, idx + 1, sum);
	Make( m, arr, idx + 1, sum + arr[idx]);
}
long long func() {
	long long ans = 0;
	Make(Lm, L, 0, 0);
	Make(Rm, R, 0, 0);
	sort(Rm.begin(), Rm.end());

	for (int i = 0; i < Lm.size(); i++) {
		int val = S - Lm[i];
		auto lower = lower_bound(Rm.begin(), Rm.end(), val);
		auto upper = upper_bound(Rm.begin(), Rm.end(), val);
		ans += (upper - lower);
	}
	if (S == 0) ans--; // 공집합 제외
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	cout << func() << "\n";
	return 0;
}
