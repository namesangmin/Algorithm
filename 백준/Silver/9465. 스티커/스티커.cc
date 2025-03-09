#include <iostream>
#include <cstring>

using namespace std;
int T, n;
int arr[2][100001];
int visited[2][100001];

// 만약 선택 x -> 전에 있던 값으로 업데이트
// 선택 o 같은 자리면 다른 자리에 있는 것을 선택해서 더함
// F_S -> First, Second
int dp(int F_S, int s) {
	// 이미 저장되어 있는 값이 있으면 리턴
	if (s <= 0)return 0;
	if (visited[F_S][s] != -1)return visited[F_S][s];

	return visited[F_S][s] = max(dp(1 - F_S, s - 1), dp(1 - F_S, s - 2)) + arr[F_S][s];
}
void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		memset(arr, 0, sizeof(arr));
		memset(visited, -1, sizeof(visited));
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> arr[j][k];
			}
		}
		cout << max(dp(0, n), dp(1, n)) << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();


	return 0;
}