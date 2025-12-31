#include <iostream>
#include <vector>
#include <unordered_set>  
#include <algorithm>
#define MAX 110
using namespace std;

int N;
bool visited[MAX];
vector<vector<int>> vv;
vector<vector<int>> v;
vector<unordered_set<int>> v_check;  

void input() {
	int temp;
	cin >> N;
	vv.resize(N + 1);
	v.resize(N + 1);
	v_check.resize(N + 1);  

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> temp;
			if (temp) {
				vv[r].push_back(c);
			}
		}
	}
}

void dfs(int num) {
	if (visited[num]) return;
	visited[num] = true;

	int size = vv[num].size();
	for (int i = 0; i < size; i++) {
		int n_num = vv[num][i];
		dfs(n_num);

		if (!v_check[num].count(n_num)) {         
			v[num].push_back(n_num);
			v_check[num].insert(n_num);           
		}

		int n_size = v[n_num].size();
		for (int j = 0; j < n_size; j++) {
			int node = v[n_num][j];
			if (!v_check[num].count(node)) {
				v[num].push_back(node);
				v_check[num].insert(node);
			}
		}
	}
	return;
}

void func() {
	for (int i = 1; i <= N; i++) {
		fill(visited, visited + N + 2, false);
		dfs(i);
	}
}

void print() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (find(v[r].begin(), v[r].end(), c) != v[r].end())
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}

int main() {
	input();
	func();
	print();
	return 0;
}
