#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> v, ans(6);
void input() {
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
}
void func(int n, int size){
	if (size == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = n; i < N; i++) {
		ans[size] = v[i];
		func(i + 1, size + 1);
	}
}
int main() {
	while (true){
		input();
		if (N == 0) break;
		func(0,0);
		cout << "\n";
	}
	return 0;
}