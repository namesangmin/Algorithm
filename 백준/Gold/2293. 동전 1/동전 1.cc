#include <iostream>
#include <vector>
using namespace std;
int n, k, ans;
vector<int> List;
vector<int> dp;
void input() {
	cin >> n >> k;
	dp.resize(k+1);

	int tm;
	for (int i = 0; i < n; i++) {
		cin >> tm;
		List.push_back(tm);
	}
}

void func(int num) {
	
	if (num < 0)return;
	if (num == 0) {
		ans++;
		return;
	}
	// 각 동전 종류마다 사용한 개수를 저장해야 함
	for (int i = 0; i < n; i++) {
		func(num - List[i]);
	}
}

int main() {
	input();
	//func(k);
	// List[i] 개수
	// List[i]~ List[i+1] 개수
	// List[i]~List[i+2]... 개수
	// List[i+1] ~ List[i+1]// 개수
	// List[i+1] ~ List[i+2]// 개수
	// List[i+2] ~~ List[i+2]// 개수
	int listSize = List.size();
	// 1. 동전 종류를 하나씩 꺼낸다
	dp[0] = 1; // 아무것도 안 냄.
	for (int i = 0; i < n; i++) {

		// 2. 현재 동전(List[i])을 사용해서 만들 수 있는 금액(j)을 갱신한다
		// j는 금액이므로 동전 값부터 목표 금액 k까지 돈다.
		for (int j = List[i]; j <= k; j++) {
			// 여기에 점화식이 들어감
			// 의미: "j원을 만드는 방법" += "j - 현재동전값"을 만드는 방법
			dp[j] = dp[j - List[i]] + dp[j];
		
		}
	}
	cout << dp[k] << "\n";
	return 0;
}