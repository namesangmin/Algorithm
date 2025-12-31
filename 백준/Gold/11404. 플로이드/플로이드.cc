#include <iostream>
#include <vector>
#define MAX 10000001
using namespace std;
int n, m;
vector<vector<long long>> arr;
void input() {
	cin >> n >> m;
	int a, b, c;
	
	// init
	arr.resize(n + 1, vector<long long>(n + 1, 0));
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			if (r == c) continue;
			arr[r][c] = MAX;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (arr[a][b] > c)
			arr[a][b] = c;
		//else arr[a][b] = c;
	}
}

void func() {
	for (int i = 1; i <= n; i++) { // 거쳐가는 노드
		for (int st = 1; st <= n; st++){ // 시작 노드
			for (int end = 1; end <= n; end++) { // 도착 노드
				// st에서 end로 가는데 거쳐가는 노드와 그냥 가는 방법 중 어느 것이 더 작은지 확인
				if (arr[st][end] > arr[st][i] + arr[i][end])
					arr[st][end] = arr[st][i] + arr[i][end];
			}
		}
	}

	// 출력
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			if (arr[r][c] >= MAX)
				cout << "0 ";
			else
				cout << arr[r][c] << " ";
		}
		cout << "\n";
	}
}
int main() {
	input();
	func();
	return 0;
}