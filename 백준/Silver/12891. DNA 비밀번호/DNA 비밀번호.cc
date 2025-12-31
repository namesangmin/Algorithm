#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<char> arr;
vector<pair<char, int>> checkVal = { {'A',0}, {'C',0}, {'G',0}, {'T',0} };
map<char, int> m;
int N, M;

void input() {
	cin >> N >> M;
	char tm;
	for (int i = 0; i < N; i++) {
		cin >> tm;
		arr.push_back(tm);
		if (i < M) m[tm]++;
	}
	int tm2;
	for (int i = 0; i < 4; i++) {
		cin >> tm2;
		checkVal[i].second += tm2;
	}
}
bool check() {
	bool isP = true;
	for (int i = 0; i < 4; i++) {
		char cVal = checkVal[i].first;
		int cnt = checkVal[i].second;

		if (cnt == 0) continue;
		if (m.find(cVal) != m.end()) { // 값을 찾고 있으면 커야 함
			if (m[cVal] < checkVal[i].second) isP = false;
		} // 만약에 값이 없는데 cnt가 더 높아
		else isP = false;
	}
	return isP;
}
int func() {
	int ans = 0;
	int maxIdx = N - M;
	for (int i = 0; i <= maxIdx; i++) {
		if (check())ans++;

		// 현재 있는 값 하나 빼고 다음 거 넣기
		if (i != maxIdx) {
			m[arr[i]]--;
			m[arr[M + i]]++;
		}
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