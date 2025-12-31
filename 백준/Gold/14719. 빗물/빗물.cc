#include <iostream>


using namespace std;
bool arr[501][501];
int main() {
	int h, w;
	int input;
	int result = 0;
	cin >> h >> w;
	for (int i = 1; i <= w; i++) {
		cin >> input;
		for (int j = 1; j <= input; j++) {
			arr[i][j] = true;
		}
	}

	for (int j = 1; j <= h; j++) {
		int counter = 0;
		int area = 0;
		for (int i = 1; i <= w; i++) {
			if (arr[i][j]) {
				counter++;
			}
			else {
				if(counter != 0)
					area++;
			}

			if (counter == 2) {
				result += area;
				counter = 1;
				area = 0;
			}
		}
	}
	cout << result << "\n";

	return 0;
}