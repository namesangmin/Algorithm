#include <iostream>
using namespace std;

int N, S, ans;
int arr[21];

void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void func(int n, int sum) {
	if (n == N) return;

	sum += arr[n];
	if (sum == S) ans++;

	func(n + 1, sum);
	func(n + 1, sum - arr[n]);
}

int main() {
	input();
	func(0, 0);
	cout << ans << '\n';
	return 0;
}
