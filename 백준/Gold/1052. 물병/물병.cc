#include <iostream>

using namespace std;
int N, K, buy;
void input() {
	cin >> N >> K;
}
int Count(int n) {
	int cnt = 0;
	while (n > 0) {
		cnt += (1 & n);
		n >>= 1;
	}
	return cnt;
}
void func() {

	while (Count(N) > K) {
		N++;
		buy++;
	}
	cout << buy << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	input();
	func();
	return 0;
}