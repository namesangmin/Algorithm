#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int min = -1;

	for (int i = 0; i * 5 <= N; i++) {
		int a = N - i * 5;
		if (a % 3 == 0) {
			int j = a / 3;
			int total = i + j;
			if (min == -1 || total < min) {
				min = total;
			}
		}
	}

	cout << min << "\n";
	return 0;
}
