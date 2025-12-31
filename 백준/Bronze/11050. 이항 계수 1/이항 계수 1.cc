#include <iostream>

using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int result_a = 1;
	for (int i = 1; i <= b; i++) {
		result_a *= a;
		a--;
	}
	int result_b = 1;
	for (int i = 1; i <= b; i++) {
		result_b *= i;
	}
	cout << result_a / result_b << "\n";
	return 0;
}