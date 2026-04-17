#include <iostream>
#include <vector>

using namespace std;
int N, removeNode, stNode;
vector<vector<int>> arr;
vector<bool> visited;
void input() {
	cin >> N;
	arr.resize(N + 1);
	visited.resize(N + 1, false);

	int nodeG;
	for (int i = 0; i < N; i++) {
		cin >> nodeG;	
		if (nodeG == -1) {
			stNode = i;
		}
		else {
			arr[nodeG].push_back(i); // 맵 제작
		}
	}
	cin >> removeNode;
	int removeSize = arr[removeNode].size();
	for (int i = 0; i < removeSize; i++) {
		arr[removeNode].pop_back();
	}
}
int cnt;
int dfs(int node) {
	if (arr[node].size() == 0 && node != removeNode ||
		arr[node].size() == 1 && arr[node][0] == removeNode) cnt++;

	for (int i = 0; i < arr[node].size(); i++) {
		int nNode = arr[node][i];
		if (nNode != removeNode && !visited[nNode]) {
			visited[nNode] = true;
			dfs(nNode);
		}
	}
	return cnt;
}

int func() {
	int ans = dfs(stNode);
	return ans;
}

int main() {
	input();
	cout << func() << "\n";
	return 0;
}