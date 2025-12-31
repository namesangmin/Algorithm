#include <iostream>

using namespace std;
int N, S;
int arr[100001];
void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}
void func() {
	int sum = 0;
	int aP = 0;
	int bP = 0;
	int ans = 999999;
	while (true) {
		if (sum >= S) {
			int temp = aP - bP;
			if (ans > temp)
				ans = temp;
			sum -= arr[bP++];
		}
		else {
			if (aP == N) break;
			sum += arr[aP++];
		}
	}
	if (ans == 999999) cout << "0\n";
	else cout << ans << "\n";
}
int main() {
	input();
	func();

	return 0;
}