#include <iostream>
#define MAX 101

using namespace std;
int N, M, R;
int map[MAX][MAX];
int temp[MAX][MAX];
int R_memory[1000];

void input() {
	cin >> N >> M >> R;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> map[r][c];
		}
	}
	for (int i = 0; i < R; i++) {
		cin >> R_memory[i];
	}
}
void copyMap(int copy[MAX][MAX], int original[MAX][MAX]) {
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++)
			copy[r][c] = original[r][c];
}
void printMap() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++)
			cout << map[r][c] << " ";
		cout << '\n';
	}
}

void func_1() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			map[r][c] = temp[N + 1 - r][c];
		}
	}
}

void func_2() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			map[r][c] = temp[r][M + 1 - c];
		}
	}
}

void func_3() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			map[c][N-r+1] = temp[r][c];
		}
	}
	int ch = M;
	M = N;
	N = ch;
}

void func_4() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			map[M + 1 - c][r] = temp[r][c];
		}
	}
	int ch = M;
	M = N;
	N = ch;
}

void func_5() {
	int sr = 1, sc = 1;
	int er= N / 2, ec= M / 2;
	
	for (int r = sr; r <= er; r++) {
		for (int c = sc; c <= ec; c++) {
			map[r][c + ec] = temp[r][c];
		}
	}

	sc += ec;
	for (int r = sr; r <= er; r++) {
		for (int c = sc; c <= M; c++) {
			map[r + er][c] = temp[r][c];
		}
	}

	sr += er;
	for (int r = sr; r <= N; r++) {
		for (int c = sc; c <= M; c++) {
			map[r][c-M/2] = temp[r][c];
		}
	}

	sc -= ec;
	for (int r = sr; r <= N; r++) {
		for (int c = sc; c <= ec; c++) {
			map[r-N/2][c] = temp[r][c];
		}
	}
}

void func_6() {
	int sr = 1, sc = 1;
	int er = N / 2, ec = M / 2;

	for (int r = sr; r <= er; r++) {
		for (int c = sc; c <= ec; c++) {
			map[r + er][c] = temp[r][c];
		}
	}

	sr += er;
	for (int r = sr; r <= N; r++) {
		for (int c = sc; c <= ec; c++) {
			map[r][c+ec] = temp[r][c];
		}
	}

	sc += ec;
	for (int r = sr; r <= N; r++) {
		for (int c = sc; c <= M; c++) {
			map[r - N/2][c] = temp[r][c];
		}
	}
	sr -= er;
	for (int r = sr; r <= er; r++) {
		for (int c = sc; c <= M; c++) {
			map[r][c - M/2] = temp[r][c];
		}
	}
}

void func(int func) {
	copyMap(temp, map);
	switch (func)
	{
	case 1:
		func_1();
		break;
	case 2:
		func_2();
		break;
	case 3:
		func_3();
		break;
	case 4:
		func_4();
		break;
	case 5:
		func_5();
		break;
	case 6:
		func_6();
		break;
	default:
		break;
	}
}

void rotate() {
	for (int i = 0; i < R; i++) {
		func(R_memory[i]);
	}
}

int main() {
	input();
	rotate();
	printMap();
	return 0;
}