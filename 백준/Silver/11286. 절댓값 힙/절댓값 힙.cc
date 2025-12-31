#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

bool check[100001];
int main() {
	int n;
	int input;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 0) {
			if (pq.empty())
				cout << "0" << "\n";
			else {
				pair<int, int> result = pq.top();
				pq.pop();
				cout << result.second << "\n";
			}
			continue;
		}
		pq.push({ abs(input),input });
	}
	return 0;
}