#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int> pq;
int N, M, K;
vector<int> v;

void func() {
	int ans = 0;
	int prevGood = 0;
	while (!pq.empty()) {
		int important = pq.top();
		pq.pop();
		int cal = important + (int)(prevGood / 2);
		prevGood = cal;
		important -= M;

		v.push_back(prevGood);
		ans++;
		if (important > K) {
			pq.push(important);
		}
	}
	cout << ans << "\n";
	for (auto a : v) {
		cout << a << "\n";
	}
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}
	func();

	return 0;
}