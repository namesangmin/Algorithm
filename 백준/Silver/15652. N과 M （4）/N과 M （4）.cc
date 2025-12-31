#include <iostream>

using namespace std;
int arr[9];
int visited[9];
// 앞의 자리가 뒷 자리보다 커야 함
void dfs(int n, int N, int M) {
	// 출력
	if (n == M) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i] && ( n==0 || arr[n-1] <= i+1)) {
			// 해당 번호가 False이고 n이 i보다 커야 함?
			arr[n] = i+1;
			//cout << arr[i] << "\n";
			
			//visited[i] = true;
			
			dfs(n + 1, N, M); // i가 아니라 n이어야 함
			// i이면 해당 숫자를 돌고 false로 찍히는데 
			// 그 번호를 다시 돈다.
			// 
			//visited[i] = false;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	dfs(0,N,M);
	return 0;
}