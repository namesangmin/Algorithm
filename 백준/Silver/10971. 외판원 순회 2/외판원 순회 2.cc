#include <iostream>
#define INF 99999999

using namespace std;
int N, w[17][17], ans = INF;
bool visited[17];
void input() {
	cin >> N;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> w[r][c];
		}
	}
}
void func(int curN, int Count, int cost) {
	if (ans < cost)
		return;

	if (Count == N) {
		if (w[curN][1] != 0) {
			cost += w[curN][1];
			ans = min(ans, cost);
		}
	}

	for (int nextN = 1; nextN <= N; nextN++) {
		if (!visited[nextN] && w[curN][nextN] > 0) {
			visited[nextN] = true;
			func(nextN, Count+1, w[curN][nextN] + cost);
			visited[nextN] = false;
		}
	}
}

int main() {
	input();
	visited[1] = true;
	func(1,1,0);
	cout << ans << "\n";
	return 0;
}