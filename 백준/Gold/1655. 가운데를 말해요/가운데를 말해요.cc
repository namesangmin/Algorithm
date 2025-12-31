#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>> pqMax;
priority_queue<int, vector<int>, greater<int>> pqMin;
int N;

void func(int input) {
	int sizeMax = pqMax.size();
	int sizeMin = pqMin.size();

	if (pqMax.empty())
		pqMax.push(input);
	else if (sizeMax == sizeMin)
		pqMax.push(input);
	else
		pqMin.push(input);

	if ((!pqMax.empty() && !pqMin.empty()) && (pqMax.top() > pqMin.top())) {
		int pqM = pqMax.top();
		int pqm = pqMin.top();
		pqMax.pop();
		pqMin.pop();

		pqMax.push(pqm);
		pqMin.push(pqM);
	}
	cout << pqMax.top() << "\n";
	
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		func(input);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	return 0;
}