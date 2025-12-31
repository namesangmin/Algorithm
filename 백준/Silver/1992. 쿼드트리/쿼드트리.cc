#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<char>>v;
int N;
void input() {
	cin >> N;
	v.resize(N + 1, vector<char>(N + 1));
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> v[r][c];
		}
	}
}

string func(int Size, int x, int y) {
	string result = "";
	if (Size == 1) {
		if (v[y][x] == '0') return "0";
		else return "1";
	}
	// 리턴을 string으로 리턴을 해. 그것을 concat을 해
	string lu =func(Size / 2, x, y);
	string ru = func(Size / 2, x + Size / 2, y);
	string ld = func(Size / 2, x, y + Size / 2);
	string rd = func(Size / 2, x + Size/2 , y + Size/2);
	// 결과값을 저장해서 리턴을 때려야 하는데?
	// 4개 결과값이 같나? 아니면 ()하고 서로 concat
	// 전체를 한 번에 나타내지 못할 때 1 or 0
	// 나눠서 출력을 해라
	if ((lu == "0" && ru == "0" && ld == "0" && rd == "0") ||
		(lu == "1" && ru == "1" && ld == "1" && rd == "1")) {
		result = lu;
	}
	else {
		result = "(" + lu + ru + ld + rd + ")";
	}	
	return result;
}
int main() {
	input();
	cout <<func(N, 1, 1) << "\n";
	return 0;
}