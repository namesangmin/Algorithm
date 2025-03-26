#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int bag[300001];
typedef pair<int, int> p;
struct compare {
	bool operator()(const p& a, const p& b) {
		return a.first > b.first;
	}
};
struct compare2 {
	bool operator()(const p& a, const p& b) {
		return a.second < b.second;
	}
};
bool c(const vector<int>& a, const vector<int>& b) {
	return a < b;
}
priority_queue<p, vector<p>, compare> pq_p;

priority_queue<p, vector<p>, compare2> pq_check;

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
			//cout << "a : " << a <<  " weight : " << weight << " value : " << value << "\n";

			if (a >= weight) {
				pq_check.push({ weight,value });
				pq_p.pop();
			}
			else
				break;
		}
		//cout << "re input : " << " weight : " << weight << " value : " << value << "\n";
		//pq_p.push({ weight,value });
		if (!pq_check.empty()) {
			//cout << " value : " << pq_check.top().second << "\n";
			result += pq_check.top().second;
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