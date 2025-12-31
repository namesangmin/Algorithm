#include <iostream>
#include <cstring>
using namespace std;
int T, n, d, Count, X[500][500];
void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << X[i][j] << " ";
		}
		cout << "\n";
	}
}
void func() {
    int tempX[500][500] = { 0, };

	memcpy(tempX, X, sizeof(X));
	int half = (n + 1) / 2;
	
	// 1.
	for (int i = 0; i < n; i++) {
		X[i][half - 1] = tempX[i][i];
	}
	// 2.
	for (int i = 0; i < n; i++) {
		X[i][n - (1 + i)] = tempX[i][half - 1];
	}
	// 3.
	for (int i = 0; i < n; i++) {
		X[half-1][n - (1 + i)] = tempX[i][n - (1 + i)];
	}
	// 4.
	for (int i = 0; i < n; i++) {
		X[n - (1 + i)][n - (1 + i)] = tempX[half-1][n - (1 + i)];
	}
}
void input() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n >> d;
		d = (d + 360) % 360;
		Count = d / 45;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> X[j][k];
			}
		}
		for(int i=0; i<Count; i++)
			func();
		Print();
	}
}
int main() {
	input();

	return 0;
}