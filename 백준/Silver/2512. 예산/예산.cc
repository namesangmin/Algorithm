#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, Max;
vector<int> v;
void input() {
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (Max < temp) Max = temp;
		v.push_back(temp);
	}
	cin >> M;
}
int func() {
	int ans = 0;
	int left = 0, right = Max;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += min(mid, v[i]);
		}
		// 가능함 -> 그러면 더 늘림
		if (sum <= M) {
			left = mid + 1;
			ans = mid;
		}
		else { // 불가능 -> 더 줄임
			right = mid - 1;
		}
	}
	return ans;
}
int main() {
	input();
	cout << func() << "\n";
	return 0;
}