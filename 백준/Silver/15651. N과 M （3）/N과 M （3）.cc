#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[8];

void input() {
	cin >> N >> M;
}
void func(int n) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		arr[n] = i;
		func(n + 1);
	}
}
int main() {
	input();
	func(0);
	return 0;
}