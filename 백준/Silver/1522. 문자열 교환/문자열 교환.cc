#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
	string arr;
	cin >> arr;

	int arrSize = arr.size();
	int ans = 1001;
	int aCount = count(arr.begin(), arr.end(), 'a');
	arr.append(arr);
	// 그냥 두 번 돌려서 b가 최소인 개수를 구하면 되는 거 아닌가?
	for (int stIdx = 0; stIdx < arrSize; stIdx++) {
		int bCount = 0;

		for (int j = stIdx; j < stIdx + aCount; j++) {
			if (arr[j] == 'b') bCount++;
		}
		// 조사한 구간에 모두 a밖에 없음 -> 정답
		// 혹은 b만 있음
		if (bCount == 0) {
			ans = 0;
			break;
		}
		if (ans > bCount) ans = bCount;
	}
	cout << ans << "\n";
	return 0;
}