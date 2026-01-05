	#include <iostream>
	#include <vector>
	#include <algorithm>
	using namespace std;

	int n,k;
    long long inputSum;
	vector<int> arr;
	void input() {
		cin >> n >> k;
		int tm;
		for (int i = 0; i < n; i++) {
			cin >> tm;
			arr.push_back(tm);
			inputSum += tm;
		}
	}
	long long func() {
		long long ans = 0;
		long long left = 0;
		long long right = inputSum;

		while (left <= right) {
			long long mid = (left + right) / 2 + 1;

			// 확인
			long long cnt = 0;
			for (int i = 0; i <arr.size(); i++) {
				cnt += (long long)(arr[i] / mid);
			}
			if (cnt >= k) { // 될 때 -> 왼쪽 크기를 늘림
				ans = max(ans, mid);
				left = mid;
			}
			else { // 안될 때 -> 오른쪽 크기를 줄임
				right = mid - 2;
			} 
		}
		return ans;
	}
	int main() {
		input();
		cout << func() << "\n";
	}