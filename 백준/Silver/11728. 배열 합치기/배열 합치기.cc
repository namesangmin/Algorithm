#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int A, B;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;
	int input;
	for (int i = 0; i < A; i++) {
		cin >> input;
		pq.push(input);
	}
	for (int i = 0; i < B; i++) {
		cin >> input;
		pq.push(input);
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}