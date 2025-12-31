#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int arr[501][501];
map<int, int> m;
int main() {
	int N, M, B;
	cin >> N >> M >> B;
	// min max 값을 구하고 시작해야 되나?
	int Min = 256, Max = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			Min = min(Min, arr[i][j]);
			Max = max(Max, arr[i][j]);
			m[arr[i][j]] = 0;
		}
	}
	for (int i = Min; i <= Max; i++) {
		int temp_block = 0;
		int temp_time = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				int get_time_block = i - arr[j][k];
				temp_block += get_time_block;
				// 설치
				if (get_time_block > 0) {
					temp_time += get_time_block * 1;
				}
				// 지우기
				else if (get_time_block < 0) {
					temp_time += (-get_time_block) * 2;
				}
			}
		}
		if (temp_block > B) {
			m[i] = 99999999;
		}
		else {
			m[i] = temp_time;
		}
	}
	int temp_h;
	int temp_time = 99999999;
	for (auto f = m.begin(); f != m.end(); f++) {
		if (f->second < temp_time) {
			temp_h = f->first;
			temp_time = f->second;
		}
		else if (f->second == temp_time) {
			if (f->first > temp_h) {
				temp_h = f->first;
			}
		}
	}
	cout << temp_time << " " << temp_h << "\n";
	return 0;
}