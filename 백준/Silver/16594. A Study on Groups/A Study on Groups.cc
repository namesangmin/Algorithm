#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int arr[100001] = { 0 };

void input() {
	cin >> N >> M;
	int i;
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + N + 1);
}

void func() {
	int div = N / M;
	int mod = N % M;
	long long minimum = 0;
	long long maximum = 0;
	
	for (int i = 1; i <= M; i++) { minimum += arr[i]; }

	// mod 개수 처리
	for (int i = 0; i < mod; i++) {
		if (i * (div + 1) + 1 <= N) {
			maximum += arr[i * (div + 1) + 1];
		}
	}
	// 나머지 그룹
	int start = mod * (div + 1) + 1;
	for (int i = 0; i < M - mod; i++) {
		if (start + i * div <= N) {
			maximum += arr[start + i * div];
		}
	}
	cout << minimum << " " << maximum << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	func();
	return 0;
}