#include <iostream>
using namespace std;
int main() {
	int A, B;
	int mod = 0;
	cin >> A >> B;
	if (A < B) {
		int a = A;
		A = B;
		B = a;
	}
	mod = B;
	int mod_a = A;
	while (mod_a % mod != 0) {
		int temp = mod;
		mod = mod_a % mod;
		mod_a = temp;
		//cout << mod_a <<" " << mod << "\n";
	}
	A /= mod;
	B /= mod;
	cout << mod << "\n";
	cout << mod * A * B << "\n";
	return 0;
}