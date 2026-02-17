#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<bool>> v;
vector<int> m;
queue<int> q;
void input() {
	int a, b;
	cin >> N;
	v.resize(N + 1, vector<bool>(N + 1, 0));
	m.resize(N + 1, -1);
	for (;;) {
		cin >> a >> b;
		if (a == -1 || b == -1) break;
		v[a][b] = 1;
		v[b][a] = 1;
	}
}
bool bfs(int node) {
    q = queue<int>();
    q.push(node);
	m[node] = 1;

	while (!q.empty()){
		int cNode = q.front();
		q.pop();

		for (int idx = 1; idx <= N; idx++) {
			// 자기 자신 제외
			if (idx == cNode) continue;
			// 자기 자신과 엮기지 말아야 할 것과 같은 팀이라면
			if (v[cNode][idx] == 0 && m[idx] == m[cNode]) return false;

			// 해당 맵의 값이 0이고, 아직 아무 팀에 속해있지 않으면
			if (v[cNode][idx] == 0 && m[idx] == -1 ) {
				m[idx] = m[cNode] ^ 1;
				q.push(idx);
			}
		}
	}
	return true;
}
void func() {
	for (int i = 1; i <= N; i++) {
		if (m[i] == -1) {
			bool tm = bfs(i);
			if (!tm) {
				cout << "-1\n";
				return;
			}
		}
	}

	vector<int> A;
	vector<int> B;
	int one = m[1];
	for (int i = 1; i <= N; i++) {
		if (m[i] == one) {
			A.push_back(i);
		}
		else {
			B.push_back(i);
		}
	}

	cout << "1\n";
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << "-1\n";
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << " ";
	}
	cout << "-1\n";

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	input();
	func();
}