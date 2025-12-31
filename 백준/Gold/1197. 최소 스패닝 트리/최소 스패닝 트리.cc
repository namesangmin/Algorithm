#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V, E, A, B, C;
struct VE {
	int a, b;
};
vector<pair<int, VE>>vv;
vector<int> parent;

bool Sort(const pair<int, VE>& x, const pair<int, VE>& y) {
	return x.first < y.first;
}

void input() {
	cin >> V >> E;
	parent.resize(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		vv.push_back({ C,{A,B} });
	}
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	sort(vv.begin(), vv.end(), Sort);
}

int findParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = findParent(parent[a]);
}
void Union(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b)
		parent[b] = a;
}
void func() {
	int V_size = vv.size();
	int ans = 0;
	int Count = 0;
	for (int i = 0; i < V_size; i++) {
		int a_node = vv[i].second.a;
		int b_node = vv[i].second.b;
		int cost = vv[i].first;
		if (findParent(a_node) == findParent(b_node))
			continue;

		Union(a_node, b_node);
		
		ans = ans + cost;
		Count++;
		if (Count == V - 1) break;
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