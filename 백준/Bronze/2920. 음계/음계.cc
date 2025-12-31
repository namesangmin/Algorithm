#include <iostream>
#define SCALE 8
using namespace std;

int main() {

	int input[8] = { 0 };

	int a = 1;
	int temp = 8;

	for (int i = 0; i < SCALE; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < SCALE; i++) {
		if (input[i] == a) {
			a ++;
		}
		else if (input[i] == temp) {
			temp--;
		}
		else {
			break;
		}
	}

	// cout << a << "\n"<< temp << endl;
	if (temp == 1) {
		cout << "descending" << endl;
	}else if (a == 9) {
		cout << "ascending" << endl;
	}
	else {
		cout << "mixed" << endl;
	}


	return 0;
}