#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	int sum = 0;
	for (int i = 0; i < K; i++) sum += v[i];

	int Max = sum;
	for (int i = K; i < N; i++) {
		sum = sum - v[i - K] + v[i];
		Max = max(Max, sum);
	}
	cout << Max << "\n";
	return 0;
}
