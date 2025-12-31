#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> A, memo;
void input() {
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.push_back(temp);
	}
}
int Search(int target) {
	int Idx = memo.size();
	int left = 0, right = memo.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		int curVal = memo[mid];

		if (curVal < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			Idx = mid;
		}
	}
	return Idx;
}
int func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int idx = Search(A[i]);

		if (idx == memo.size()) memo.push_back(A[i]);
		else memo[idx] = A[i];
	}

    ans = memo.size();
	return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	cout << func() << "\n";
	return 0;
}