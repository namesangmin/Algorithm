#include <iostream>
#include <cstdint>

using namespace std;
int N, M, arr[1001];
bool visited[51];
void input() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int st, ed;
		cin >> st >> ed;
		for (int j = st; j <= ed; j++) {
			arr[j] = i;
		}
	}
}
void func() {
	int Count = 0;
	uint64_t ans = 1;
	for (int i = 1; i <= N; i++) {
		int idx = arr[i];
		if (arr[i] > 0 && !visited[idx]) {
			visited[idx] = true;
			Count++;
		}
	}
	for (int i = 0; i < Count; i++) {
		ans *= 2;
	}
	cout << ans << "\n";
}
int main() {
	input();
	func();
	return 0;
}