#include <iostream>
#include <vector>


using namespace std;
int arr[50][50];
int check[50][50];
int goX[4] = { 1,0,-1,0 };
int goY[4] = { 0,1,0,-1 };

int dfs(int y, int x, int n, int m) {
	if (check[y][x]) return 0;
	check[y][x] = 1;
	int sumX;
	int sumY;
	for (int i = 0; i < 4; i++) {
		sumX = x + goX[i];
		sumY = y + goY[i];


		if (sumX >= 0 && sumY >= 0 && sumX < m && sumY < n && arr[sumY][sumX])
			dfs(sumY, sumX, n, m);
	}
	return 1;
}

int main() {

	int T ,M, N, K, x,y;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int count = 0;
		cin >> M >> N >> K;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				arr[j][k] = 0;
				check[j][k] = 0;
			}
		}

		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[j][k] && !check[j][k]) {
					if (dfs(j, k, N, M))
						count++;

				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}