#include <iostream>
#include <vector>
#include <string>
using namespace std;
int T, N, mineCnt;
char mineCh[100], mineNum[100];
int arr[2] = { -1, 1};
int func();
void input() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		mineCnt = 0;
		for (int i = 0; i < N; i++) {
			cin >> mineNum[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> mineCh[i];
		}

		for (int i = 0; i < N; i++) {
			if (mineCh[i] == '*') {
				mineCh[i] = '#';
				mineNum[i]--;
				mineCnt++;

				for (int j = 0; j < 2; j++) {
					int idx = i + arr[j];
					if (idx < 0 || idx >= N) continue;
					mineNum[idx]--;
				}
			}
		}
		cout << func() << "\n";
	}
}

int func() {
	// 주위에 1이상이면 내가 지뢰다.
	for (int i = 0; i < N; i++) {
		if (mineNum[i] > '0') {
			bool b= true;

			for (int j = 0; j < 2; j++) {
				int idx = i + arr[j];
				if (idx < 0 || idx >= N) continue;
				if (mineNum[idx] <= '0') b = false;
			}

			if (b) {
				for (int j = 0; j < 2; j++) {
					int idx = i + arr[j];
					if (idx < 0 || idx >= N) continue;
					mineNum[idx]--;
				}

				mineNum[i]--;
				mineCh[i] = '*';
				mineCnt++;
			}
		}
	}
	return mineCnt;
}

int main() {
	input();
	return 0;
}