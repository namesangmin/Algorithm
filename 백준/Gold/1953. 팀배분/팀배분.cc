#include <iostream>
#include <vector>

using namespace std;
int n;
vector<vector<int>> v;
vector<int> flag;
void input() 
{
	int a, b;
	cin >> n;
	v.resize(n + 1);
	flag.resize(n + 1, -1);

	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			v[i].push_back(b);
		}
	}
}
void dfs(int cNode) {

	for (int i = 0; i < v[cNode].size(); i++) {
		int nNode = v[cNode][i];
		if (flag[nNode] == -1) {
			flag[nNode] = flag[cNode] ^ 1;
			dfs(nNode);
		}
	}
}
void func() {

	for (int i = 1; i <= n; i++) {
		if (flag[i] == -1) {
			flag[i] = 1;
			dfs(i);
		}
	}
	int white = 0, black = 0;
	vector<int> w, b;
	for (int i = 1; i <= n; i++) {
		if (flag[i]) {
			white++;
			w.push_back(i);
		}
		else {
			black++;
			b.push_back(i);
		}
	}
	cout << white << "\n";
	for (int i = 0; i < white; i++) {
		cout << w[i] << " ";
	}
	cout << "\n";
	cout << black << "\n";
	for (int i = 0; i < black; i++) {
		cout << b[i] << " ";
	}
}
int main() {
	input();
	func();

	return 0;
}