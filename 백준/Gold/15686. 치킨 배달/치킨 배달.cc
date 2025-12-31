#include <iostream>
#include <vector>
#include <cmath>
#define MAX 9999
using namespace std;

vector<pair<int, int>> chicken;
vector<bool> chickenChoose;
vector<pair<int, int>> house;
vector<int> values;
int N, M, ans = MAX;
void input() {
	int temp;
	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> temp;
			if (temp == 1) {
				house.push_back({ r,c });
				values.push_back(MAX);
			}
			else if (temp == 2) {
				chicken.push_back({ r,c });
				chickenChoose.push_back(false);
			}
		}
	}
}
void calValues(int mNum) {
	for (int i = 0; i < house.size(); i++) {
		int dis = abs(chicken[mNum].first - house[i].first) + abs(chicken[mNum].second - house[i].second);
		if (values[i] > dis)
			values[i] = dis;
	}
}
// 치킨 집
void func(int idx, int chickCount) {
	// 치킨 집 개수 조건
	if (chickCount == M) {
		int tempAns = 0;
		for (int i = 0; i < house.size(); i++) {
			tempAns += values[i];
		}
		if (tempAns < ans)
			ans = tempAns;

		return;
	}

	// 치킨 집 선택
	for (int c = idx; c < chicken.size(); c++) {
		if (!chickenChoose[c]) { // 선택 안한 치킨집을 선택
			chickenChoose[c] = true;
			vector<int> backUp = values;
			calValues(c);
			func(c + 1, chickCount + 1);
			chickenChoose[c] = false;
			values = backUp;
		}
	}
}
int main() {
	input();
	func(0, 0);
	cout << ans << "\n";
	return 0;
}