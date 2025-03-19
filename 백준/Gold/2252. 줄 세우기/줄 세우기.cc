#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int  N, M, degree[32001];
queue<int> result;
priority_queue<int, vector<int>, greater<int>> q;
vector<int> vv[32001];
void f() {
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int c_node = q.top();
		q.pop();
		result.push(c_node);
		for (auto d : vv[c_node]) {
			degree[d]--;
			if (degree[d] == 0) {
				q.push(d);
			}
		}
	}
}

void input() {
	int fST, sST;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> fST >> sST;
		vv[fST].push_back(sST);
		degree[sST]++;
	}
}
void output() {
	while (!result.empty()) {
		cout << result.front() << " ";
		result.pop();
	}
	/*for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}*/
}
int main() {
	input();
	f();
	output();
	return 0;
}