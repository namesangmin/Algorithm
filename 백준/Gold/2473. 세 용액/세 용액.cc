#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 3000000001
using namespace std;

int N;
vector<int> v;


void input() {
	cin >> N;
	
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
}
vector<int> func() {
	vector<int> ans(3);

	long long Min= INF;
	for (int i = 0; i < N - 2; i++) {
		long long curVal = v[i];
		int st = i + 1;
		int end = N - 1;
		//Min = curVal + v[st] + v[end];
		while (st < end) {
		    long long stVal = v[st];
			long long endVal = v[end];
			
			long long sum = curVal + stVal + endVal;
			// 더 작은 값
			if (llabs(sum) < llabs(Min)) {
				Min = sum;
				ans[0] = curVal;
				ans[1] = stVal;
				ans[2] = endVal;
			}
			
			if (sum < 0) {
				st++;
			}
			else {
				end--;
			}
		}
	}
	return ans;
}
int main() {
	input();
	vector<int> ans = func();
	sort(ans.begin(), ans.end());

	for (auto a : ans) {
		cout << a << " ";
	}
	return 0;
}