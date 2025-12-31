#include <iostream>

using namespace std;
int arr[21][21], N, ans=9999999, temp[21];
bool visited[21];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}
// 하나만 정하면 나머지는 알아서 따라오는데..
void func(int n, int st) {
	if (n == N / 2) {
		int sumA = 0;
		int sumB = 0;
		int tempB[21] = {0,}, idx = 0;
		// 배열에 있는 모든 조합의 합 vs 배열 나머지 조합의 합
		for (int i = 0; i < N / 2; i++) {
			for (int j = i+1; j < N / 2; j++) {
				int a = temp[i];
				int b = temp[j];
				sumA += (arr[a][b] + arr[b][a]);
			}
		}

		// 나머지 그룹에 있는 것들
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				tempB[idx++] = i;
			}
		}
		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				int a = tempB[i];
				int b = tempB[j];
				sumB += (arr[a][b] + arr[b][a]);
			}
		}
		int tempAns = abs(sumA - sumB);
		if (ans > tempAns)
			ans = tempAns;
		return;
	}


	for (int i = st; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp[n] = i;
			func(n + 1, i+1);
			visited[i] = false;
		}
	}
}
int main() {
	input();
	visited[0] = true;
	temp[0] = 0;
	func(1,1);
	cout << ans << "\n";
	return 0;
}