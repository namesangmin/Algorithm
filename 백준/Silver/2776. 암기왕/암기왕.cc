#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> su1;
void func(int val);
void input() {
	su1.clear();
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		su1.push_back(temp);
	}
	sort(su1.begin(), su1.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		func(temp);
	}
}
bool Check(int val) {
	int st = 0;
	int end = N - 1;
	while (st <= end) {
		int mid = (st + end) / 2;

		if (su1[mid] == val) 
			return true;
		
		if (su1[mid] > val) 
			end = mid - 1;
		else 
			st = mid + 1;
	}
	return false;
}
void func(int val) {
	if (Check(val)) cout << true << "\n";
	else cout << false << "\n";

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		input();
	}
}