#include <iostream>

using namespace std;
int N, M, arr[101];
int main() {
	int i, j;
	cin >> N >> M;
	for (int k = 1; k <= N; k++) {
		arr[k] = k;
	}
	for (int k = 1; k <= M; k++) {
		int temp = -1;
		cin >> i >> j;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	for (int k = 1; k <= N; k++) {
		cout << arr[k] << " ";
	}
	return 0;
}