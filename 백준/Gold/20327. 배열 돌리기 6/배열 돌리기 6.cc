#include <iostream>
#define MAX 130

using namespace std;
int N, R;
int map[MAX][MAX];
int temp[MAX][MAX];
int R_memory[1000][2];
struct RowCol {
	int row;
	int col;
};
RowCol arr[MAX * MAX];

void input() {
	cin >> N >> R;
	N = 1 << N;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> map[r][c];
		}
	}
	for (int i = 0; i < R; i++) {
		cin >> R_memory[i][0] >> R_memory[i][1];
	}
}
void copyMap(int copy[MAX][MAX], int original[MAX][MAX]) {
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			copy[r][c] = original[r][c];
}
void printMap() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++)
			cout << map[r][c] << " ";
		cout << '\n';
	}
}
void func_1(int l) {
	int er = 0;
	int ec = 0;
	for (int sr = 1; sr < N; sr += l) {
		for (int sc = 1; sc < N; sc += l) {
			er = sr + l - 1;
			ec = sc + l - 1;
			int i = 1;
			for (int r = sr; r <= er; r++, i++) {
				for (int c = sc; c <= ec; c++) {
					map[r][c] = temp[er + 1 - i][c];
				}
			}
		}
	}
}


void func_2(int l) {
	int er = 0;
	int ec = 0;
	for (int sr = 1; sr < N; sr += l) {
		for (int sc = 1; sc < N; sc += l) {
			er = sr + l - 1;
			ec = sc + l - 1;
			for (int r = sr; r <= er; r++) {
				int i = 1;
				for (int c = sc; c <= ec; c++, i++) {
					map[r][c] = temp[r][ec + 1 -i];
				}
			}
		}
	}
}

void func_3(int l) {
	int er = 0;
	int ec = 0;
	for (int sr = 1; sr < N; sr += l) {
		for (int sc = 1; sc < N; sc += l) {
			er = sr + l - 1;
			ec = sc + l - 1;
			for (int r = 0; r < l; r++) {
				for (int c = 0; c < l; c++) {
					map[sr + r][sc + c] = temp[er - c][sc + r];

				}
			}
		}
	}
}

void func_4(int l) {
	int er = 0;
	int ec = 0;
	for (int sr = 1; sr < N; sr += l) {
		for (int sc = 1; sc < N; sc += l) {
			er = sr + l - 1;
			ec = sc + l - 1;
			for (int r = 0; r < l; r++) {
				for (int c = 0; c < l; c++) {
					map[sr + r][sc + c] = temp[sr + c][ec - r];

				}
			}
		}
	}
}
void func_5(int l) {
	int size = N / l;
	for (int sr = 1; sr <= N; sr += l) {
		for (int sc = 1; sc <= N; sc += l) {
			int br = (sr - 1) / l;
			int bc = (sc - 1) / l;

			int nr = size - 1 - br;
			int nc = bc;

			int tr = nr * l + 1;
			int tc = nc * l + 1;

			for (int r = 0; r < l; r++) {
				for (int c = 0; c < l; c++) {
					map[tr + r][tc + c] = temp[sr + r][sc + c];
				}
			}
		}
	}
}

void func_6(int l) {
	int size = N / l;
	for (int sr = 1; sr <= N; sr += l) {
		for (int sc = 1; sc <= N; sc += l) {
			int br = (sr - 1) / l;
			int bc = (sc - 1) / l;

			int nr = br;
			int nc = size - 1 - bc;

			int tr = nr * l + 1;
			int tc = nc * l + 1;

			for (int r = 0; r < l; r++) {
				for (int c = 0; c < l; c++) {
					map[tr + r][tc + c] = temp[sr + r][sc + c];
				}
			}
		}
	}
}
void func_7(int l) {
	int size = N / l;
	for (int sr = 1; sr <= N; sr += l) {
		for (int sc = 1; sc <= N; sc += l) {
			int br = (sr - 1) / l;
			int bc = (sc - 1) / l;

			int nr = bc;
			int nc = size - 1 - br;

			int tr = nr * l + 1;
			int tc = nc * l + 1;

			for (int r = 0; r < l; r++) {
				for (int c = 0; c < l; c++) {
					map[tr + r][tc + c] = temp[sr + r][sc + c];
				}
			}
		}
	}
}
void func_8(int l) {
	int size = N / l;
	for (int sr = 1; sr <= N; sr += l) {
		for (int sc = 1; sc <= N; sc += l) {
			int br = (sr - 1) / l;
			int bc = (sc - 1) / l;

			int nr = size - 1 - bc;
			int nc = br;

			int tr = nr * l + 1;
			int tc = nc * l + 1;

			for (int r = 0; r < l; r++) {
				for (int c = 0; c < l; c++) {
					map[tr + r][tc + c] = temp[sr + r][sc + c];
				}
			}
		}
	}
}


void Func(int getArr[]) {
	int func = getArr[0];
	int l = getArr[1];
	l = 1 << l;
	copyMap(temp, map);
	// 복사한 배열을 l의 값에 따라 범위를 나
	switch (func) {
	case 1:
		func_1(l);
		break;
	case 2:
		func_2(l);
		break;
	case 3:
		func_3(l);
		break;
	case 4:
		func_4(l);
		break;
	case 5:
		func_5(l);
		break;
	case 6:
		func_6(l);
		break;
	case 7:
		func_7(l);
		break;
	case 8:
		func_8(l);
		break;
	default:
		break;
	}
}

void rotate() {
	for (int i = 0; i < R; i++) {
		Func(R_memory[i]);
	}
}

int main() {
	input();
	rotate();
	printMap();
	return 0;
}