#include <iostream>
#include <queue>
using namespace std;

int arr[101];		///반대로 저장  100에서 1로 가는 최단거리 구하기 문제
int N, M;
int vst[101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr[a] = b;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a] = b;
	}
	queue<int> q;
	q.push(1);
	vst[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (arr[x] != 0) {
			int xx = arr[x];
			vst[xx] = vst[x];
			q.push(xx);
		}
		else if (arr[x] != 0) {
			int xx = arr[x];
			vst[xx] = vst[x];
			q.push(xx);
		}
		else {
			for (int i = 1; i <= 6; i++) {
				int xx = x + i;
				if (xx > 0 && xx <= 100) {
					if (vst[xx] == 0 || vst[xx] > vst[x] + 1) {
						vst[xx] = vst[x] + 1;
						q.push(xx);
					}
				}
			}
		}
	}
	cout << vst[100];
	return 0;
}