#include <iostream>

using namespace std;
int X, ans;

void func() {
	while (X > 0) {
		if(X & 1) ans++;
		X >>= 1;
	}
}
int main() {
	cin >> X;
	func();
	cout << ans << "\n";
	return 0;
}