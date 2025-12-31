#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 99999999
using namespace std;
int N, D;
vector<pair<pair<int,int>,int>> v;
vector<int> dist;

void input() {
	cin >> N >> D;
	dist.resize(N + 1, MAX);
	dist[0] = 0;
	v.push_back({ {0,0},0 });
	int st, ed, val;

	for (int i = 1; i <= N; i++) {
		cin >> st >> ed >> val;
		v.push_back({ {st,ed},val });
	}
}

void calD(int curLocate, int idx) {
	for (int i = 1; i < v.size(); i++) {
		if (curLocate > v[i].first.first) continue; // 지금보다 작은 곳 못 지나감

		// v[i].first.first 가 더 크면 이제 다음에 어디로 갈지 찾음
		// 음.. 다 돌면 알아서 찾아지나
		int calLocate = (v[i].first.first - curLocate) + v[i].second + dist[idx];
		if (dist[i] > calLocate) {
			dist[i] = calLocate;
			calD(v[i].first.second, i);
		}
	}
}

int func() {
	int ans = D;

	calD(0, 0);
	// 거리 계산
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first.second > D)continue;
		int diff = D - v[i].first.second + dist[i];
		ans = min(ans, diff);
	}

	return ans;
}
int main() {
	input();
	cout << func() << "\n";
	return 0;
}