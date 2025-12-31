#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> A, memo, arrTemp;
void input() {
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.push_back(temp);
	}
}

int Search(int target) {
	int idx = arrTemp.size(); // 수열을 저장하는 배열의 크기
	int left = 0, right = arrTemp.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int curVal = arrTemp[mid];
		
		if (curVal < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			idx = mid;
		}
	}
	return idx;
}
void func() {
	vector<int> ans;
	int ansSize = 0;
	/////////////////
	memo.resize(N);
	
	for (int i = 0; i < N; i++) {
		int idx = Search(A[i]); // 해당 인덱스의 값이 들어갈 위치를 구하기
		if (idx == arrTemp.size())
			arrTemp.push_back(A[i]);
		else {
			arrTemp[idx] = A[i];
		}
		memo[i] = idx;
	}
		
	ansSize = arrTemp.size();
	int len = arrTemp.size();

	for (int i = N-1; i >= 0; i--) {
		if (memo[i] == len - 1) {
			ans.push_back(A[i]);
			len--;
		}
	}
	reverse(ans.begin(), ans.end());
	// 정답 출력
	cout << ansSize << "\n";
	for (auto a : ans) {
		cout << a << " ";
	}
}
int main() {
	input();
	func();
	return 0;
}
