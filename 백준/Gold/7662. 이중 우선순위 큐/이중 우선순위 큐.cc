#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
using namespace std;

int N, M;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
	cin >> N;
	char input;
	int input_what;
	for (int i = 0; i < N; i++) {
		priority_queue<int>p1;
		priority_queue<int, vector<int>, greater<int>>p2;
		unordered_map<int, int> Count ;// 이게 왜 int로? 와 동일 값 입력이 들어오네
		int Max, Min;

		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> input >> input_what;
			if (input == 'I') {
				p1.push(input_what);
				p2.push(input_what);
				Count[input_what]++;
			}
			else if (input == 'D') {
				if (input_what == 1) {
					while (!p1.empty() && Count[p1.top()] == 0) {
						p1.pop();
					}
					if (!p1.empty()) {
						Count[p1.top()]--;
						p1.pop();
					}
				}
				else {
					while (!p2.empty() && Count[p2.top()] == 0) {
						p2.pop();
					}
					if (!p2.empty()) {
						Count[p2.top()]--;
						p2.pop();
					}
				}
			}
		}

		while (!p1.empty() && Count[p1.top()] == 0) {
			p1.pop();
		}
		while (!p2.empty() && Count[p2.top()] == 0) {
			p2.pop();
		}

		if (p1.empty() || p2.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << p1.top() << " " << p2.top() << "\n";
		}
		// print
		/*
		while (!p1.empty()) {
			int a = p1.top();
			p1.pop();
			cout << a << " ";
		}
		cout << "\n\n";


		while (!p2.empty()) {
			int a = p2.top();
			p2.pop();
			cout << a << " ";
		}
		cout << "\n";*/
	}
	return 0;
}