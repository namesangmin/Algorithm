#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;
int students[10001];
int money[10001];

int find(int getNUM) {
	if (getNUM == students[getNUM])
		return getNUM;
	else
		return students[getNUM] = find(students[getNUM]);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, k, v, w;
	int inputA[10000] = { -1 };
	//map<int, int>A;
	int A[100001];
	int idx = 0;
	int vmoney, wmoney;
	int vparent, wparent;
	int result = 0;
	cin >> N >> M >> k;

	//scanf("%d %d %d", &N, &M, &k);
	for (int i = 1; i <= N; i++) {
		cin >> inputA[i];
		//scanf("%d", &inputA[i]);
		students[i] = i;
		money[i] = inputA[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> v >> w;

		//scanf("%d %d", &v, &w);
			A[v] = v;
			A[w] = w;
		vparent = find(A[v]);
		wparent = find(A[w]);

		if (vparent == wparent) {
			continue;
		}

		money[v] = inputA[v];
		money[w] = inputA[w];
		vmoney = money[vparent];
		wmoney = money[wparent];

		if (vmoney != wmoney) {
			if (vmoney < wmoney) {
				students[wparent] = vparent;
			}
			else { //vmoney > wmoney
				students[vparent] = wparent;
			}
		}
		else {// vmoney == wmoney
			students[wparent] = vparent;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (i == students[i])
			result += money[i];
	}
	if (result > k) {
		cout << "Oh no\n";
		//printf("Oh no\n");
		return 0;
	}
	cout << result << "\n";
	//printf("%d\n", result);
	return 0;
}