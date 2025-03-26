#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq_p;
priority_queue<int> pq_check;
vector<int> v;

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int f_tm, s_tm;
		cin >> f_tm >> s_tm;
		pq_p.push({ f_tm, s_tm });
	}
	for (int i = 1; i <= K; i++) {
		int tm;
		cin >> tm;
		v.push_back(tm);
	}
}
void func() {
	long result = 0;
	int weight;
	int value;
	sort(v.begin(), v.end());
	for (auto a : v) {
		while (!pq_p.empty()) {
			weight = pq_p.top().first;
			value = pq_p.top().second;
			if (a >= weight) {
				pq_check.push(value);
				pq_p.pop();
			}
			else
				break;
		}
		if (!pq_check.empty()) {
			result += pq_check.top();
			pq_check.pop();
		}
	}
	cout << result << "\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	func();
	return 0;
}