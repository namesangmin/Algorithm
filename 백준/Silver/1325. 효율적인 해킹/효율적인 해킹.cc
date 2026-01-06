#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, tmMax, tmIdx;
vector<vector<int>> arr;

// 단지 번호와 개수
// A B와 같은 형식으로 들어오며, "A가 B를 신뢰한다"를 의미한다.
// 개수 세기
vector<int> cnt;
queue<int> q;
vector<bool> visited;
void input() {
	cin >> N >> M;
	arr.resize(N+1);
	cnt.resize(N + 1, 0);
	visited.resize(N + 1, false);

	// input
	int a,b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b; // a가 b를 신뢰하면, b가 감염되면 a도 감염 => 거꾸로 하면 어디까지 감염되는지 개수가 나옴
		arr[b].push_back(a);
	}
}

int bfs(int num) {
	q.push(num);
	visited[num] = true;
	int tmCnt = 1;
	while (!q.empty()) {
		int cNum = q.front();
		q.pop();
		
		for (int i = 0; i < arr[cNum].size(); i++) {
			int nNum = arr[cNum][i];
			if (!visited[nNum]) {
				q.push(nNum);
				visited[nNum] = true;
				tmCnt++;
			}
		}
	}
	return tmCnt;
}

void check() {
	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		if (tmMax == cnt[i])ans.push_back(i);
	}
	
	sort(ans.begin(), ans.end());
	for (auto a : ans) {
		cout << a << " ";
	}
}
void func() {
	for (int i = 1; i <= N; i++) {
		visited.assign(N + 1, false);
		cnt[i] = bfs(i);
		if (tmMax < cnt[i]) {
			tmMax = cnt[i];
			tmIdx = i;
		}
	}
	check();
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	input();
	func();
	return 0;
}