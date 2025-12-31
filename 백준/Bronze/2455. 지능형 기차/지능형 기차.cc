#include <iostream>


using namespace std;

int main() {
	int input;
	int output;
	int result=0;
	int station[4] = { -1 };
	int temp;

	for (int i = 0; i < 4; i++) {
		cin >> output >> input ;
		result = input - output + result;
		station[i] = result;
	}

	for (int i = 0; i < 3; i++) {
		temp = station[i];
		for (int j = 1; j < 4; j++) {
			if (temp < station[j])
				temp = station[j];
		}
	}

	cout << temp << endl;

	return 0;
}