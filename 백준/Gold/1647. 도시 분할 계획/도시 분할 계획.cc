#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<pair<int, pair<int,int>>>vv; vector<int> p;
bool Sort(const pair<int, pair<int, int>>& x, const pair<int, pair<int, int>>& y) {
	return x.first < y.first;
}
void input() {
	cin >> N >> M;
	p.resize(N);
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		vv.push_back({ C,{A,B} });

	}
	sort(vv.begin(), vv.end(), Sort);
	for (int i = 0; i < N; i++) {
		p[i] = i;
	}
}

int findP(int n) {
	if (p[n] == n) return n;
	return p[n] = findP(p[n]);
}
void merge(int a, int b) {
	a = findP(a);
	b = findP(b);

	if (a != b) {
		p[a] = b;
	}
}
void func() {
	int V_size = vv.size();
	int Count = 0;
	int ans = 0;
	int costMax = -1;
	for (int i = 0; i < V_size; i++) {
		int a_node = vv[i].second.first;
		int b_node = vv[i].second.second;
		int cost = vv[i].first;
		if (findP(a_node) == findP(b_node))
			continue;

		merge(a_node, b_node);
		ans += cost;
		Count++;
		if (costMax < cost) costMax = cost;
		if (Count == N - 1) {
			ans -= costMax;
			break;
		}
	}
	cout << ans << "\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	func();
	return 0;
}