#include <iostream>

using namespace std;
int main(void) {
	int N, money;
	int input_arr[10] = { 0 };
	int count = 0;
	int value = 0;
	cin >> N >> money;
	for (int i = 0; i < N; i++) {
		cin >> input_arr[i];
	}
	for (int i = N-1; i >= 0; i--) {
		value = money / input_arr[i];
		if (value != 0) {
			money = money - value * input_arr[i];
			count += value;
		}
	}
	cout <<count << "\n";
	return 0;
}