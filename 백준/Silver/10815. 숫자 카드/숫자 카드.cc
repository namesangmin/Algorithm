#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> arrN;
int N, M;

bool func(int valFind) {
	int left = 0, right = N - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int curVal = arrN[mid];
		if (valFind == curVal) {
			return true;
		}
		else if (valFind > curVal) { left = mid + 1; }
		else { right = mid - 1; }
	}
	return false;
}

void input() {
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arrN.push_back(temp);
	}
	sort(arrN.begin(), arrN.end());
	
	cin >> M;
	string ans;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		ans += func(temp) ? "1 " : "0 ";
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	return 0;
}