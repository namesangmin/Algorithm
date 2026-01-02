#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1010101010
using namespace std;

vector<vector<pair<int,int>>> Path;
vector<int> Item, tmItem;
vector<int> dist;
int n, m, r, t; // n 지역 개수, m 수색범위, r 길의 개수, t 각 지역 아이템 수
int a, b, l; // a, b 지역 번호, l 길의 길이
void input() {
	cin >> n >> m >> r;
	Item.resize(n + 1, 0);
	Path.resize(n + 1);
	dist.resize(n + 1, MAX);
	// 각 지역 아이템 개수 입력
	for (int i = 1; i <= n; i++) {
		cin >> Item[i];
	}
	// 길 입력
	for (int i = 1; i <= r; i++) {
		cin >> a >> b >> l;
		Path[a].push_back({ b, l });
		Path[b].push_back({ a, l });
	}
}
int Check(int regionNum, int distSum) {
	if (distSum > m) return 0;

	int nSize = Path[regionNum].size();
	int distCal = tmItem[regionNum];
	// 중복 제거.. 만약 업데이트가 되었으면, 더하면 안됨
	tmItem[regionNum] = 0;
	for (int n = 0; n < nSize; n++) {
		int regionNext = Path[regionNum][n].first;
		int distNext = Path[regionNum][n].second;
		
		// 다음 지역 검사
		if (distSum + distNext < dist[regionNext]) {
			dist[regionNext] = distSum + distNext;
			distCal += Check(regionNext, dist[regionNext]);
		}
	}
	return distCal;
}
int func() {
	int ans = 0;
	// 각 지역 모두 검사
	for (int i = 1; i <= n; i++) {
		dist[i] = 0;
		tmItem = Item;
		ans = max(ans, Check(i, 0));
		dist.assign(n + 1, MAX);
	}
	return ans;
}
int main() {
	input();
	cout << func() << "\n";
	return 0;
}