#include <iostream>
#include <algorithm>

using namespace std;
int arr[100001];
int N;
void input() {
	cin >> N;
	int tm;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}
int gcd(int a, int b) {
	while (b != 0) {
		int tm = a % b;
		a = b;
		b = tm;
	}
	return a;
}
int func() {
	int g = arr[1] - arr[0];
	for (int i = 2; i < N; i++) {
		g = gcd(g, arr[i] - arr[i - 1]);
	}

	int ans = 0;
	for (int i = 1; i < N; i++) {
		int d = arr[i] - arr[i - 1];
		ans += (d / g) - 1;
	}
	return ans;
}

int main() {
	input();
	cout << func() << "\n";
	return 0;
}