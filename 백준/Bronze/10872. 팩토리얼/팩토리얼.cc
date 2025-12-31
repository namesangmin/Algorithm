#include <iostream>
using namespace std;

int main() {
	unsigned long long  N, B=1;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		B *= i;
	}
	cout << B;
}