#include <iostream>
#include <algorithm>
#define MAX 1000000000  
using namespace std;
int N, a, b, c;
int maxV, minV = MAX;
int DP[3][2] = {0,};

void func(int a, int b, int c) {
	int maxA = max(DP[0][0], DP[1][0]) + a;
	int maxB = max({DP[0][0], DP[1][0], DP[2][0]}) + b;
	int maxC = max(DP[1][0], DP[2][0]) + c;
	DP[0][0] = maxA;
	DP[1][0] = maxB;
	DP[2][0] = maxC;

	maxV = max({ maxA, maxB, maxC });
	int minA = min(DP[0][1], DP[1][1]) + a;
	int minB = min({DP[0][1], DP[1][1], DP[2][1]}) + b;
	int minC = min(DP[1][1], DP[2][1]) + c;
	DP[0][1] = minA;
	DP[1][1] = minB;
	DP[2][1] = minC;
	minV = min({ minA, minB, minC });
}

void input() {
	cin >> N;
	cin >> a >> b >> c;
	DP[0][0] = DP[0][1] = a;
	DP[1][0] = DP[1][1] = b;
	DP[2][0] = DP[2][1] = c;
	if (N == 1) {
		maxV = max({ DP[0][0],DP[1][0],DP[2][0] });
		minV = min({ DP[0][1],DP[1][1],DP[2][1] });
	}
	for (int i = 2; i <= N; i++) {
		cin >> a >> b >> c;
		func(a,b,c);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	cout << maxV << " " << minV << "\n";
	return 0;
}