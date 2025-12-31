#include <iostream>
#include <string>
using namespace std;

// 애초에 처음부터 제대로 된 체스판을 넣고
// 그 체스판과 자른 체스판을 비교하면?
int N, M;
int maxX, maxY;
int Min = 999999;
char arr[51][51];
string wF[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string bF[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};
void input() {
	cin >> N >> M;
	maxX = M - 8;
	maxY = N - 8;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
}
void func() {
	int Min = 9999999;
	for (int i = 0; i <= maxY; i++) {
		for (int j = 0; j <= maxX; j++) {
			int wCount = 0;
			int bCount = 0;
			for (int k = 0; k < 8; k++) {
				for (int p = 0; p < 8; p++) {
					if (wF[k][p] != arr[k + i][p + j])wCount++;
					if (bF[k][p] != arr[k + i][p + j])bCount++;
				}
			}
			if (bCount > wCount) bCount = wCount;
			if (Min > bCount) Min = bCount;
		}
	}
	cout << Min << "\n";
}
int main() {
	input();
	func();
	return 0;
}