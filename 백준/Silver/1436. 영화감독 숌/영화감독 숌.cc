#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int N;
	cin >> N;
	int ans = 0;
	int sixCnt = 0;
	int curNum = 666;
	int maxNum = 999;
	int lineSize = 3;
	while (true) {		
		// 검사 666이 붙어있는지
		int tempCnt = 0;
		int modNum, divNum = curNum;
		int prevIdx = -1;
		bool firstSix = false;
		for (int line = 0; line < lineSize; line++) {
			modNum = divNum % 10;
			divNum /= 10;
			if (tempCnt >= 3) break;
			// 현재 마지막 숫자가 6이고, 연속된 숫자이면 tempCnt를 하나 늘림
			// 16660 일 때, 6이 3개 연속되어 있지만 해당 로직에서 prevNum == modNum
			// 61616 -> 떨어져 있을 때
			// 이면은 잘못 계산됨
			if (modNum == 6) {
				tempCnt++;
			}
			else {
				tempCnt = 0;
			}
		}
		// 만약 연속된 6의 숫자가 3자리 이상일 때 sixCnt를 늘림
		if (tempCnt >= 3) sixCnt++;

		if (N == sixCnt) {
			ans = curNum;
			break;
		}

		curNum++;
		// lineSIze -> 3자리 4자리..
		if (maxNum == curNum) {
			maxNum = maxNum * 10 + 9;
			lineSize++;
		}
	}
	cout << ans << "\n";
	return 0;
}