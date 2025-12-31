#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, C;
vector<int> house;
void input() {
	cin >> N >> C;	
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		house.push_back(temp);
	}
	sort(house.begin(), house.end());
}
bool Check(int d) {
	int inS = C - 1;
	int lastInstall = 0;
	// 첫 번째 집에 설치했다고 가정
	for (int i = 1; i < N; i++) {
		int dist = house[i] - house[lastInstall];
		if (dist >= d) {
			lastInstall = i;
			inS--;
		}
	}
	if (inS <= 0)return true;
	return false;
}
int func() {
	int ans = 0;
	int left = 1;
	int right = house[N - 1] - house[0];
	while (left <= right) {		
		int mid = (left + right) / 2;
		if (!Check(mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			ans = mid;
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