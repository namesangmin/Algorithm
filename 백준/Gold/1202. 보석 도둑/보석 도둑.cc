#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq_p; 
priority_queue<int> pq; 
vector<p> v;

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int w, c;
		cin >> w >> c;
		v.push_back({ w, c });
	}
	for (int i = 0; i < K; i++) {
		int w;
		cin >> w;
		pq_p.push({ w, 0 }); 
	}
}

void func() {
	long long result = 0;
	int idx = 0;

	sort(v.begin(), v.end());

	while (!pq_p.empty()) {
		int now_cap = pq_p.top().first;
		pq_p.pop();

		while (idx < N && v[idx].first <= now_cap) {
			pq.push(v[idx].second); 
			idx++;
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	func();
	return 0;
}
