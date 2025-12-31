#include <iostream>
#define NUMBER 9
using namespace std;
int main() {
	int input;
	int temp = 0;
	int result_number = 0;
	for (int i = 0; i < NUMBER; i++) {
		cin >> input;

		if (temp < input) {
			temp = input;
			result_number = i+1;
		}
	}
	cout << temp << "\n" << result_number << endl;

	return 0;
}