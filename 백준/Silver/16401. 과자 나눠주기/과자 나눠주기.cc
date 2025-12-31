#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, maxVal;
vector<int> stick;
void input() {
	cin >> N >> M;
	int temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (maxVal < temp) maxVal = temp;
		stick.push_back(temp);
	}
}
int func() {
	// 배열 안에 있는 값이 아닌 인덱스로 접근을 해 버리면 
	// n과 n + 1 사이에 있는 값(예. 8과 10 사이에 9)을 조사를 할 수가 없음
	int ans = 0;
	int stVal = 1;
	int endVal = maxVal;
	while (stVal <= endVal) {
		int midVal = (stVal + endVal) / 2;
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			cnt += stick[i] / midVal;
		}
		if (cnt >= N) {
			ans = max(ans, midVal);
			stVal = midVal + 1;

		}else endVal = midVal - 1;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	cout << func() << "\n";
	return 0;
}