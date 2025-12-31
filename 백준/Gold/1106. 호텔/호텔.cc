#include <iostream>
#include <vector>
#define MAX 1e9 + 1
using namespace std;
int N, C;
struct city{
	int cost, person;
};
vector<city> v_c;
int DP[1000001]; // C = 1000, N = 1, N + 1 = 100 1 => 1,000,000

void input() {
	cin >> C >> N;
	v_c.resize(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> v_c[i].cost >> v_c[i].person;
	}
}
void func(int c_cost) {
	if (DP[c_cost] >= C) return;

	for (int i = 0; i < N; i++) {
		int n_c = v_c[i].cost + c_cost;
		int n_p = v_c[i].person;
		if (DP[n_c] < DP[c_cost] + n_p) {
			DP[n_c] = DP[c_cost] + n_p;
			func(n_c);
		}
	}
}
void print() {
	int ans = MAX;
	for (int i = 0; i < 1000001; i++) {
		if (DP[i] >= C) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
}
int main() {
	input();
	func(0);
	print();
	return 0;
}