#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int R, C, N;
struct info {
	char isBomb;
	int Time;
};
vector<vector<info>>v;
queue<int> memoTime;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
void input() {
	cin >> R >> C >> N;
	v.resize(R, vector<info>(C));

	// 초기 0초
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> v[r][c].isBomb;
			v[r][c].Time = 0;
		}
	}
	memoTime.push(0);
}

void boom(int tTime) {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (v[r][c].Time == tTime) {
				v[r][c].isBomb = '.';
				for (int i = 0; i < 4; i++) {
					if (r + dy[i] >= 0 && r + dy[i] < R && c + dx[i] >= 0 && c + dx[i] < C)
						v[r + dy[i]][c + dx[i]].isBomb = '.';
				}
			}
		}
	}
}
void install(int cTime) {
	memoTime.push(cTime);
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (v[r][c].isBomb == '.') {
				v[r][c].isBomb = 'O';
				v[r][c].Time = cTime;
			}
		}
	}
}
void print() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << v[r][c].isBomb;
		}
		cout << "\n";
	}
}
void func() {
	// (init)
	// (1) 0초 초기 -> 설치 
	// 
	// (func)
	// (2) 1초 아무것도 x 
	// (3) 2초 설치되어 있지 않은 공간에 폭탄 설치 // 모든 칸에 폭탄을 가지고 있음
	// (4) 3초 -> 3초 전에 설치된 폭탄 모두 폭발
	// [[3과 4를 반복]]
	for (int cTime = 1; cTime <= N; cTime++) {
		// 설치
		if (cTime % 2 == 0) install(cTime);
		// 터뜨리기
		if ((memoTime.front() + 3) == cTime) {
			int targetTime = memoTime.front(); memoTime.pop();
			boom(targetTime);
		}
	}
	// 출력
	print();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	func();
	return 0;
}