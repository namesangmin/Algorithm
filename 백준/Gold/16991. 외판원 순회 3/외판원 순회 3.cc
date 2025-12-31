#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

#define INF 99999999
using namespace std;
int N, x, y;
double ans, dp[16][1 << 16];
vector<vector<pair<int, int>>>vv;

void input() {
	cin >> N;
	vv.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		vv[i].push_back({ x,y });
	}

}
double func(int stCity, int curCity, int bitVisit) {
	// 마지막에 가려던 좌표에서 뺴서 리턴
	if (bitVisit == (1 << N) - 1) {
		int curX = vv[curCity].front().first; int curY = vv[curCity].front().second;
		int lastX = vv[stCity].front().first; int lastY = vv[stCity].front().second;
		dp[curCity][bitVisit] = sqrt(pow(curX - lastX, 2) + pow(curY - lastY, 2));
		return dp[curCity][bitVisit];
	}
	if (dp[curCity][bitVisit] != 0) return dp[curCity][bitVisit];

	dp[curCity][bitVisit] = INF;
	for (int i = 0; i < N; i++) {
		// 방문한 도시는 다시 못 가
		if (bitVisit & (1 << i)) { continue; }
		int curX = vv[curCity].front().first; int curY = vv[curCity].front().second;
		int nextX = vv[i].front().first; int nextY = vv[i].front().second;
		int nextBit = bitVisit | (1 << i);
		dp[curCity][bitVisit] = min(dp[curCity][bitVisit], sqrt(pow(curX - nextX, 2) + pow(curY - nextY, 2)) + func(0, i, nextBit));
	}
	return dp[curCity][bitVisit];
}

int main() {
	input();
	ans = func(0,0,1);
	cout << fixed << ans << setprecision(9) << "\n";
	return 0;
}