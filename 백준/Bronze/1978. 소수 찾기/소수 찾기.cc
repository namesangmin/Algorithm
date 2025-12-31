#include <iostream>

using namespace std;
int main() {
	int N;
	int input;
	int count = 0;
	int arr[4] = { 2,3,5,7 };
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		int result = 0;
		if (input == 1)
			continue;
		
		for (int j = 2; j <= input; j++) {
			if (input % j == 0) {
				result++;
			}
		}
		if (result == 1)
			count++;
		result = 0;

	}
	cout << count ;


	return 0;
}