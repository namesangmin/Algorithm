#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
int m[8];
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}
	sort(m, m + N);
}
void func(int n, int st) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = st; i < N; i++) {
		arr[n] = m[i];
		func(n + 1, i + 1);
	}
}
int main() {
	input();
	func(0,0);
	return 0;
}