#include <iostream>
#include <queue>
using namespace std;
int N, K;
int Count;
bool visited[100001];
int dx[2] = { -1,1 };
// 무조건 N이 K보다 작을 때임
// 5, 4, 6, (10)… 3,5,10, 5,7,12, (9,11,20) …… (8,10,18) ……. 7,9,16 9,11,20 (17,18,36)
int f(int n) {
	queue<int>q;
	bool isFind = false;
	// 1. +1을 할 경우
	// 2. -1을 할 경우
	// 3. x2를 할 경우
	//if (visited[n]) return false;
	
	visited[n] = true;
	q.push(n);

	while (!q.empty()) {
		// BFS니까 한 행이 끝날 때까지 count를 하지 않는다.
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int current = q.front();
			q.pop();
			//cout << "pop current" << current << "\n";

			if (current == K)
				return Count;

			// +1, -1
			for (int i = 0; i < 2; i++) {
				int next_x = current + dx[i];
				if (!visited[next_x] && next_x >= 0 && next_x <= 100000) {
					visited[next_x] = true;
					q.push(next_x);
					//cout << "next_x" << next_x << " ";
				}
			}
			// x 2
			if (2 * current >= 0 && 2 * current <= 100000) {
				if (!visited[2 * current]) {
					visited[2 * current] = true;
					current *= 2;
					q.push(current);
					//cout << "current" << current << " ";
				}
			}
		}
		Count++;
		//cout << "Count" << Count << "\n";
	}
}

int main() {
	cin >> N >> K;
	int temp = N;
	if (N > K) {
		while (true) {
			if (temp == K)
				break;
			Count++;
			temp--;
		}
	}
	else if(N < K){
		f(N);
	}
	cout << Count << "\n";
	return 0;
}