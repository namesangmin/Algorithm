#include <iostream>
using namespace std;
int main() {
	int input;
	int A, B;
	cin >> input;
	for (int i = 0; i < input; i++) {
		cin >> A >> B;
		cout << A + B << endl;
	}

	return 0;
}