#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> myP, cnt;
vector<bool> m, isP;
int N, Q, tmAns;
void func(int a, int b);
void input() {
	cin >> N >> Q;
	myP.resize(N + 1);
	m.resize(N + 1, 0);
	isP.resize(N + 1, 0);
	cnt.resize(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		myP[i] = i;
	}

	int a, b;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		func(a, b);
		cout << tmAns << "\n";
	}
}

int findP(int node) {
	if (node == myP[node]) return node;

	int tm = myP[node];

	myP[node] = findP(myP[node]);
	m[node] = m[tm] ^ m[node];
	
	return myP[node];
}

// 합치고 집합 비교 -> 다른 집합이어야 함
// 작은 쪽에 개수도 더함
void func(int a, int b) {
	int aP = findP(a);
	int bP = findP(b);

	if (aP > bP) swap(aP, bP);

	// 부모가 다르면 병합
	if (aP != bP) {
		if (isP[aP] && !isP[bP]) tmAns += cnt[bP];
		else if (!isP[aP] && isP[bP]) tmAns += cnt[aP];

		myP[bP] = myP[aP]; // 부모 작은 쪽으로
		cnt[aP] += cnt[bP]; // 작은 쪽으로 더함
		m[bP] = m[a] ^ m[b] ^ 1;
		isP[aP] = isP[aP] | isP[bP];
	}
	else { 
		// 부모가 같으면 비교
		if (m[a] == m[b] && !isP[aP]) {
			isP[aP] = true;
			tmAns += cnt[aP];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	return 0;
}