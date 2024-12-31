#include <iostream>
#include <algorithm>
using namespace std;
int arr[9];
int temp[9] = { -1, };
int visited[9];
int Check[2];
// 앞의 자리가 뒷 자리보다 커야 함
void dfs(int n, int N, int M, int j) {
	// 출력
	if (n == M) {
		for (int i = 0; i < n; i++) {
			cout << temp[i] << " ";
		}
		cout << "\n";
		return;
	}
	int prev_num = -1;
	for (int i = 0; i < N; i++) {
		//cout << "n : " << n << " prev_num : " << prev_num << "\n";
		//cout << "arr : "<<i << " " << arr[i] << " temp : " << temp[n] << "\n";

		if (prev_num != arr[i] && arr[j] <= arr[i]) {
			// 해당 번호가 False이고 n이 i보다 커야 함?
			// i가 아니라 n이어야 함
			// i이면 해당 숫자를 돌고 false로 찍히는데 
			// 그 번호를 다시 돈다.
			temp[n] = arr[i];
			//cout << "2. arr : " << i << " " << arr[i] << " temp : " << temp[n] << "\n";
			
			prev_num = temp[n];
			dfs(n + 1, N, M,i); 
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	dfs(0, N, M, 0);
	return 0;
}