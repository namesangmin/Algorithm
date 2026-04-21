#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 191919
using namespace std;

int N;
vector<int> v, memo;
int main() {
	cin >> N;
	v.resize(N + 1);
	memo.resize(N + 1, MAX);
	int tm;
	for (int i = 0; i < N; i++) {
		cin >> tm;
		v[i] = tm;
	}
	memo[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= v[i]; j++) {

			if (i + j > N) continue;
			if (memo[i + j] > memo[i] + 1) {
				memo[i + j] = memo[i] + 1;
			}
		}
	}
	if (memo[N - 1] == MAX) cout << "-1";
	else cout << memo[N - 1];
	return 0;
}