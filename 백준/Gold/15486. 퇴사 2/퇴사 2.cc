#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 날짜
vector<pair<int,int>> T_cost;
vector<pair<int, int>> v_p;
// top_down
int DP(int n) {
	int day = v_p[n].first;
	int cost = v_p[n].second;
	int isDayOK = n + day - 1;

	// 값이 저장되어 있으면 return 값
	if (n <= 0 )return false;
	if (T_cost[n].second != 0) return T_cost[n].second;
	// 0이하면 return false 
	// day + n
	if (isDayOK <= N) {
		// 없으면 더함. 
		if (T_cost[isDayOK].second == 0) {
			if (N < isDayOK+1)
				T_cost[n].second += (cost + T_cost[isDayOK].second);
			else
				T_cost[n].second += (cost + T_cost[isDayOK+1].second);
		}
		// 있으면 다음 위치를 더함
		else {
			if (N < isDayOK + 1)
				T_cost[n].second = cost ;
			else
				T_cost[n].second += (cost + T_cost[isDayOK + 1].second);
		}
	}
	else {
		T_cost[n].second += T_cost[n + 1].second;
	}
	//이전항과 비교 
	if (T_cost[n] < T_cost[n + 1])
		T_cost[n] = T_cost[n + 1];
	
	DP(--n);
	// N보다 크거나 0보다 작으면 담을 수 없음. return // -1은 본인 날짜 포함
	return T_cost[n].second; // 함수 끝에 반환 값 추가

}
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T, P;
	cin >> N;
	T_cost.resize(N + 2);
	v_p.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		v_p[i]={ T,P };
	}
	int a = DP(N);
	/*
	printf("\n");
	for (int i = 1; i <= N; i++) {
		cout << T_cost[i].first << " : " << T_cost[i].second << "\n";
	}
	printf("\n");
	//sort(T_cost.begin(), T_cost.end(),cmp);
	for (int i = 1; i <= N; i++) {
		cout << T_cost[i].first << " : " << T_cost[i].second << "\n";
	}*/

	cout << T_cost[1].second << "\n";
	return 0;
}