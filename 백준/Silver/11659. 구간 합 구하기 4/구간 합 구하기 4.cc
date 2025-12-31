#include <iostream>
#include <vector>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int input;
	int inputA, inputB;
	int result = 0;
	int sum[100001] = {};

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;
		sum[i+1] = sum[i] + input;		
	}

	for (int i = 0; i < M; i++) {
		cin >> inputA >> inputB;

		result = sum[inputB] - sum[(inputA - 1)];
		printf("%d\n", result);

	}

	return 0;
}