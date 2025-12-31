#include <iostream>
#include <queue>

using namespace std;
queue<int>q;
int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	cout << "<";
	int idx = 1;
	int Count = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (idx == K) {
			cout << cur;
			if (Count != N) {
				cout << ", ";
			}
			Count++;
			idx = 1;
		}
		else {
			q.push(cur);
			idx++;
		}

	}
	cout << ">";
	return 0;
}