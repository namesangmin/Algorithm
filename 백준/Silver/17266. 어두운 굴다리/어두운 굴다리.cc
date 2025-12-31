#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int N, M;
void input() {
	cin >> N >> M;

	int temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		v.push_back(temp);
	}
}
int func() {
	int ans = 0;
	int Min = 1, Max = N; // 가로등 최소 높이 1, 최대 높이 N
	
	while (Min <= Max) {
		bool possible = true;
		int mid = (Min + Max) / 2;
		int idxMemo = 0;
		// 가로등 검사 0~N까지 다 있어야 함 하나라도 안 나오면 false
		// 근데 어떻게 검사?
		for (int i = 0; i < v.size(); i++) {
			int idxFront = v[i] - mid;
			int idxLast = v[i] + mid;
			if (idxFront < 0) idxFront = 0;
			if (idxMemo < idxFront) {
				possible = false; // 마지막으로 저장한 idx보다 현재 가로등의 맨 앞보다 더 작음
				break;
			}
			idxMemo = idxLast;
		}

		// 마지막에 N보다 작으면 false
		if (idxMemo < N) possible = false;
		// 값이 될 때
		if (possible) {
			Max = mid - 1;
			ans = mid;
		} // 안될 때
		else Min = mid + 1;
	}
	return ans;
}
int main() {
	input();
	cout << func() << "\n";
	return 0;
}