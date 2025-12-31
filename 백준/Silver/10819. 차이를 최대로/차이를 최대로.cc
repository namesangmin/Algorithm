#include <iostream>
#include <vector>
#define MAX -999999
using namespace std;
int N, maxV;
vector<bool> visited;
vector<int> v, arr;
void input() {
	cin >> N;
	v.resize(N);
	arr.resize(N);
	visited.resize(N, false);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	maxV = MAX;
}
void func(int n) {
	if (n == N) {
		int value = 0;
		for (int i = 0; i < N - 1; i++) {
			value += abs(arr[i] - arr[i + 1]);
		}
		if (maxV < value)
			maxV = value;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			arr[n] = v[i];
			visited[i] = true;
			func(n + 1);
			visited[i] = false;
		}
	}
}
int main() {
	input();
	func(0);
	cout << maxV << "\n";
	return 0;
}