#include <iostream>
#include <string>

using namespace std;
string str;
int T, idx;
bool func(int Size, int startIdx, int lastIdx);
void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		str.clear();
		cin >> str;
		if (func(str.size(), 0, str.size() - 1)) cout << "YES\n";
		else cout << "NO\n";
	}
}

bool func(int Size, int startIdx, int lastIdx) {
	if (Size <= 1) return true;
	
	// 확인
	int cSize = Size / 2;
	int midIdx = (startIdx + lastIdx) / 2;
	for (int i = 1; i <= cSize; i++) {
		if (str[midIdx + i] == str[midIdx - i]) {
			return false;
		}
	}
	// 왼쪽 확인 
	bool isP = func(cSize, startIdx, lastIdx / 2 - 1);

	// 오른쪽 확인
	isP = func(cSize, midIdx + 1, lastIdx);
	return isP;
}
int main() {
	input();
}