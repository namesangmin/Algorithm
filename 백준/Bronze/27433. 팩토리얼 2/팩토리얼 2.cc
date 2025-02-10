#include <iostream>

using namespace std;

unsigned long long int f(int n) {
	unsigned long long int result = 1;
	for (int i = 0; i < n; i++) {
		result *= (i + 1);
	}

	return result;
}

int main() {
	int N;
	cin >> N;
	unsigned long long int result = f(N);
	cout << result << "\n";
	return 0;
}