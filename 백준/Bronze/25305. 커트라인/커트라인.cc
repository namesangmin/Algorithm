#include <iostream>
#include <queue>
using namespace std;
int N, k;
priority_queue<int> pq;
int main() {
	cin >> N >> k;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		pq.push(input);
	}

	for (int i = 0; i < k - 1; i++) {
		pq.pop();
	}
	cout << pq.top() << "\n";

	return 0;
}