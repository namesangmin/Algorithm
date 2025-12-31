#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
vector<long long int> v;
long long int isTrue(long long int p_center) {
	long long int Count = 0;
	for (int i = 0; i < N; i++) {
		if (v[i] > p_center)
			Count += v[i]- p_center;
	}
	return Count;
}
// 이분 탐색
long long int f(vector<long long int> const& find_v) {
	long long int pl = 0;
	long long int pr = find_v.back();
	long long int r = 0;
	while (pl <= pr) {
		long long int pc = (pl + pr)/2;
		long long int want_tree= isTrue(pc);
		if (want_tree >= M) {
			r = pc;
			pl = pc + 1;
		}
		else if (want_tree < M) {
			pr = pc - 1;
		}
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);  
	cin.tie(0);  
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long int result = f(v);
	cout << result << "\n";


	return 0;
}