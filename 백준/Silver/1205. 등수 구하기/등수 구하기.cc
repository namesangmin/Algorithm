#include <iostream>
#include <vector>

using namespace std;
int N, P, newScore;
vector<int> arr;

void input() {
	cin >> N >> newScore >> P;
	arr.resize(P);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}
int func() {
	int ans = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i] > newScore) ans++;
		else break;
	}
	if (N == P && newScore <= arr[N - 1]) ans = -1;
	return ans;
}
int main() {
	input();
	cout << func() << "\n";
	return 0;
}