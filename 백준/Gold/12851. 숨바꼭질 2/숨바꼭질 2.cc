#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000001
using namespace std;

int N, K;
int Way, Time, MaxTime;
vector<int> timeList;
void func() {
	timeList.resize(MAX, MAX);
	queue<pair<int,int>> q;

	Time = -1;
	timeList[N] = 0;
	q.push({ N, 0 });
	int tmNode[3] = { 0, };
	bool isT = false;
	while (!q.empty()) {
		int cn = q.front().first;
		int cTime = q.front().second;
		tmNode[0] = cn - 1;
		tmNode[1] = cn + 1;
		tmNode[2] = 2 * cn;
		q.pop();
		// 정답 판별
		if (K == cn) {
			if (Time == -1) {
				Time = cTime;
				Way = 1;
			}
			else if(Time > cTime){
				Time = cTime;
				Way = 1;
			}
			else if (Time == cTime) {
				Way++;
			}
			isT = true;
		}

		for (int i = 0; i < 3; i++) {
			int nextN = tmNode[i];
			int nextT = cTime + 1;
			if (nextN < 0 || nextN > MAX) continue;
			if (isT && nextT > Time) continue;
			if (timeList[nextN] < nextT) continue;
			timeList[nextN] = nextT;
			q.push({ nextN, nextT });
		}
	}

	cout << Time << "\n" << Way << "\n";
}
int main() {
	cin >> N >> K;
	func();
	return 0;
}