#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<vector<int>> v;
vector<int>visited;

void input() {
	cin >> N >> M;
	// init
	v.resize(N); 
	visited.resize(N,false);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

int Check(int node, int Size) {
	if (Size >= 4) {
        cout << "1\n";
        exit(0);
    }
	// 만약에 막혔는데 깊이가 5보다 작으면? return false
	// 막힌 것을 어떻게 알지?
	int maxCnt = Size;
	
	for (int i = 0; i < v[node].size(); i++) {
		if (!visited[v[node][i]]) {
			visited[v[node][i]] = true;
			maxCnt = max(Check(v[node][i], Size + 1), maxCnt);
			visited[v[node][i]] = false;
		}
	}
	return maxCnt;
}

bool func() {
	bool ans = false;
	int tm = 0;
	for (int i = 0; i < N; i++) {
		visited[i] = true;
		tm = Check(i, 0);
		visited[i] = false;
	}
	return ans;
}
int main() {
	input();
	cout << func() << "\n";
	return 0;
}