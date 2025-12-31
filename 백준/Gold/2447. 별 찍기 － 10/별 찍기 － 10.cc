#include <iostream>

using namespace std;

void printStar(int x, int y, int size) {
	if (size == 1) {
		cout << "*";
		return;
	}

	int block = size / 3;
	if ((x / block) % 3 == 1 && (y / block) % 3 == 1) {
		cout << " ";
	}
	else {
		printStar(x, y, block);
	}
}
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printStar(i, j, N);
		}
		cout << "\n";
	}

	return 0;
}