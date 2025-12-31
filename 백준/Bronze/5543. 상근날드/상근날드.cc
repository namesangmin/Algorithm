#include <iostream>

using namespace std;
int main() {

	int arr[5];
	int temp1=-1;
	int temp2 = -1;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	temp1 = arr[0];
	for (int i = 0; i < 3; i++) {
		if (temp1 > arr[i])
			temp1 = arr[i];
	}

	temp2 = arr[3];
	for (int i = 0; i < 2; i++) {
		if (temp2 > arr[i + 3])
			temp2 = arr[i + 3];
	}
	cout << temp1 + temp2 - 50 << "\n";





	return 0;
}