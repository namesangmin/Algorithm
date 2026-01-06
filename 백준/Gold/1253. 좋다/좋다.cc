#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> arr;
void input() {
	cin >> n;
	int tm;
	for (int i = 0; i < n; i++) {
		cin >> tm;
		arr.push_back(tm);
	}
	sort(arr.begin(), arr.end());
}

// 음수 양수 따로 둬야하네
// 보니가 A는 -값이 나올 수가 있네
int func() {
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		int leftIdx = 0, rightIdx = arr.size() - 1, targetIdx = i;
		bool isPossible = false;
		while (leftIdx < rightIdx) {
			if (arr[leftIdx] + arr[rightIdx] == arr[targetIdx]) {
				if (leftIdx == targetIdx)	leftIdx += 1;
				else if (rightIdx == targetIdx) rightIdx -= 1;
				else {
					isPossible = true;
					break;
				}
			}
			else {
				if (arr[leftIdx] + arr[rightIdx] > arr[targetIdx]) {
					rightIdx -= 1;
				}
				else {
					leftIdx += 1;
				}
			}
		}
		if (isPossible) ans++;
	}

	return ans;
}
int main() {
	input();
	cout << func() << "\n";
}