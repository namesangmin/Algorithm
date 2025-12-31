#include <iostream>
using namespace std;
int main() {
	int bye, hello, max = 0, temp = 0;
	for (int i = 0; i < 10; i++) {
		cin >> bye >> hello;
		temp += (hello - bye);
		if (temp > max)
			max = temp;
	}
	cout << max << "\n";
	return 0;
}