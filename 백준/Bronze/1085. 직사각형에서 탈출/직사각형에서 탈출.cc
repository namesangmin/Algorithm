#include <iostream>

using namespace std;
int main() {
	int x, y, z, w;
	int temp;

	cin >> x >> y >> z >> w;

	int arr[4] = { z-x, w-y,x - 0,y - 0 };
	temp = arr[0];

	for (int i = 0; i < 4; i++) {
		//cout << "arr"<<i<< arr[i] << "\n";
		if (temp > arr[i])
			temp = arr[i];
	}
	cout << temp << "\n";
	return 0;
}