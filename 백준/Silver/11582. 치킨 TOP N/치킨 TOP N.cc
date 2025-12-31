#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, k, ans;
vector<int> v;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; 
		cin >> temp;
		v.push_back(temp);
	}
	cin >> k;
}

void func() {
	int group = N / k;
	vector<vector<int>> vv;
	vv.resize(k + 1);
	for (int i = 0; i < k; i++) {
		for (int j = i * group; j < (i + 1) * group; j++) {
			vv[i].push_back(v[j]);

		}
		sort(vv[i].begin(), vv[i].end());
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < group; j++) {
			cout << vv[i][j] << " ";
		}
	}
}
int main() {
	input();
	func();
	return 0;
}