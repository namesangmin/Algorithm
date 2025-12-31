#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int tree[100001] = { 0 };
int left[100001] = { 0 };
int right[100001] = { 0 };
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int N, input;
	int head = 0; // 0번 자리를 헤드로 쓸 거임.
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == 0 && pq.empty())cout << "0 \n";
		else if (input == 0 && !pq.empty()) {
			cout << -pq.top()<< "\n";
			pq.pop();
		}
		else {
			pq.push(-input);
		}
	}	
	return 0;
}