#include <iostream>
#include <deque>

using namespace std;
int n;
void input() {
	cin >> n;
}

void func() {
	deque<char> d;
	int cnt = 0;
	int left = 2, right = 2;
	d.push_back('H');
	for (int i = 1; i < n; i++) {
		
		// 오른쪽 부터 2개 다 채움
		if (right > 0) {
			d.push_back('S');
			right--;
		}
		// 그 다음에 왼쪽
		else if (left > 0) {
			d.push_front('S');
			left--;
		}
		// 2개 다 채우면
		// H 하나 추가하고 추가한 왼쪽이나 오른쪽에 2로 초기화
		if (left == 0 && right == 0) {
			d.push_back('H');
			right = 2;
		}
	}
	// print
	for (int i = 0; i < n; i++) {
		char tmCh = d.front();
		d.pop_front();
		cout << tmCh;
	}
}
int main() {
	input();
	func();
}