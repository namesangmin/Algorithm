#include <iostream>
#include <string>
using namespace std;

string m, ans;
int d;
long long x, y, tX, tY, tmD;

void input() {
	cin >> d >> m >> x >> y;
	tmD = 1LL << d;
}

void func(long long Size, long long cX, long long cY, string& cStr, int idx) {
	if (Size <= 1) {
		if (cStr == m) {
			tX = cX;
			tY = cY;
		}
		return;
	}

	cStr += m[idx];
	int nL = m[idx] - '0';

	switch (nL) {
	case 1:
		func(Size / 2, cX, cY, cStr, idx + 1);
		break;
	case 2:
		func(Size / 2, cX - Size / 2, cY, cStr, idx + 1);
		break;
	case 3:
		func(Size / 2, cX - Size / 2, cY - Size / 2, cStr, idx + 1);
		break;
	case 4:
		func(Size / 2, cX, cY - Size / 2, cStr, idx + 1);
		break;
	}	
}
bool moveXY() {
	tX += x;
	tY += y;
	if (tX <= 0 || tX > tmD || tY <= 0 || tY > tmD) return false;
	return true;
}
void moveTarget(long long Size, long long cX, long long cY, string& cStr, int idx, char ch) {
	if (Size <= 1) {
		if (cX == tX && cY == tY) {
			cStr += ch;
			ans = cStr;
		}
		return;
	}
	if (ch != '0') cStr += ch;

	// 마찬가지로 모두 다 탐색하면 시간 터짐
	// 좌표를 알고 있음
	if (cX - Size / 2 < tX && cY - Size / 2 < tY) {
		moveTarget(Size / 2, cX, cY, cStr, idx + 1, '1');
	}
	else if (cX - Size / 2 >= tX && cY - Size / 2 < tY) {
		moveTarget(Size / 2, cX - Size / 2, cY, cStr, idx + 1, '2');
	}
	else if (cX - Size / 2 >= tX && cY - Size / 2 >= tY) {
		moveTarget(Size / 2, cX - Size / 2, cY - Size / 2, cStr, idx + 1, '3');
	}
	else if (cX - Size / 2 < tX && cY - Size / 2 >= tY) {
		moveTarget(Size / 2, cX, cY - Size / 2, cStr, idx + 1, '4');
	}
}
int main() {
	input();
	
	// 1. 해당 위치의 좌표를 구하고
	string p1 = "";
	func(tmD, tmD, tmD, p1, 0);
	// 2. 이동 -> x, y
	if (moveXY()) {
		// 3. 다시 그 좌표를 찾음
		string p2 = "";
		moveTarget(tmD, tmD, tmD, p2, 0, '0');
		cout << ans << "\n";
	}
	else cout << "-1\n";
	return 0;
}